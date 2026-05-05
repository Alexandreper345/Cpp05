#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class RobotomyRequestForm : public AForm
{
private:
    std::string target;    
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    std::string get_target() const;
    virtual void    action() const;
    ~RobotomyRequestForm();
};

#endif