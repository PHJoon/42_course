/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:06 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/21 11:09:45 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
    std::cout << "--- test ---" << std::endl;
    
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    
    std::cout << std::endl << "---  my test 1 ---" << std::endl;
    
    Span my = Span(10000);
    
    my.fillSpan(my.getBegin(), my.getEnd());
    my.printAll();
    std::cout << my.shortestSpan() << std::endl;
    std::cout << my.longestSpan() << std::endl;
    
    std::cout << std::endl << "---  my test 2 ---" << std::endl;
    
    Span my2 = Span(3);

    my2.addNumber(1);
    my2.addNumber(5);
    my2.addNumber(8);
    try
    {
        my2.addNumber(100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Span my3 = Span(4);
    try
    {
        std::cout << my3.shortestSpan() << std::endl;
        std::cout << my3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    my3.addNumber(1010);
    
    try
    {
        std::cout << my3.shortestSpan() << std::endl;
        std::cout << my3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Span my4 = Span(999999);
    my4.fillSpan(my4.getBegin(), my4.getEnd());
    try
    {
        my4.addNumber(120);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        my4.fillSpan(my4.getBegin(), my4.getBegin() + 2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    return 0;
}