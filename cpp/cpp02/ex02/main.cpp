/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:18:56 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/20 10:00:42 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    

    std::cout << std::endl;
    std::cout << "-------------------------my test--------------------------" << std::endl;
    
    Fixed c(Fixed(5.05f) * Fixed(2));
    
    std::cout << Fixed::min(a, b) << std::endl;
    std::cout << Fixed::min(5.05f, 2) << std::endl;
    std::cout << Fixed::max(5.05f, 2) << std::endl;
    std::cout << c << std::endl;
    std::cout << ++c << std::endl;
    std::cout << c << std::endl;
    std::cout << c++ << std::endl;
    std::cout << c << std::endl;

    Fixed d(Fixed(5.05f) * Fixed(2));
    if (c != b) {
        std::cout << "c와 b는 다르다, ";
        if (c >= b) {
            std::cout << "c는 b보다 크거나 같다" << std::endl;
        } else {
            std::cout << "b는 c보다 크거나 같다" << std::endl;
        }
    } else {
        std::cout << "c와 b는 같다" << std::endl;
    }
    
    ++d;
    d++;

    if (c != d) {
        std::cout << "c와 d는 다르다, ";
        if (c >= d) {
            std::cout << "c는 d보다 크거나 같다" << std::endl;
        } else {
            std::cout << "d는 c보다 크거나 같다" << std::endl;
        }
    } else {
        std::cout << "c와 d는 같다" << std::endl;
    }
    
    std::cout << "----for문----" << std::endl;

    float ret = 0.0f;
    for (int i = 0; i < 10000; i++) {
        ret += 0.1f;
    }

    std::cout << ret << std::endl;

    return 0;
}
