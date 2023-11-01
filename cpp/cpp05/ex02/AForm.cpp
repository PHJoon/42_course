/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:45:07 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/01 17:39:59 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("default"), _s_grade(150), _e_grade(150), _signed(false)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const int s_grade, const int e_grade): _name(name), _s_grade(s_grade), _e_grade(e_grade), _signed(false)
{
    std::cout << "AForm " << _name << " constructor called" << std::endl;
    if (s_grade < 1 || e_grade < 1) throw GradeTooHighException();
    else if (s_grade > 150 || s_grade > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& src): _name(src._name), _s_grade(src._s_grade), _e_grade(src._e_grade), _signed(src._signed)
{
    std::cout << "AForm copy constructor called" << std::endl;    
}

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm& AForm::operator=(AForm const& rhs)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _signed = rhs._signed;
    }
    return *this;
}

const std::string &AForm::getName(void) const
{
    return _name;
}

const int &AForm::getSignGrade(void) const
{
    return _s_grade;
}
const int &AForm::getExecuteGrade(void) const
{
    return _e_grade;
}

const bool &AForm::getSigned(void) const
{
    return _signed;
}

void    AForm::setSigned(bool sign)
{
    _signed = sign;
}

void    AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _s_grade) {
        _signed = true;
    } else throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return "Grade Too High!";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return "Grade Too Low!";
}

std::ostream &operator<<(std::ostream &out, const AForm &aForm)
{
    out << aForm.getName() << " signed: " << std::boolalpha << aForm.getSigned() << ", sign grade " << aForm.getSignGrade() << 
    ", execute grade " << aForm.getExecuteGrade() << ".";
    return out;
}