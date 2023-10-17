/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:51:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 11:06:59 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {
    return ;    
}

HumanA::~HumanA() {
    return ;
}

void HumanA::attack(void) {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}