/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:44:36 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/20 12:10:59 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) 
{
    ClapTrap a("Tom");
    ClapTrap b("Bob");

    a.attack("Bob");
    b.takeDamage(a.getAD());
    
    b.setAD(10);

    std::cout << "a  hp: " << a.getHP() << std::endl;    
    
    b.attack("Tom");
    a.takeDamage(b.getAD());
    
    std::cout << "a  hp: " << a.getHP() << std::endl;
    
    a.beRepaired(10);
    a.attack("Tom");
    
    return 0;
}