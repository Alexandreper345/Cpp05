#include "Form.hpp"

Form::Form(std::string name, int grade_sign, int grade_execut) : 
    name(name), is_assign(false), grade_sign(grade_sign), grade_execut(grade_execut)
{
    if (grade_sign < 1 || grade_execut < 1)
        throw Form::GradeTooHighException();
    if (grade_sign > 150 || grade_execut > 150)
        throw Form::GradeTooLowException();
}



Form::Form(const Form &other) : 
    name(other.name), 
    is_assign(other.is_assign), 
    grade_sign(other.grade_sign), 
    grade_execut(other.grade_execut) 
{}

Form &Form::operator=(const Form &other)
{
    if (this != &other) {
        this->is_assign = other.is_assign;
    }
    return *this;
}

std::string Form::get_name() const
{
	return this->name;
}

bool Form::get_is_assign() const 
{
	return this->is_assign;
}

int	Form::get_grade_sign() const 
{
	return this->grade_sign;
}

int	Form::get_grade_execut() const 
{
	return this->grade_execut;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getgrade() > get_grade_sign())
		throw Form::GradeTooLowException();
	this->is_assign = true; 	
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form: " << form.get_name() 
        << " | Signed: " << (form.get_is_assign() ? "Yes" : "No")
        << " | Grade to Sign: " << form.get_grade_sign()
        << " | Grade to Exec: " << form.get_grade_execut();
    return out;
}
Form::~Form(){}