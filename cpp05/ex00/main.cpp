/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:55:32 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/07/21 19:15:32 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{

	try
	{
		Bureaucrat a;
		Bureaucrat c("def", 52);
		Bureaucrat d("ghi", 1);
		Bureaucrat e("jkl", 15);
		Bureaucrat f("mno", 75);
				
		try{
			Bureaucrat b("b", 10);
			std::cout << YELLOW << b << RESET << std::endl;
			std ::cout <<"\n\n-------------" << std::endl;
			std ::cout << YELLOW << b.getName() << RESET << std::endl;
			std ::cout << YELLOW << b.getGrade() << RESET << std::endl;
			
			b.decGrade();
			

			std ::cout << YELLOW << b.getName() << RESET << std::endl;
			std ::cout << YELLOW << b.getGrade() << RESET << std::endl;

			b.incGrade();

			std ::cout << YELLOW << b.getName() << RESET << std::endl;
			std ::cout << YELLOW << b.getGrade() << RESET << std::endl;
			std ::cout <<"--------------\n\n" << std::endl;

		}
		catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    	}
		
	} 
	catch (const std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
    }
}