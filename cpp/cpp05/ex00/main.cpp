/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:17:22 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/02 15:50:04 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

// void a()
// {
//     system("leaks a.out");
// }

int main()
{
    // atexit(a);
    std::cout << "--- TEST START ---" << std::endl << std::endl;

    std::cout << "--- name: A / grade: 151 ---" << std::endl;
    try
    {
        Bureaucrat a = Bureaucrat("A", 151);
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl << "--- name: B / grade: 0 ---" << std::endl;
    try
    {
        Bureaucrat b = Bureaucrat("B", 0);
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl << "--- name: C / grade: 13 ---" << std::endl;
    try
    {
        Bureaucrat c = Bureaucrat("C", 13);
        std::cout << c << std::endl;
        c.decrement();
        std::cout << c << std::endl;
        c.increment();
        c.increment();
        std::cout << c << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "--- name: D / grade: 1 ---" << std::endl;
    try
    {
        Bureaucrat d = Bureaucrat("D", 1);
        std::cout << d << std::endl;
        d.increment();
        std::cout << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "--- name: E / grade 150 ---" << std::endl;
    try
    {
        Bureaucrat e = Bureaucrat("E", 150);
        std::cout << e << std::endl;
        e.decrement();
        std::cout << e << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "--- TEST END ---" << std::endl;

    return 0;
}