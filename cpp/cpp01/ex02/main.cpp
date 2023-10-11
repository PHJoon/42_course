/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:33:33 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/11 12:46:03 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "The memory address of the str       : " << &str << std::endl;
    std::cout << "The memory address of the stringPTR : " << &stringPTR << std::endl;
    std::cout << "The memory address of the stringREF : " << &stringREF << std::endl;
    
    std::cout << "The value of the str       : " << str << std::endl;
    std::cout << "The value of the stringPTR : " << stringPTR << std::endl;
    std::cout << "The value of the stringREF : " << stringREF << std::endl;
}