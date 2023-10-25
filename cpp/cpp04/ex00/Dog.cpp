/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:34:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 09:17:17 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog Default Constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& src): Animal()
{
    std::cout << "Dog Copy constructor called" << std::endl;
    _type = src._type;
}

Dog::~Dog(void)
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const& rhs)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs._type;
    }
    return *this;
}

const std::string& Dog::getType(void) const
{
    return _type;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof-Woof! ruff-ruff! bark!" << std::endl;
}
