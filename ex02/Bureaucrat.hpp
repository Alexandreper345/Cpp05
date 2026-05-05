#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int	grade;

public:

	std::string getname() const;
	int getgrade() const;
	void	increment(void);
	void	decrement(void);
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	void executeForm(AForm const & form);
	void signForm(AForm &form);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException() {}
			virtual const char* what() const throw(){
				return "Grade too high!";
			}
			virtual ~GradeTooHighException() throw() {}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException() {}
			const char* what() const throw(){
				return "Grade too low!";
			}
			virtual ~GradeTooLowException() throw() {}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif