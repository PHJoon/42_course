/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:32:10 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/01 15:29:58 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("default"), _sign_grade(150), _execute_grade(150), _signed(false)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int s_grade, int e_grade): _name(name), _sign_grade(s_grade), _execute_grade(e_grade), _signed(false)
{
    std::cout << "Form " << _name << " constructor called" << std::endl;
    if (s_grade < 1 || e_grade < 1) throw GradeTooHighException();
    else if (s_grade > 150 || s_grade > 150) throw GradeTooLowException();
}

Form::Form(const Form& src): _name(src._name), _sign_grade(src._sign_grade), _execute_grade(src._execute_grade), _signed(src._signed)
{
    std::cout << "Form copy constructor called" << std::endl;    
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(Form const& rhs)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _signed = rhs._signed;
    }
    return *this;
}

const std::string &Form::getName(void) const
{
    return _name;
}

const int &Form::getSignGrade(void) const
{
    return _sign_grade;
}
const int &Form::getExecuteGrade(void) const
{
    return _execute_grade;
}

const bool &Form::getSigned(void) const
{
    return _signed;
}

void    Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _sign_grade) {
        _signed = true;
    }
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return "Form Grade Too High!";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return "Form Grade Too Low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << " signed: " << form.getSigned() << ", sign grade " << form.getSignGrade() << 
    ", execute grade " << form.getExecuteGrade() << ".";
    return out;
}