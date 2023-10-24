/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:22:00 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/24 14:07:17 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("default_clap_name")
{
    this->_name = "default";
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
    this->_name = name;
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage; 
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    this->_name = src._name;
    this->_hit_points = src._hit_points;
    this->_energy_points = src._energy_points;
    this->_attack_damage = src._attack_damage;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs)
{
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hit_points = rhs._hit_points;
        this->_energy_points = rhs._energy_points;
        this->_attack_damage = rhs._attack_damage;
    }
    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is " << _name << " ClapTrap name is " << ClapTrap::_name << std::endl;
}
