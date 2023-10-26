/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:35:56 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 16:09:27 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Floor.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter *me = new Character("me");
    
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter *bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;

    // std::cout << std::endl << "-----   my test   -----" << std::endl;

    // Floor *floor = new Floor();

    // IMateriaSource *src_re = new MateriaSource();
    // src_re->learnMateria(new Ice());
    // src_re->learnMateria(new Cure());
    
    // ICharacter *me_re = new Character("me_re");
    
    // AMateria *ptr_arr[6];
    // for (int i = 0; i < 6; i++)
    // {
    //     if (i % 2) {
    //         ptr_arr[i] = src_re->createMateria("ice");
    //     } else {
    //         ptr_arr[i] = src_re->createMateria("cure");
    //     }
    // }
    // for (int i = 0; i < 6; i++)
    // {
    //     me_re->equip(ptr_arr[i]);
    //     me_re->unequip(0);
    //     floor->putFloor(ptr_arr[i]);
    //     floor->showFloor();
    //     std::cout << std::endl;
    // }

    // delete me_re;
    // delete src_re;

    // delete floor;
    
    
    return 0;
}