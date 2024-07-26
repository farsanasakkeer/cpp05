/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 01:33:34 by farsana           #+#    #+#             */
/*   Updated: 2024/07/26 15:36:19 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm:public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string name, const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm overload);

		void formAction() const;
};
#endif