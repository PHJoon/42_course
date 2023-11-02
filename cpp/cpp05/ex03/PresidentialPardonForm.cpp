/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:56:45 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/02 15:39:26 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardon", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardon", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm target: " << _target << " constructor called" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm("PresidentialPardon", 25, 5), _target(src._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    this->setSigned(src.getSigned());
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _target = rhs._target;
        this->setSigned(rhs.getSigned());
    }
    return *this;
}

void    PresidentialPardonForm::executeForm(Bureaucrat const &executor) const
{
    if (this->getSigned() && executor.getGrade() <= this->getExecuteGrade())
    {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    } else throw GradeTooLowException();
}
