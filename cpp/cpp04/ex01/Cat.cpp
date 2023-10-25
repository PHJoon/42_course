/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:34:37 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 10:55:17 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat Default Constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& src): Animal()
{
    std::cout << "Cat Copy constructor called" << std::endl;
    _type = src._type;
    _brain = src._brain;
}

Cat::~Cat(void)
{
    std::cout << "Cat Destructor called" << std::endl;
    delete _brain;
}

Cat& Cat::operator=(Cat const& rhs)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs._type;
        _brain = rhs._brain;
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

void Cat::show_brain(void) const
{
    _brain->showIdeas();
}
