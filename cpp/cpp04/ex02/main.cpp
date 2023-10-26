/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:23:49 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 12:25:00 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
    // 추상클래스는 객체 생성 불가
    // const Animal *meta = new Animal(); // error
    Animal *i = new Dog();
    Animal *j = new Cat();
    Cat *c_ptr;
    Dog *d_ptr;

    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    d_ptr = dynamic_cast<Dog *>(i);
    d_ptr->show_brain();
    std::cout << std::endl;
    std::cout << j->getType() << " " << std::endl;
    j->makeSound();
    c_ptr = dynamic_cast<Cat *>(j);
    c_ptr->show_brain();

    std::cout << std::endl;

    delete i;
    delete j;
    
    return 0;
}