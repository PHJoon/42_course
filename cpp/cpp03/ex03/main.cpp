/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:44:36 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/24 14:42:29 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) 
{
    ClapTrap    t("Tom");
    ClapTrap    *pInterface = NULL;
    ClapTrap    *pBase = new ClapTrap("A");
    ClapTrap    *pChildB = new ScavTrap("B");
    ClapTrap    *pChildC = new FragTrap("C");
    ClapTrap    *pChildD = new DiamondTrap("D");
    ScavTrap    *pInterfaceScav = NULL;
    FragTrap    *pInterfaceFrag = NULL;
    DiamondTrap    *pInterfaceDiamond = NULL;
    
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
    
    std::cout << "--- ScavTrap B info ---" << std::endl;
    std::cout << pInterface->getName() << "/" << pInterface->getHP() << "/" << pInterface->getEP() << "/" << pInterface->getAD() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Frag Trap C ---" << std::endl << std::endl;
    pInterface = pChildC;
    pInterface->attack(t.getName());
    t.takeDamage(pInterface->getAD());

    std::cout << "--- FragTrap C info ---" << std::endl;
    std::cout << pInterface->getName() << "/" << pInterface->getHP() << "/" << pInterface->getEP() << "/" << pInterface->getAD() << std::endl;
    std::cout << std::endl;
    
    std::cout << "--- Diamond Trap C ---" << std::endl << std::endl;
    pInterface = pChildD;
    pInterface->attack(t.getName());
    t.takeDamage(pInterface->getAD());
    std::cout << std::endl;

    std::cout << "--- DiamondTrap D info ---" << std::endl;
    std::cout << pInterface->getName() << "/" << pInterface->getHP() << "/" << pInterface->getEP() << "/" << pInterface->getAD() << std::endl;
    std::cout << std::endl;

    std::cout << "--- DownCasting ---"<< std::endl;
    // error -> 다운캐스팅 필요
    // pInterface->guardGate();

    pInterfaceScav = dynamic_cast<ScavTrap *>(pChildB);
    if (!pInterfaceScav) { std::cout << "fail dynamic cast" << std::endl;}
    pInterfaceScav->guardGate();
    
    pInterfaceFrag = dynamic_cast<FragTrap *>(pChildC);
    if (!pInterfaceFrag) { std::cout << "fail dynamic cast" << std::endl;}
    pInterfaceFrag->highFivesGuys();
    
    pInterfaceDiamond = dynamic_cast<DiamondTrap *>(pChildD);
    if (!pInterfaceFrag) { std::cout << "fail dynamic cast" << std::endl;}
    pInterfaceDiamond->guardGate();
    pInterfaceDiamond->highFivesGuys();
    pInterfaceDiamond->whoAmI();

    std::cout << std::endl;
    
    pInterface = pChildD;
    pInterface->attack(pInterfaceDiamond->getName());
    pInterfaceDiamond->takeDamage(pInterface->getAD());
    pInterfaceDiamond->beRepaired(20);

    std::cout << std::endl;
    std::cout << "--- Destructor ---" << std::endl;
    delete pChildD;
    delete pChildB;
    delete pChildC;
    delete pBase;

    return 0;
}