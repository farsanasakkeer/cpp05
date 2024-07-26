/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:32:29 by farsana           #+#    #+#             */
/*   Updated: 2024/07/25 18:32:20 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

// class Bureaucrat;
class Bureaucrat; // Forward declaration

class AForm {

	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
		const std::string _target;
	
	public:
		AForm();
		AForm(const std::string name, int req_sign_grade, int req_exec_grade,const std::string target);
		AForm(const AForm &copy);
		virtual ~AForm();

        AForm &operator=(const AForm &overload);

        void beSigned(const Bureaucrat &sign);

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
		//-------------------//
		const std::string getTarget() const;

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};		

		virtual void formAction() const = 0;
		void execute(const Bureaucrat &executor) const;


};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif
