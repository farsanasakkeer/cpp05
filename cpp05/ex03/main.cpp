/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:55:32 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/07/26 20:48:01 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

int main()
{

	try {
		
		Intern someRandomIntern;
		
		AForm* rrf;
		rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
		std::cout << YELLOW << *rrf << RESET << std::endl;
		delete rrf;
		
		AForm* ppf = someRandomIntern.makeForm("Presidential Pardon", "Bender");
		std::cout << YELLOW << *ppf << RESET << std::endl;
		delete ppf;

		AForm* scf = someRandomIntern.makeForm("Shrubbery Creation", "Bender");
		std::cout << YELLOW << *scf << RESET << std::endl;
		delete scf;

		AForm* ivf = someRandomIntern.makeForm("invalid Creation", "Bender");
		delete ivf;
		

		Bureaucrat Bureacrat("test",7); 
		AForm* test = someRandomIntern.makeForm("Shrubbery Creation", "Bender");
		std::cout << YELLOW << *test << RESET << std::endl;
		Bureacrat.signForm(*test);
		std::cout << YELLOW << *test << RESET << std::endl;
		Bureacrat.executeForm(*test);
		delete test;
		
	} 
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	
}


