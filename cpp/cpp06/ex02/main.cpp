/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:55:33 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/12 18:21:32 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <string>
#include <cstdlib>

Base *generate(void)
{
    srand(time(NULL));
    int rand_n = rand() % 3;

    switch (rand_n) {
        case 0:
            std::cout << "A generated" << std::endl;
            return new A();
        case 1:
            std::cout << "B generated" << std::endl;
            return new B();
        case 2:
            std::cout << "C generated" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base *p)
{
    std::string type;
    if (dynamic_cast<A *>(p)) {
        type = "A";
    } else if (dynamic_cast<B *>(p)) {
        type = "B";
    } else if (dynamic_cast<C *>(p)) {
        type = "C";
    }
    std::cout << "Actual type is " << type << std::endl;
}

void identify(Base &p)
{
    std::string type;
    try
    {
        A &ptr = dynamic_cast<A&>(p);
        type = "A";
        (void)ptr;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        B &ptr = dynamic_cast<B&>(p);
        type = "B";
        (void)ptr;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        C &ptr = dynamic_cast<C&>(p);
        type = "C";
        (void)ptr;
    }
    catch(const std::exception& e)
    {
    }
    
    std::cout << "Actual type is " << type << std::endl;
}

int main()
{
    Base *ptr = generate();
    identify(ptr);
    identify(*ptr);

    delete ptr;
    
    return 0;
}