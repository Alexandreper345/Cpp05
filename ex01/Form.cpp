#include "Form.hpp"

Form::Form(std::string name, bool is_assign, int grade_sign, int grade_execut) : 
		name(name), is_assign(false), grade_sign(grade_sign), grade_execut(grade_execut)
{
	if (grade_sign <= 1 || grade_execut <= 1)
		throw Form::GradeTooHighException();
	if (grade_sign >= 150 || grade_execut >= 150)
		throw Form::GradeTooLowException();
	this->grade_sign = grade_sign;
	this->grade_execut = grade_execut;

}

std::string get_name() const
{
	return this->name;
}

bool get_is_assign() const 
{
	return this->is_assign;
}

int	get_grade_sign() const 
{
	return this->grade_sign;
}

int	get_grade_execut() const 
{
	return this->grade_execut;
}

void beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getgrade() <= get_grade_sign())
		throw Form::GradeTooLowException();
	is_assign = true; 	
}

Form::~Form(){}