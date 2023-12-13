/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:59:51 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/12/13 19:33:08 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cstdlib>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    // 인자 개수 체크
    if (ac < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe a(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
}