/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:35:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/12 08:40:19 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
    return ;
}

Weapon::~Weapon() {
    return ;
}

Weapon::Weapon(std::string type): type(type) {
    return ;   
}

const std::string &Weapon::getType(void) {
    const std::string &ref = this->type;
    return (ref);
}

void Weapon::setType(const std::string &type) {
    this->type = type;
}