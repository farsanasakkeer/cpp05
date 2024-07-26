#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout <<  "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, int req_sign_grade, int req_exec_grade) :
    _name(name), _signed(false), _sign_grade(req_sign_grade), _exec_grade(req_exec_grade)
{
	std::cout << "Form " << this->_name << " named constructor called" << std::endl;
    if (_sign_grade < 1 || _exec_grade < 1)
        throw(GradeTooHighException());
    else if (_sign_grade > 150 || _exec_grade > 150)
        throw(GradeTooLowException());
    
}

Form::Form(const Form &copy) : _name(copy._name), _signed(false), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor Called" << std::endl;
}

Form &Form::operator=(const Form &overload)
{
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	if (this != &overload)
        _signed = overload._signed;
	return (*this);
}

void Form::beSigned(const Bureaucrat &sign)
{
    if (sign.getGrade() > this->_sign_grade)
        throw(GradeTooLowException());
    else
        this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high" RESET);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low" RESET);
}

const std::string Form::getName() const
{
	return(this->_name);
}

bool Form::getsign() const
{
	return(this->_signed);
}

int Form::getSignGrade() const
{
	return(this->_sign_grade);
}

int Form::getExecGrade() const
{
	return(this->_exec_grade);
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form name : " << form.getName()
        << "\nSign : " << (form.getsign() ? "yes":"no")
        << "\nSigned Grade : "<< form.getSignGrade()
        << "\nExecute Grade : " << form.getExecGrade();
    
    return out;
}