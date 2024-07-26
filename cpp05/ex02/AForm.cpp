/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:31:15 by fvaliyak           #+#    #+#             */
/*   Updated: 2024/07/24 17:31:17 by fvaliyak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _sign_grade(150), _exec_grade(150), _target("default")
{
	std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string name, int req_sign_grade, int req_exec_grade, const std::string target) : 
    _name(name), _signed(false), _sign_grade(req_sign_grade), _exec_grade(req_exec_grade), _target(target)
{
	std::cout << "AForm " << this->_name << " named constructor called" << std::endl;
    if (_sign_grade < 1 || _exec_grade < 1)
        throw(GradeTooHighException());
    else if (_sign_grade > 150 || _exec_grade > 150)
        throw(GradeTooLowException());
    
}

AForm::AForm(const AForm &copy) : 
    _name(copy._name), _signed(false), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade), _target(copy._target)

{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor Called" << std::endl;
}

AForm &AForm::operator=(const AForm &overload)
{
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	if (this != &overload)
        _signed = overload._signed;
	return (*this);
}

void AForm::beSigned(const Bureaucrat &sign)
{
    if (sign.getGrade() > this->_sign_grade)
        throw(GradeTooLowException());
    else
        this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high" RESET);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low" RESET);
}

const std::string AForm::getName() const
{
	return(this->_name);
}

bool AForm::getsign() const
{
	return(this->_signed);
}

int AForm::getSignGrade() const
{
	return(this->_sign_grade);
}

int AForm::getExecGrade() const
{
	return(this->_exec_grade);
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    out << "AForm name : " << AForm.getName()
        << "\nSign : " << (AForm.getsign() ? "yes":"no")
        << "\nSigned Grade : "<< AForm.getSignGrade()
        << "\nExecute Grade : " << AForm.getExecGrade()
        << "\nTarget : " << AForm.getTarget();
    
    return out;
}

const std::string AForm::getTarget() const
{
	return (this->_target);
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("This form was not signed");
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!this->_signed)// should be signed otherwise throw the exception
	{
		throw NotSignedException();
	} else if (this->_exec_grade < executor.getGrade()){
		throw GradeTooLowException();
	} 
    else {
		this->formAction();
	}
}