/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:32:40 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 03:19:34 by hyungjpa         ###   ########.fr       */
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
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
}

void    Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl; 
    std::cout << "You didn't put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable!" << std::endl;
    std::cout << "I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level) {

    void    (Harl::*fp[4])(void) = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
    };
    
    std::string complain_array[4] = {"debug", "info", "warning", "error"};
    
    for (int i = 0; i < 4; i++) {
        if (complain_array[i] == level) {
            (this->*fp[i])();
            std::cout << std::endl;
            return ;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    std::cout << std::endl;
    return ;
}