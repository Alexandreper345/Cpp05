#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{}

std::string PresidentialPardonForm::get_target() const
{
    return this->target;
}

void    PresidentialPardonForm::action() const
{
    std::cout << this->target
        << " has been pardoned by Zaphod Beeblebrox."
        << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm()
{
}