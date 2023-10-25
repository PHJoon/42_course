/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:51:25 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 15:40:20 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
    std::cout << "Character Default Constructor called" << std::endl;
}

Character::Character(const Character& src)
{
    std::cout << "Character Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = src._inventory[i];
    }
}

Character::~Character(void)
{
    std::cout << "Character Destructor called" << std::endl;
}

Character& Character::operator=(Character const& rhs)
{
    std::cout << "Character Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            _inventory[i] = rhs._inventory[i];
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    
}

void Character::unequip(int idx)
{
    
}

void Character::use(int idx, ICharacter &target)
{
    
}