/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:11:39 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/18 17:20:36 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void testIter(T *arrPtr, std::size_t len)
{
    std::cout << std::boolalpha;
    std::cout << "before addSomething" << std::endl;
    iter(arrPtr, len, ::printArr);
    std::cout << std::endl;
    iter(arrPtr, len, ::addSomething);
    std::cout << std::endl << "after addSomething" << std::endl;
    iter(arrPtr, len, ::printArr);
    std::cout << std::endl << std::endl;
}

int main()
{
    std::string arr1[3] = {"테스트용", "배열입니다", "!!"};
    const int arr2[5] = {123, 45, 6789, 10, 11};
    const double arr3[4] = {0.023, 1234.123, 384.0, 99.1};
    const char arr4[2] = {'a', 'b'};
    bool arr5[3] = {true, false, false};

    std::cout << "--- std::string ---" << std::endl;
    // iter(arr1, 3, ::printArr);
    testIter(arr1, sizeof(arr1)/sizeof(std::string));
    
    std::cout << "--- int ---" << std::endl;
    // iter(arr2, 5, ::printArr);
    testIter(arr2, sizeof(arr2)/sizeof(int));
    
    std::cout << "--- double ---" << std::endl;
    testIter(arr3, sizeof(arr3)/sizeof(double));
    
    std::cout << "--- char ---" << std::endl;
    testIter(arr4, sizeof(arr4)/sizeof(char));

    std::cout << "--- bool ---" << std::endl;
    testIter(arr5, sizeof(arr5)/sizeof(bool));

    return 0;
}