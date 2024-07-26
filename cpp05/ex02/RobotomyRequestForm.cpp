/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:15:03 by farsana           #+#    #+#             */
/*   Updated: 2024/07/26 15:43:50 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest Form", 72, 45, "default")
{
	std::cout << "RobotomyRequest Form default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequest Form", 72, 45, target)
{
	std::cout << "RobotomyRequest Form named constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
	std::cout << "RobotomyRequest Form copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequest Form Destructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &overload) 
{
	std::cout << "RobotomyRequest Form Operator Overload Called" << std::endl;
	if (this != &overload) 
    {
        AForm::operator=(overload);
    }
	return(*this);
}

void RobotomyRequestForm::formAction() const
{
    std::srand(std::time(0)); // Seed the random number generator with the current time
    int successRate = std::rand() % 2; // Generate a random number (0 or 1)

    std::cout << BLUE << "Drilling noises............" << RESET << std::endl;

	if (successRate == 1)
	{
		std::cout << BLUE << getTarget() << " has been robotomized successfully!" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "Robotomy failed for " << getTarget() << "." << RESET << std::endl;
	}
}