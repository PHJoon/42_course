/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:11:39 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/12 07:32:38 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

int main()
{
    std::string arr1[3] = {"테스트용", "배열입니다", "!!"};
    int arr2[5] = {123, 45, 6789, 10, 11};
    double arr3[4] = {0.023, 1234.123, 384.0, 99.1};
    char arr4[2] = {'a', 'b'};

    iter(arr1, 3, ::printArr);
    std::cout << std::endl;
    iter(arr2, 5, ::printArr);
    std::cout << std::endl;
    iter(arr3, 4, ::printArr);
    std::cout << std::endl;
    iter(arr4, 2, ::printArr);
    std::cout << std::endl;


    return 0;
}