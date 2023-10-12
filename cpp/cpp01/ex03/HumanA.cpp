/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:51:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/12 10:00:06 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon) {
    return ;    
}

HumanA::~HumanA() {
    return ;
}

void HumanA::attack(void) {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}