/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:15:50 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/12 12:00:04 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av) {
    std::ifstream   file;
    std::string line;
    std::string content = "";

    if (ac != 4) {
        return 1;
    }
    file.open(av[1]);
    if (file.is_open()) {
        while (getline(file, line)) {
            content += line;
            if (!file.eof()) {
                content += "\n";
            }
        }
        std::cout << content << std::endl;

        std::string s1(av[2]);
        std::string s2(av[3]);
        

    } else {
        // error
    }
    return 0;
}