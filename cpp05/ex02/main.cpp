/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:55:32 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/07/26 20:46:14 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

	try {
			
		Bureaucrat b("b", 5);
		std::cout << b << std::endl;
		std::cout << GREEN << std::endl << "--- Srubbery Creation Form ---" << RESET << std::endl;
		ShrubberyCreationForm scf("scf"); // sign: 145, exec: 137
		std::cout << GREEN << scf << RESET << std::endl;
		b.executeForm(scf);
		b.signForm(scf);
		std::cout << GREEN << scf << RESET << std::endl;
		b.executeForm(scf);

		std::cout << GREEN << std::endl << "\n--- RobotomyRequestForm Creation Form ---" << RESET << std::endl;
		RobotomyRequestForm rcf("rcf"); // sign: 72, exec: 45
		std::cout << GREEN << rcf << RESET << std::endl;
		b.executeForm(rcf);
		b.signForm(rcf);
		std::cout << GREEN << rcf << RESET << std::endl;
		b.executeForm(rcf);

		std::cout << GREEN << std::endl << "\n--- PresidentialPardonForm Creation Form ---" << RESET << std::endl;
		PresidentialPardonForm ppf("ppf"); // sign: 72, exec: 45
		std::cout << GREEN << ppf << RESET << std::endl;
		b.executeForm(ppf);
		b.signForm(ppf);
		std::cout << GREEN << ppf << RESET << std::endl;
		b.executeForm(ppf);


		
	} 
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	
}


