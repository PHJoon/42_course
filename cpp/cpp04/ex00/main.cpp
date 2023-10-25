/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:23:49 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 09:53:51 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    std::cout << "----- Wrong Animal, Cat -----" << std::endl;
    const WrongAnimal *w_meta = new WrongAnimal();
    const WrongAnimal *k = new WrongCat();
    std::cout << k->getType() << " " << std::endl;
    k->makeSound();
    w_meta->makeSound();

    delete meta;
    delete i;
    delete j;
    delete w_meta;
    delete k;

    return 0;
}