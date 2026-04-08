#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Form
{
private:
	std::string const name;
	bool is_assign;
	const int	grade_sign;
	const int	grade_execut;
public:
	std::string get_name() const;
	bool get_is_assign() const;
	int	get_grade_sign() const;
	int	get_grade_execut() const;
	Form(const Form &other);
	void beSigned(Bureaucrat const &bureaucrat);
	Form(std::string name, bool is_assign, int grade_sign, int grade_execut);
	~Form();

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

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif