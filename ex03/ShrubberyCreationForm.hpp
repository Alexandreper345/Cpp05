#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
public:

    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    std::string get_target() const;
    virtual void    action() const;
    ~ShrubberyCreationForm( );
};

#endif
