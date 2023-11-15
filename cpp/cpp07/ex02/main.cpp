/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:17:28 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/15 09:06:58 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

// void a()
// {
//     system("leaks a.out");
// }

int main()
{
    // atexit(a);
    unsigned int intLen = 10;
    unsigned int floatLen = 5;

    std::cout << "--- my test ---" << std::endl;
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

    std::cout << std::endl << "--- main test ---" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;

    return 0;
}