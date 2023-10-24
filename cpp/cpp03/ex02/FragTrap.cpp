/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:28:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/24 14:41:08 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap()
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    this->_name = src._name;
    this->_hit_points = src._hit_points;
    this->_energy_points = src._energy_points;
    this->_attack_damage = src._attack_damage;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hit_points = rhs._hit_points;
        this->_energy_points = rhs._energy_points;
        this->_attack_damage = rhs._attack_damage;
    }
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if (_hit_points == 0)
    {
        std::cout << "FragTrap " << _name << " has no hit point !" << std::endl;
        return;
    }
    if (_energy_points == 0)
    {
        std::cout << "FragTrap " << _name << " has no energy point !" << std::endl;
        return;
    }
    _energy_points -= 1;
    std::cout << "FragTrap " << _name << " is preparing to attack" << std::endl;
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage !" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (_hit_points == 0)
    {
        std::cout << "FragTrap " << _name << " has no hit point !" << std::endl;
        return;
    }
    if (_energy_points == 0)
    {
        std::cout << "FragTrap " << _name << " has no energy point !" << std::endl;
        return;
    }
    _energy_points -= 1;
    std::cout << "FragTrap " << _name << " is high-fiving" << std::endl;
}