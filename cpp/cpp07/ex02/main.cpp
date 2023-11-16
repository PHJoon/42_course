/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:17:28 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/16 09:14:34 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

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

    std::cout << "--- my test1 ---" << std::endl;
    Array<int> *A = new Array<int>(intLen);
    Array<float> *B = new Array<float>(floatLen);

    srand(time(NULL));
    for (unsigned int i = 0; i < A->size(); i++)
    {
        (*A)[i] = rand();
    }
    for (unsigned int i = 0; i < B->size(); i++)
    {
        (*B)[i] = static_cast<float>(rand());
    }

    Array<int> C = Array<int>(*A);
    for (unsigned int i = 0; i < C.size(); i++)
    {
        C[i] += 42;
    }

    Array<float> D = *B;
    for (unsigned int i = 0; i < D.size(); i++)
    {
        D[i] = i + 4.242;
    }

    const Array<int> E = Array<int>(C);
    
    for (unsigned int i = 0; i < E.size(); i++)
    {
        std::cout << "A: " << (*A)[i] << "| C: " << C[i] << "| E: " << E[i] << std::endl;
    }

    for (unsigned int i = 0; i < B->size(); i++)
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


    std::cout << std::endl << "--- my test2 ---" << std::endl;
    Array<std::string> strArr(8);
    std::string *strArr2 = new std::string[8];
    for (unsigned int i = 0; i < strArr.size(); i++)
    {
        if (i % 2) {
            strArr[i] = "world";
        } else {
            strArr[i] = "hello";
        }
    }

    for (unsigned int i = 0; i < 8; i++)
    {
        strArr2[i] = strArr[i];
    }
    
    std::cout << "strArr 1 / 2" << std::endl;
    for (unsigned int i = 0; i < strArr.size(); i++)
    {
        std::cout << "strArr 1 => " << strArr[i] << " | strArr2 => " << strArr2[i] << std::endl;
    }
    
    try
    {
        for (unsigned int i = 0; i < strArr.size(); i++)
        {
            if (i % 2) {
                strArr[i] = strArr[i + 1] + strArr[i];
            } else {
                strArr[i] = strArr[i] + strArr[i + 1];
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // 일반 배열 인덱스에서는 예외가 안잡힘 undefined behavior이기 때문
    try
    {
        strArr2[-1] = "hi";
    }
    catch(const std::exception& e)
    {
        std::cerr << "strArr2 index" << std::endl;
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl << "strArr 1 | 2" << std::endl;
    for (unsigned int i = 0; i < strArr.size(); i++)
    {
        std::cout << "strArr 1 => " << strArr[i] << " | strArr2 => " << strArr2[i] << std::endl;
    }

    delete[] strArr2;


    std::cout << std::endl << "--- const test ---" << std::endl;
    /* const [] overloading 없는 경우 에러 */
    // const Array<int> arr(1);
    // arr[0];
    
    const Array<int> a(10);
    const Array<int> tmp = a;
    
    // tmp[1] = 2; error
    tmp[2];
    

    return 0;
}