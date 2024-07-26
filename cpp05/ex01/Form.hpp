#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

// class Bureaucrat;
class Bureaucrat; // Forward declaration

class Form {

	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
	
	public:
		Form();
		Form(const std::string name, int req_sign_grade, int req_exec_grade);
		Form(const Form &copy);
		virtual ~Form();

        Form &operator=(const Form &overload);

        void beSigned(const Bureaucrat &sign);
		// void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		const std::string getName() const;
		bool getsign() const;
		int getSignGrade() const;
		int getExecGrade() const;

};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
