/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:37:20 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/28 08:33:05 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange bE;

    if (ac != 2) {
        std::cout << "Error: could not open file." << std::endl;
    } else {
        bE.displayValue(av[1]);
    }
    return 0;
}
