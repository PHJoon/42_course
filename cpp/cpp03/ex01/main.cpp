/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:44:36 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/24 14:40:25 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) 
{
    ClapTrap    t("Tom");
    ClapTrap    *pInterface = NULL;
    ClapTrap    *pBase = new ClapTrap("A");
    ClapTrap    *pChildB = new ScavTrap("B");
    ClapTrap    *pChildC = new ScavTrap("C");
    ScavTrap    *pInterface2 = NULL;
    
    std::cout << std::endl;
    std::cout << "--- ClapTrap A ---" << std::endl << std::endl;
    pInterface = pBase;
    pInterface->attack(t.getName());
    t.takeDamage(pInterface->getAD());
    std::cout << std::endl;

    std::cout << "--- Scav Trap B ---" << std::endl << std::endl;
    pInterface = pChildB;
    pInterface->attack(t.getName());
    t.takeDamage(pInterface->getAD());
    std::cout << std::endl;

    std::cout << "--- Scav Trap C ---" << std::endl << std::endl;
    pInterface = pChildC;
    pInterface->attack(t.getName());
    t.takeDamage(pInterface->getAD());
    std::cout << std::endl;


    std::cout << "--- DownCasting ---"<< std::endl;
    // error -> 다운캐스팅 필요
    // pInterface->guardGate();
    pInterface2 = dynamic_cast<ScavTrap *>(pChildC);
    if (!pInterface2) { std::cout << "fail dynamic cast" << std::endl;}
    pInterface2->guardGate();

    std::cout << std::endl;
    pInterface = pChildB;
    pInterface->attack(pInterface2->getName());
    pInterface2->takeDamage(pInterface->getAD());
    pInterface->beRepaired(20);

    std::cout << std::endl;
    std::cout << "--- Destructor ---" << std::endl;
    delete pChildB;
    delete pChildC;
    delete pBase;

    return 0;
}