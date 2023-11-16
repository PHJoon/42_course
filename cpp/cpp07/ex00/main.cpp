/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:07:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/16 10:25:51 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
    std::cout << "--- main test ---" << std::endl;
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;


    std::cout << std::endl << "--- my test ---" << std::endl;
    char c_a = 'a';
    char c_b = 'k';
    float f_a = 1.2231f;
    float f_b = 9239.343f;
    double d_a = 4.24242;
    double d_b = 2.42424;
    bool b_a = true;
    bool b_b = false;
    
    ::printTest(c_a, c_b);
    ::printTest(f_a, f_b);
    ::printTest(d_a, d_b);
    ::printTest(b_a, b_b);

    std::cout << std::endl << "--- const test ---" << std::endl;
    const char c_x = 'a';
    const char c_y = 'k';
    const float f_x = 1.2231f;
    const float f_y = 9239.343f;


    ::printTest(c_x, c_y);
    ::printTest(f_x, f_y);
    ::printTest(4.242, 2.424);
    ::printTest(true, false);

    return 0;
}