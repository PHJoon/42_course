/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:11:45 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/22 16:36:04 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->setName(name);
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;

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
        this->setName(rhs.getName());
        this->setName(rhs.getName());
        this->setName(rhs.getName());
        this->setName(rhs.getName());
    }
    return *this;
}