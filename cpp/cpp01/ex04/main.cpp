/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:15:50 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 13:31:20 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av) {
    std::ifstream   infile;
    std::ofstream   outfile;
    std::string line;
    std::string content = "";
    std::string ret = "";

    if (ac != 4) {
        std::cout << "arguments error" << std::endl;
        return (1);
    }
    
    infile.open(av[1]);
    if (infile.is_open()) {
        while (getline(infile, line)) {
            content += line;
            if (!infile.eof()) {
                content += "\n";
            }
        }
        infile.close();
    } else {
        std::cout << "infile open error" << std::endl;
        return (1);
    }
    
    std::string filename(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);


    for (size_t i = 0; i < content.length(); i++) {
        std::string temp = content.substr(i, s1.length());
        if (temp == s1) {
            ret += s2;
            i += s1.length() - 1;
        } else {
            ret += content[i];
        }
    }

    filename += ".replace";
    outfile.open(filename.c_str());
    if (outfile.is_open()) {
        outfile << ret;
        outfile.close();
    } else {
        std::cout << "outfile open error" << std::endl;
        return (1);
    }

    return (0);
}