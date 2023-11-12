/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:56:17 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/12 17:55:23 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data    x;
    Data    *tmp = NULL;
    uintptr_t y;

    x.value = 10;

    
    std::cout << "--- serialize ---"<< std::endl;
    y = Serializer::serialize(&x);

    std::cout << "x-Address: " << &x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "tmp-Adress: " << tmp << std::endl;

    std::cout << "--- deserialize ---"<< std::endl;
    tmp = Serializer::deserialize(y);
    std::cout << "tmp-Adress: " << tmp << std::endl;
    
    std::cout << "x-value: " << x.value << std::endl;
    std::cout << "tmp-value: " << tmp->value << std::endl;
    
    return 0;
}