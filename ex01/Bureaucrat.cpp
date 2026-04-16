#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getname() << " signed " << form.get_name() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getname() << " couldn’t sign " << form.get_name() << " because " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(){}
