/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:42:19 by farsana           #+#    #+#             */
/*   Updated: 2024/07/26 15:36:39 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm{

public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string name, const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &overload);
        virtual ~RobotomyRequestForm();

        void formAction() const;
};

#endif