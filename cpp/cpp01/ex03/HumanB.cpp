/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:56:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/12 10:00:52 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name) {
    return ;
}

HumanB::~HumanB() {
    return ;  
}

void HumanB::attack(void) {
    if (!this->weapon)
    {
        std::cout << this->name << " has no weapon" << std::endl;
    }
    else
    {
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}
