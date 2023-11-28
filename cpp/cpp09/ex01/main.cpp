/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:22 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/28 09:39:52 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
    RPN rpn;
    if (ac != 2) {
        std::cout << "Error" << std::endl;
    } else {
        rpn.execute(std::string(av[1]));
    }
    return 0;
}