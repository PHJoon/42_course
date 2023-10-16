/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:55:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/16 16:59:03 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    return ;
}

Harl::~Harl() {
    return ;
}

void    Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::exception(void) {
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}



void    Harl::complain(std::string level) {

    std::string complain_array[4] = {"debug", "info", "warning", "error"};
    int index = 0;
    for (int i = 0; i < 4; i++) {
        if (complain_array[i] == level) {
            index = i;
            break ;
        }
    }
    void    (Harl::*fp[4])(void) = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
    };

    for (int i = index; i < 4; i++) {
        (this->*fp[i])();
    }
}