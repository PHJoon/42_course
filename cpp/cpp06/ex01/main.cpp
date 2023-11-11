/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:56:17 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/10 16:58:37 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data    x;
    Data    *tmp;
    uintptr_t y;

    y = Serializer::serialize(&x);

    std::cout << &x << std::endl;
    std::cout << y << std::endl;
    std::cout << tmp << std::endl;

    tmp = Serializer::deserialize(y);
    std::cout << tmp << std::endl;
    
    return 0;
}