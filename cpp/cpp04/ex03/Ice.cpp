/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:54:34 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 10:55:17 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
    // std::cout << "Ice Default constructor called" << std::endl;
    _type = "ice";
}

Ice::Ice(const Ice& src): AMateria()
{
    // std::cout << "Ice Copy constructor called" << std::endl;
    _type = src._type;
}

Ice::~Ice(void)
{
    // std::cout << "Ice Destructor called" << std::endl;
}

Ice& Ice::operator=(Ice const& rhs)
{
    // std::cout << "Ice Copy assingment operator called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs._type;
    }
    return *this;
}

AMateria *Ice::clone() const
{
    AMateria *ptr = new Ice();
    return ptr;   
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
