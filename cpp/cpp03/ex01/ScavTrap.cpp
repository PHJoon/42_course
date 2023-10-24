/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:11:45 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/24 14:41:11 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap()
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    this->_name = src._name;
    this->_hit_points = src._hit_points;
    this->_energy_points = src._energy_points;
    this->_attack_damage = src._attack_damage;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hit_points = rhs._hit_points;
        this->_energy_points = rhs._energy_points;
        this->_attack_damage = rhs._attack_damage;
    }
    return *this;
}

void    ScavTrap::attack(const std::string &target)
{
    if (_hit_points == 0)
    {
        std::cout << "ScavTrap " << _name << " has no hit point !" << std::endl;
        return;
    }
    if (_energy_points == 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy point !" << std::endl;
        return;
    }
    _energy_points -= 1;
    std::cout << "ScavTrap " << _name << " is now in Attack mode" << std::endl;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage !" << std::endl;
}

void ScavTrap::guardGate(void)
{
    if (_hit_points == 0)
    {
        std::cout << "ScavTrap " << _name << " has no hit point !" << std::endl;
        return;
    }
    if (_energy_points == 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy point !" << std::endl;
        return;
    }
    _energy_points -= 1;
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
