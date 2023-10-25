/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:07:37 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 15:15:42 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
    std::cout << "Cure Default constructor called" << std::endl;
    _type = "cure";
}

Cure::Cure(const Cure& src): AMateria()
{
    std::cout << "Cure Copy constructor called" << std::endl;
    _type = src._type;
}

Cure::~Cure(void)
{
    std::cout << "Cure Destructor called" << std::endl;
}

Cure& Cure::operator=(Cure const& rhs)
{
    std::cout << "Cure Copy assingment operator called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs._type;
    }
    return *this;
}

AMateria *Cure::clone() const
{

}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}