#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}
std::string RobotomyRequestForm::get_target() const
{
    return this->target;
}  

void    RobotomyRequestForm::action() const
{
    std::cout << "* VRRRRRRRR! BZZZZZZZT! *" << std::endl;
    std::cout << "Wait... drilling noises are coming from the lab..." << std::endl;

    if (std::rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << " The robotomy on" << this->target << "failed. Still human, unfortunately" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}