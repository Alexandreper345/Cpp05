#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    std::string const name;
    bool    is_assign;
    const int   grade_sign;
    const int   grade_execut;

public:
	AForm();
    AForm(std::string name, int grade_sign, int grade_execut);
    AForm(const AForm &other);
    virtual ~AForm();

    std::string get_name() const;
    bool get_is_assign() const;
    int get_grade_sign() const;
    int get_grade_execut() const;
    AForm &operator=(const AForm &other);

    void    beSigned(Bureaucrat const &bureaucrat);
    void    execute(Bureaucrat const &executor) const;
    virtual void action() const = 0;

    class  FormNotSignedException: public std::exception
	{
		public:
			FormNotSignedException() {}
			const char* what() const throw() {
				return "Form is not signed";
			}
			virtual ~FormNotSignedException() throw() {}
	};
	
	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException() {}
			virtual const char* what() const throw() {
				return "Grade too high!";
			}
			virtual ~GradeTooHighException() throw(){}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException() {}
			const char* what() const throw() {
				return "Grade too low";
			}
			virtual ~GradeTooLowException() throw() {}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif