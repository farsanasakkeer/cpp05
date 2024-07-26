/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 01:57:27 by farsana           #+#    #+#             */
/*   Updated: 2024/07/26 16:36:42 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		virtual ~Intern();
		Intern &operator=(Intern overload);

		AForm *makeForm(std::string name, std::string target);
		// AForm *makeForm(std::string name, std::string target)
		// AForm *makeForm(std::string &name, std::string &target);
};

#endif