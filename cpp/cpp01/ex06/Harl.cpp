/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:55:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 13:32:45 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    return ;
}

Harl::~Harl() {
    return ;
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable!" << std::endl;
    std::cout << "I want to speak to the manager now." << std::endl << std::endl;
}

void    Harl::exception(void) {
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void    Harl::complain(std::string level) {

    std::string complain_array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index = 5;
    for (int i = 0; i < 4; i++) {
        if (complain_array[i] == level) {
            index = i;
            break ;
        }
    }
    void    (Harl::*fp[5])(void) = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::exception
    };

    switch (index) {
        case 0:
            (this->*fp[0])();
        case 1:
            (this->*fp[1])();
        case 2:
            (this->*fp[2])();
        case 3:
            (this->*fp[3])();
            break ;
        default:
            (this->*fp[4])();        
    }
}