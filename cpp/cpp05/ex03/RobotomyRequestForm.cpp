/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:55:08 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/02 15:39:32 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequest", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequest", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm target: " << _target << " default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm("RobotomyRequest", 72, 45), _target(src._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    this->setSigned(src.getSigned());
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _target = rhs._target;
        this->setSigned(rhs.getSigned());
    }
    return *this;
}

void    RobotomyRequestForm::executeForm(Bureaucrat const &executor) const
{
    if (this->getSigned() && executor.getGrade() <= this->getExecuteGrade())
    {
        srand(time(NULL));
        int rand_n = rand();
        if (rand_n % 2)
        {
            std::cout << _target << " has been robotomized successfully" << std::endl;
        }
        else
        {
            std::cout << _target << " has failed robotomized" << std::endl;
        }
    } else throw GradeTooLowException();    
    
}
