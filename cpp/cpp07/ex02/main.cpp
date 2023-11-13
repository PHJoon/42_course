/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:17:28 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/14 07:47:38 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

// void a()
// {
//     system("leaks a.out");
// }

int main()
{
    // atexit(a);
    unsigned int intLen = 10;
    unsigned int floatLen = 5;

    Array<int> *A = new Array<int>(intLen);
    Array<float> *B = new Array<float>(floatLen);

    for (unsigned int i = 0; i < intLen; i++)
    {
        (*A)[i] = i;
    }
    for (unsigned int i = 0; i < floatLen; i++)
    {
        (*B)[i] = i + 4.24242;
    }

    Array<int> C = Array<int>(*A);
    for (unsigned int i = 0; i < intLen; i++)
    {
        C[i] = i + 42;
    }

    Array<float> D = *B;
    for (unsigned int i = 0; i < floatLen; i++)
    {
        D[i] -= 2.24242;
    }
    
    for (unsigned int i = 0; i < intLen; i++)
    {
        std::cout << "A: " << (*A)[i] << "| C: " << C[i] << std::endl;
    }

    for (unsigned int i = 0; i < floatLen; i++)
    {
        std::cout << "B: " << (*B)[i] << "| D: " << D[i] << std::endl;
    }

    delete A;
    delete B;

    return 0;
}