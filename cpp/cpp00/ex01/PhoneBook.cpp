/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:57 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/14 06:01:10 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _count(1) {
    return;
}

PhoneBook::~PhoneBook() {
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

    if (_count == 9)
    {
        for (int i = 0; i < 7; i++)
        {
            _contact[i] = _contact[i + 1];
        }
        _count--;
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

    _contact[_count - 1].setFName(first);
    _contact[_count - 1].setLName(last);
    _contact[_count - 1].setNName(nick);
    _contact[_count - 1].setPNumber(phone);
    _contact[_count - 1].setDSecret(darkest);
    _count++;
}

void truncate_text(std::string const& text)
{
    if (text.length() > 9)
    {
        std::cout << std::setw(10) << text.substr(0, 9) + "." << "|";
    }
    else {
        std::cout << std::setw(10) << text << "|";
    }
}

void PhoneBook::Search(void)
{
    std::cout << std::endl;
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << "|" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    for (int i = 1; i < _count; i++)
    {
        std::cout.width(10);
        std::cout << i << "|";

        truncate_text(_contact[i - 1].getFName());
        truncate_text(_contact[i - 1].getLName());
        truncate_text(_contact[i - 1].getNName());

        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::string input;
    while (true) {
        std::cout << "index : ";
        if (!getline(std::cin, input) || input.empty()) {
            std::cin.clear();
            clearerr(stdin);
            std::cout << "invalid index" << std::endl;
            if (_count == 1) {
                std::cout << "there is no contact in phonebook" << std::endl;
            }
            break ;
        }
        
        std::istringstream iss(input);
        int number;

        if (_count == 1) {
            std::cout << "invalid index" << std::endl;
            std::cout << "there is no contact in phonebook" << std::endl;
        } else {
            if (!(iss >> number)) {
                std::cout << "invalid index" << std::endl;
            } else {
                if (number > 0 && number < _count) {
                    std::cout << "First Name : " << _contact[number - 1].getFName() << std::endl;
                    std::cout << "Last Name : " << _contact[number - 1].getLName() << std::endl;
                    std::cout << "Nick Name : " << _contact[number - 1].getNName() << std::endl;
                    std::cout << "Phone Number : " << _contact[number - 1].getPNumber() << std::endl;
                    std::cout << "Darkest Secret : " << _contact[number - 1].getDSecret() << std::endl;
                } else {
                    std::cout << "invalid index" << std::endl;
                }
            }
        }
        break ;
    }
}



void PhoneBook::Exit(void)
{
    return;
}