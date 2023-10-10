/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:57 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/11 08:24:40 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->count = 1;
    return;
}

PhoneBook::~PhoneBook()
{
    return;
}

void check_input(std::string *input, int check)
{
    while (!getline(std::cin, *input) || (*input).empty())
    {
        std::cin.clear();
        clearerr(stdin);
        std::cout << "please fill this field" << std::endl;

        if (check == 1)
            std::cout << "FirstName : ";
        else if (check == 2)
            std::cout << "LastName : ";
        else if (check == 3)
            std::cout << "NickName : ";
        else if (check == 4)
            std::cout << "PhoneNumber : ";
        else if (check == 5)
            std::cout << "DarkestSecret : ";
    }
}

void PhoneBook::Add(void)
{
    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string darkest;

    if (this->count == 9)
    {
        for (int i = 0; i < 7; i++)
        {
            this->contact[i] = this->contact[i + 1];
        }
        this->count--;
    }
    
    std::cout << "FirstName : ";
    check_input(&first, 1);
    std::cout << "LastName : ";
    check_input(&last, 2);
    std::cout << "NickName : ";
    check_input(&nick, 3);
    std::cout << "PhoneNumber : ";
    check_input(&phone, 4);
    std::cout << "DarkestSecret : ";
    check_input(&darkest, 5);

    this->contact[this->count - 1].setFName(first);
    this->contact[this->count - 1].setLName(last);
    this->contact[this->count - 1].setNName(nick);
    this->contact[this->count - 1].setPNumber(phone);
    this->contact[this->count - 1].setDSecret(darkest);
    this->count++;
}

void PhoneBook::Search(void)
{

    std::cout << "count:: "<< this->count << std::endl;
    std::cout << std::endl;
    std::cout.width(10);
    std::cout << "index"
              << "|";
    std::cout.width(10);
    std::cout << "first name"
              << "|";
    std::cout.width(10);
    std::cout << "last name"
              << "|";
    std::cout.width(10);
    std::cout << "nickname"
              << "|" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    for (int i = 1; i < this->count; i++)
    {
        std::cout.width(10);
        std::cout << i << "|";
        this->contact[i - 1].showContact();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PhoneBook::Exit(void)
{
    return;
}