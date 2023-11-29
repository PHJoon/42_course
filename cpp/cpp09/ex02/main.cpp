/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:59:51 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/29 11:54:50 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cstdlib>

int main(int ac, char **av)
{
    // 인자 개수 체크
    if (ac < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // 인자 숫자 체크
    for (int i = 1; i < ac; i++) {
        std::string tmp(av[i]);
        for (std::size_t i = 0; i < tmp.length(); i++) {
            if (!std::isdigit(tmp[i])) {
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }
    }
    
    // 인자 양수, int 범위 체크 
    for (int i = 1; i < ac; i++) {
        long long tmp = std::atoll(av[i]);
        if (tmp <= 0 || tmp > std::numeric_limits<int>::max()) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }

    // 중복 처리 추가필요

    // 정렬
    
}