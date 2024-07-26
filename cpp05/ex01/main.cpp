/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:55:32 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/07/23 23:58:33 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

		try {
			try
			{
				Form f1("f1", 10, 0);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			
			try
			{
				Form f2("f2", 10, 151);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			try
			{
				Form f3("f3", 151, 10);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			try
			{
				Form f4("f4", 0, 10);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			std::cout <<YELLOW<<"------------------------------" <<RESET<< std::endl;
			Bureaucrat b1("b1", 50);
			Form f5("f5", 15, 10);
			
			std::cout << BLUE << f5 << RESET << std::endl;
			std::cout <<YELLOW<< b1 <<RESET<< std::endl;

			b1.signForm(f5); 
			std::cout <<YELLOW<<"------------------------------" <<RESET<< std::endl;
			Bureaucrat b2("b2", 50);
			Form f6;
			
			std::cout << BLUE << f6 << RESET << std::endl;
			std::cout <<YELLOW<< b2 <<RESET<< std::endl;

			b2.signForm(f6); 
			std::cout <<YELLOW<<"----sign form called----" <<RESET<< std::endl;
			
			std::cout << BLUE << f6 << RESET << std::endl;
			std::cout <<YELLOW<< b2 <<RESET<< std::endl;
			std::cout <<YELLOW<<"------------------------------" <<RESET<< std::endl;
			
			
		} 
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

	
}


