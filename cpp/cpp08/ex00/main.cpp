/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:34:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/21 13:04:40 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template<typename T>
void printContainer(T &container)
{
    for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
    {
        std::cout << *iter;
        if (iter + 1 != container.end()) {
            std::cout << " / ";
        } else {
            std::cout << std::endl;
        }
    }
}

template<>
void printContainer(std::list<int> &container)
{
    for (std::list<int>::iterator iter = container.begin(); iter != container.end(); iter++)
    {
        std::cout << *iter;
        std::list<int>::iterator next = iter;
        if (++next != container.end()) {
            std::cout << " / ";
        } else {
            std::cout << std::endl;
        }
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 8, 123, 23};
    int arr2[] = {42, 123, 89498, -230, -1, -65};
    int arr3[] = {0, 20, 47, 42, 2424};


    std::vector<int> A(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    std::deque<int> B(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    std::list<int> C(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
    
    std::cout << "=== A ===" << std::endl;
    printContainer(A);
    std::cout << "=== B ===" << std::endl;
    printContainer(B);
    std::cout << "=== C ===" << std::endl;
    printContainer(C);

    std::cout << std::endl;
    try
    {
        std::cout << *::easyfind(A, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << *::easyfind(B, 50) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << *::easyfind(C, -490) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;
    try
    {
        std::cout << *::easyfind(A, 8) << std::endl;
        std::cout << *::easyfind(B, 42) << std::endl;
        std::cout << *::easyfind(C, 47) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    return 0;
}