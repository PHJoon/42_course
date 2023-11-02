/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:17:17 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/02 13:05:28 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
    std::cout << "Bureaucrat " << _name << " constructor called" << std::endl;
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    else if (grade > 150) throw Bureaucrat::GradeTooLowException();
    else _grade = grade;
}
        

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    _grade = src._grade;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _grade = rhs._grade;
    }
    return *this;
}

const std::string &Bureaucrat::getName(void) const
{
    return _name;
}

const int &Bureaucrat::getGrade(void) const
{
    return _grade;   
}

void Bureaucrat::increment(void)
{
    if (_grade - 1 < 1) throw Bureaucrat::GradeTooHighException(); 
    else {
        std::cout << _name << "'s grade increment" << std::endl;
        _grade -= 1;
    }
}

void Bureaucrat::decrement(void)
{
    if (_grade + 1 > 150) throw Bureaucrat::GradeTooHighException();
    else {
        std::cout << _name << "'s grade decrement" << std::endl;
        _grade += 1;
    }
}

void    Bureaucrat::signForm(AForm &aForm)
{
    try {
        aForm.beSigned(*this);
        std::cout << _name << " signed " << aForm.getName() << std::endl;
    } catch(std::exception &e) {
        std::cout << _name << " couldn't signed " << aForm.getName() << " because " << aForm.getName() << 
        "'s sign grade is " << aForm.getSignGrade() << " and " << _name << "'s grade is " << _grade << "." << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &aForm)
{
    try
    {
        aForm.executeForm(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't executed " << aForm.getName() << " because " << aForm.getName() << 
        "'s execute grade is " << aForm.getExecuteGrade() << " and " << _name << "'s grade is " << _grade << "." << std::endl;
    }
    
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "Grade Too High!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "Grade Too Low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}