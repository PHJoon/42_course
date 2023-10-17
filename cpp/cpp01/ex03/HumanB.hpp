/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:43:04 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 11:18:37 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
    private:
        std::string _name;
        Weapon  *_weapon;
    public:
        HumanB(std::string name);
        ~HumanB();
        void    attack(void);
        void    setWeapon(Weapon &weapon);
};

#endif