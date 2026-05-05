#include "AForm.hpp"

AForm::AForm() : name("Default"), is_assign(false), grade_sign(150), grade_execut(150) {}

AForm::AForm(std::string name, int grade_sign, int grade_execut) : 
    name(name), is_assign(false), grade_sign(grade_sign), grade_execut(grade_execut)
{
    if (grade_sign < 1 || grade_execut < 1)
        throw AForm::GradeTooHighException();
    if (grade_sign > 150 || grade_execut > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : 
    name(other.name),
    is_assign(other.is_assign),
    grade_sign(other.grade_sign),
    grade_execut(grade_execut)
{}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->is_assign = other.is_assign;
    }
    return *this;
}

std::string AForm::get_name() const
{
    return this->name;
}

bool AForm::get_is_assign() const
{
    return this->is_assign;
}

int AForm::get_grade_sign() const
{
    return this->grade_sign;
}

int AForm::get_grade_execut() const
{
    return this->grade_execut;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getgrade() > get_grade_sign())
        throw AForm::GradeTooLowException();
    this->is_assign = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form: " << form.get_name() 
        << " | Signed: " << (form.get_is_assign() ? "Yes" : "No")
        << " | Grade to Sign: " << form.get_grade_sign()
        << " | Grade to Exec: " << form.get_grade_execut();
    return out;
}

void    AForm::execute(Bureaucrat const &executor) const
{
    if (!this->is_assign)
        throw FormNotSignedException();
    if (executor.getgrade() > this->grade_execut)
        throw GradeTooLowException();
    
    this->action();
}

AForm::~AForm() {}