/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:53:49 by farsana           #+#    #+#             */
/*   Updated: 2024/07/26 20:42:08 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137, "default")
{
	std::cout << "Shrubbery Creation Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const std::string target) : AForm(name, 145, 137, target)
{
	std::cout << "Shrubbery Creation Form named constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form Destructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &overload) 
{
	std::cout << "Shrubbery Creation Form Operator Overload Called" << std::endl;
	if (this != &overload) 
    {
        AForm::operator=(overload); // Call the base class assignment operator
        // Calls the base class assignment operator to handle assignment of base class members.
    }
	return(*this);
}

/*This line explicitly calls the assignment operator of the base class AForm. This is necessary
 because the derived class (ShrubberyCreationForm in this case) 
 may have inherited members from the base class that need to be properly copied or assigned.*/

void ShrubberyCreationForm::formAction() const
{
    std::ofstream outputFile;
    // std::ofstream outputFile;
	outputFile.open((this->getTarget() + "_shrubbery").c_str());
    if (!outputFile)
	{
		std::cerr << RED << "Error: Unable to open file for writing." << RESET << std::endl;
	}

    outputFile << "       _-_       " << std::endl;
    outputFile << "    /~~   ~~\\    " << std::endl;
    outputFile << " /~~         ~~\\ " << std::endl;
    outputFile << "{               }" << std::endl;
    outputFile << " \\  _-     -_  / " << std::endl;
    outputFile << "   ~  \\ //  ~   " << std::endl;
    outputFile << "_- -   | | _- _  " << std::endl;
    outputFile << "  _ -  | |   -_  " << std::endl;
    outputFile << "      // \\       " << std::endl;

    outputFile.close();
}

