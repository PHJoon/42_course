/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:55:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 03:31:00 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
    Harl    harl;
    
    if (ac != 2) {
        std::cout << "only accepts one parameter" << std::endl;
        return (1);
    }
    
    std::string str(av[1]);
    harl.complain(str);
    return (0);
}