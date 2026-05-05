#include "Intern.hpp"

Intern::Intern(/* args */)
{
}


AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    AForm *form = (formName == "shrubbery creation") ? static_cast<AForm *>(new ShrubberyCreationForm(target)) :
                    (formName == "robotomy request") ? static_cast<AForm *>(new RobotomyRequestForm(target)) :
                    (formName == "presidential pardon") ? static_cast<AForm *>(new PresidentialPardonForm(target)) :
                    NULL;
    
    if (form == NULL)
    {
        std::cerr << "Intern cannot create form: " << formName << " because it is unknown." << std::endl;
        return NULL;
    }
    else
    {
        std::cout << "Intern creates " << formName << std::endl;
        return form;
    }
}

Intern::~Intern()
{
}