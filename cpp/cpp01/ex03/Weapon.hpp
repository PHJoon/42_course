/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:42:05 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/12 09:36:56 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
    std::string type;
public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    const std::string   &getType(void);
    void    setType(const std::string &type);
};



#endif