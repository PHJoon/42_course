/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:24:31 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 10:52:47 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): _type("default")
{
    // std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
    // std::cout << "AMateria " << _type << " Constructor called" << std::endl;    
}

AMateria::AMateria(const AMateria& src)
{
    // std::cout << "AMateria Copy constructor called" << std::endl;
    _type = src._type;
}

AMateria::~AMateria(void)
{
    // std::cout << "AMateria Destructor called" << std::endl;
}

AMateria& AMateria::operator=(AMateria const& rhs)
{
    // std::cout << "AMateria Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs._type;
    }
    return *this;
}

std::string const &AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* use AMateria to " << target.getName() << " *" << std::endl;
}
