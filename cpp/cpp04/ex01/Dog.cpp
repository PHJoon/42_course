/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:34:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 12:21:38 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog Default Constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& src): Animal()
{
    std::cout << "Dog Copy constructor called" << std::endl;
    _type = src._type;
    _brain = new Brain();
    *_brain = *(src._brain);
}

Dog::~Dog(void)
{
    std::cout << "Dog Destructor called" << std::endl;
    delete _brain;
}

Dog& Dog::operator=(Dog const& rhs)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs._type;
        *_brain = *(rhs._brain);
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

void Dog::show_brain(void) const
{
    _brain->showIdeas();
}
