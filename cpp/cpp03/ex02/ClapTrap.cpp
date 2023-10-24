/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:44:23 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/24 11:16:00 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name(""), _hit_points(10), _energy_points(10), _attack_damage(0) 
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    this->_name = src._name;
    this->_hit_points = src._hit_points;
    this->_energy_points = src._energy_points;
    this->_attack_damage = src._attack_damage;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hit_points = rhs._hit_points;
        this->_energy_points = rhs._energy_points;
        this->_attack_damage = rhs._attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (_hit_points == 0) {
        std::cout << "ClapTrap " << _name << " has no hit point !" << std::endl;
        return ;
    }
    if (_energy_points == 0) {
        std::cout << "ClapTrap " << _name << " has no energy point !" << std::endl;
        return ;
    }
    _energy_points -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_points < amount) {
        _hit_points = 0;
    } else {
        _hit_points -= amount;
    }
    std::cout << "ClapTrap " << _name << " take " << amount << " points of damage !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hit_points == 0)
    {
        std::cout << "ClapTrap " << _name << " has no hit point !" << std::endl;
        return;
    }
    if (_energy_points == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy point !" << std::endl;
        return;
    }
    _hit_points += amount;
    _energy_points -= 1;
    std::cout << "ClapTrap " << _name << " is repaired" << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return _name;
}

unsigned int ClapTrap::getHP(void) const
{
    return _hit_points;
}

unsigned int ClapTrap::getEP(void) const
{
    return _energy_points;
}

unsigned int ClapTrap::getAD(void) const
{
    return _attack_damage;
}

void ClapTrap::setName(std::string &name)
{
    _name = name;
}

void ClapTrap::setHP(unsigned int hp)
{
    _hit_points = hp;
}

void ClapTrap::setEP(unsigned int ep)
{
    _energy_points = ep;
}

void ClapTrap::setAD(unsigned int ad)
{
    _attack_damage = ad;
}
