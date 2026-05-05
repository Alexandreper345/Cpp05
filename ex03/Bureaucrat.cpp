#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade){ }
void Bureaucrat::increment()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout << this->name << " executes " << form.get_name() << std::endl;
	} catch (std::exception &e) {
		std::cerr << this->name << " cannot execute " << form.get_name() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->name << " signs " << form.get_name() << std::endl;
	} catch (std::exception &e) {
		std::cerr << this->name << " cannot sign " << form.get_name() << " because " << e.what() << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

void Bureaucrat::decrement()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getname() << ", bureaucrat grade " << bureaucrat.getgrade() << ".";
	return out;
}

std::string Bureaucrat::getname() const
{
	return this->name;
}

int	Bureaucrat::getgrade() const
{
	return this->grade;
}

Bureaucrat::~Bureaucrat(){}
