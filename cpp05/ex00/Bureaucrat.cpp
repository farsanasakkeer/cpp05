/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:55:20 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/07/23 22:49:08 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("default"),_grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name)
{
	std::cout << GREEN << "Bureaucrat " << this->_name  << " named constructor called" << RESET << std::endl;
	
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	
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
	if (this != &overload) {
        // We cannot assign to 'name' because it's a constant
        this->_grade = overload._grade;
    }
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

const std::string Bureaucrat::getName() const
{
	return(this->_name);
}
		
int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void Bureaucrat::incGrade()
{
	if (this->_grade - 1 < 1)
		throw(GradeTooHighException());
	else
		this->_grade--;
}

void Bureaucrat::decGrade()
{
	if (this->_grade + 1 > 150)
		throw(GradeTooLowException());
	else
		this->_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &in)
{
	out << YELLOW << "Bureaucrat  name: \"" << in.getName() << "\", Bureaucrat grade: " << in.getGrade()  << RESET;
	return out;
}