/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:57 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/05 15:08:15 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    return ;
}

PhoneBook::~PhoneBook() {
    return ;
}

void PhoneBook::Add(void) {

    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string darkest;

    if (this->count == 8) {
        for (int i = 0; i < 7; i++) {
            this->contact[i] = this->contact[i + 1];
        }
        this->count--;
    }
    std::cout << "FirstName : ";
    std::cin >> first;
    this->contact[this->count].setFName(first);
    
    std::cout << "LastName : ";
    std::cin >> last;
    this->contact[this->count].setLName(last);
    
    std::cout << "NickName : ";
    std::cin >> nick;
    this->contact[this->count].setNName(nick);
    
    std::cout << "PhoneNumber : ";
    std::cin >> phone;
    this->contact[this->count].setPNumber(phone);
    
    std::cout << "DarkestSecret : ";
    std::cin >> darkest;
    this->contact[this->count].setDSecret(darkest);
    
    this->count++;
}

void PhoneBook::Search(void) {
    for (int i = 0; i < this->count; i++) {
        std::cout << i <<std::endl;
    }
}

void    PhoneBook::Exit(void) {
    return ;
}