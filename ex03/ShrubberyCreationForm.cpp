#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm.hpp", 145, 137), target("defualt") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm.hpp", 145, 137), target(target) {}

void ShrubberyCreationForm::action() const
{
    std::ofstream file(this->target + "_shrubbery");
    
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }

    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    file.close();
    std::cout << "Shrubbery created successfully in " << this->target + "_shrubbery" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( )
{}