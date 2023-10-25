/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:34:37 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 10:17:49 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat Default Constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat& src): Animal()
{
    std::cout << "Cat Copy constructor called" << std::endl;
    _type = src._type;
}

Cat::~Cat(void)
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const& rhs)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs._type;
    }
    return *this;
}

const std::string& Cat::getType(void) const
{
    return _type;
}

void Cat::makeSound(void) const
{
    std::cout << "meow-meow! meow-meow! meow!" << std::endl;
}