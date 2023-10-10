/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:40:02 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/11 05:22:13 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    std::string input;
    PhoneBook   phonebook;

    std::cout << "This is PhoneBook Program" << std::endl;
    std::cout << "only accepts ADD, SEARCH and EXIT" << std::endl;
    while (true) {
        std::cout << "COMMAND > ";
        if (!getline(std::cin, input)) {
            std::cin.clear();
            clearerr(stdin);
            std::cout << std::endl;
            continue ;
        }
        if (input == "ADD") {
            phonebook.Add();
        } else if (input == "SEARCH") {
            phonebook.Search();
        } else if (input == "EXIT") {
            phonebook.Exit();
            break ;
        } else {
            std::cout << "invalid command! only accepts ADD, SEARCH and EXIT" << std::endl;
        }
    }
    return 0;
}