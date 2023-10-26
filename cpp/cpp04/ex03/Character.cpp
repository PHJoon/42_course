/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:51:25 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 15:19:39 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name("default")
{
    // std::cout << "Character Default Constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
    }
}

Character::Character(std::string name): _name(name)
{
    // std::cout << "Character Default Constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character& src)
{
    // std::cout << "Character Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = src._inventory[i]->clone();
    }
}

Character::~Character(void)
{
    // std::cout << "Character Destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete _inventory[i];
        _inventory[i] = NULL;
    }
}

Character& Character::operator=(Character const& rhs)
{
    // std::cout << "Character Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            _inventory[i] = rhs._inventory[i]->clone();
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
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3) return ;
    _inventory[idx]= NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3) return ;
    if (_inventory[idx] == NULL) return ;
    _inventory[idx]->use(target);
}