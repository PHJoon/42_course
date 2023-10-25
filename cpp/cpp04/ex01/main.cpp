/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:23:49 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 11:14:01 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j; // should not create a leak
    delete i;

    // Animal *array_ptr = new Animal[10];
    Animal *array_ptr[10];
    Cat *c_ptr;
    Dog *d_ptr;

    for (int k = 0; k < 10; k++)
    {
        if (k > 4)
        {
            array_ptr[k] = new Cat(); 
        }
        else
        {
            array_ptr[k] = new Dog(); 
        }
    }
    
    for (int k = 0; k < 10; k++)
    {
        std::cout << "----- < " << k << " > -----" << std::endl;
        std::cout << array_ptr[k]->getType() << " " << std::endl;
        array_ptr[k]->makeSound();
        if (k > 4)
        {
            c_ptr = dynamic_cast<Cat *>(array_ptr[k]);
            c_ptr->show_brain();
        }
        else
        {
            d_ptr = dynamic_cast<Dog *>(array_ptr[k]);
            d_ptr->show_brain();
        }
        std::cout << std::endl;
    }

    for (int k = 0; k < 10; k++)
    {
        std::cout << "--- < " << k << " > --- Destructor ---" << std::endl;
        delete array_ptr[k];
    }

    return 0;
}