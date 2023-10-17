/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:56:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 11:37:22 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {
    return ;
}

HumanB::~HumanB() {
    return ;  
}

void HumanB::attack(void) {
    if (!_weapon)
    {
        std::cout << _name << " has no weapon" << std::endl;
    }
    else
    {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}
