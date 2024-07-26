/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:03:55 by farsana           #+#    #+#             */
/*   Updated: 2024/07/26 16:47:19 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = copy;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}
// Intern &Intern::operator=(Intern overload)
Intern &Intern::operator=(Intern overload) 
{
    std::cout << "Intern assignment operator called" << std::endl;
    (void)overload;
    return *this;// This line returns a reference to the current object. This is essential for chaining assignments (e.g., a = b = c;).
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    static const std::string formNames[] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};

	for(int i=0; i<3; i++)
	{
		if(name == formNames[i])
		{
			std::cout << "Intern creates a " << GREEN << formNames[i] << " Form" << RESET << std::endl;
			switch (i)
			{
				case 0:
					return new PresidentialPardonForm(name, target);
				case 1:
					return new RobotomyRequestForm(name, target);
				case 2:
					return new ShrubberyCreationForm(name, target);
			}
		}
	}
	std::cerr << RED << "Intern failed to create a " << name << " form." << RESET << std::endl;
	return NULL;
}