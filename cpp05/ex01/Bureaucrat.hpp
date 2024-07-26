/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:55:45 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/07/23 20:51:19 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define PURPLE			"\033[35m"

#include <iostream>
#include "Form.hpp"

class Form; // Forward declaration to resolve circular dependency

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		virtual ~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat overload);

		const std::string getName() const;
		int getGrade() const;

		void incGrade();
		void decGrade();

		void signForm(Form &form);		

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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &in);

#endif


/*Without the virtual keyword, 
if you delete an object through a base class pointer and the base class destructor 
is not virtual, then only the base class destructor will be called. 
This can lead to memory leaks and undefined behavior if the derived class 
has resources that need to be properly deallocated.

So, by declaring the destructor virtual in the base class, 
you ensure that when you delete an object through a pointer to the base class, 
the appropriate destructor (the one corresponding to the derived class) is called,
 allowing for proper cleanup of resources.
*/