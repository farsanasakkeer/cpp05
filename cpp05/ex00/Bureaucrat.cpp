/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:55:20 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/05/19 14:11:12 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("default"),_grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
	std::cout << YELLOW << "Grade: " << this->_grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name)
{
	std::cout << GREEN << "Bureaucrat " << this->_name  << " named constructor called" << RESET << std::endl;
	std::cout <<YELLOW << "Name  : " << this->_name << RESET << std::endl;
	std::cout << YELLOW << "Grade : " << grade << RESET << std::endl;
	try 
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREEN << "Bureaucrat destructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):_name(copy._name),_grade(copy._grade)
{
	std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat overload)
{
	std::cout << GREEN << "Bureaucrat = operator called" << RESET << std::endl;
	overload.swap(*this);
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high" RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low" RESET);
}

void Bureaucrat::swap(Bureaucrat &copy)
{
	std::swap(this->_grade, copy._grade);
}



/*Using swap can help in achieving strong exception safety guarantees. 
By first swapping resources, if an exception occurs during the operation, 
the original state of the object remains unchanged, 
ensuring no resources are leaked or left in an inconsistent state.*/