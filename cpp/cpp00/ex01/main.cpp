/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:40:02 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/05 15:08:35 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    
    std::string input;
    PhoneBook   phonebook;


    while (true) {
        std::getline(std::cin, input);

        if (input.compare("ADD") == 0) {
            
            phonebook.Add();

        } else if (input.compare("SEARCH") == 0) {
            phonebook.Search();
            
        } else if (input.compare("EXIT") == 0 ) {
            phonebook.Exit();
            break ;
        }
    }
    return 0;
}