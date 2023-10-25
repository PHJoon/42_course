/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:25:37 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 09:17:04 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    _type = src._type;
}

Animal::~Animal(void)
{
    std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(Animal const& rhs)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs._type;
    }
    return *this;
}

const std::string& Animal::getType(void) const
{
    return _type;
}

void Animal::makeSound(void) const
{
    std::cout << "This animal is making sound" << std::endl;
}
