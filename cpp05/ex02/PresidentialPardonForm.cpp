/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 01:34:41 by farsana           #+#    #+#             */
/*   Updated: 2024/07/26 01:36:47 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5, "default")
{
	std::cout << "Presidential Pardon Form Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("Presidential Pardon Form", 25, 5, target)
{
	std::cout << "Presidential Pardon Form named constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy)
{
	std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm overload)
{
	std::cout << "Presidential Pardon Form operator overload called" << std::endl;
	if (this != &overload) 
    {
        AForm::operator=(overload);
    }
	return(*this);
}

void PresidentialPardonForm::formAction() const
{
	std::cout << BLUE << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl; 
}