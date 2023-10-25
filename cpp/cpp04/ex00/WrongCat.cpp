/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:49:37 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 10:18:00 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat Default Constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal()
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    _type = src._type;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const& rhs)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs._type;
    }
    return *this;
}

const std::string &WrongCat::getType(void) const
{
    return _type;
}

void WrongCat::makeSound(void) const
{
    std::cout << "peep-peep! peep-peep! peep!" << std::endl;
}