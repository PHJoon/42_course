/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/09/04 15:53:46 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string first, std::string last, std::string nick, std::string phone, std::string darkest) {
    this->first_name = first;
    this->last_name = last;
    this->nickname = nick;
    this->phone_number = phone;
    this->darkest_secret = darkest;
}

Contact::~Contact() {
    
}

std::string Contact::get_first_name() {
    return (this->first_name);
}
std::string Contact::get_last_name() {
    return (this->last_name);
}
std::string Contact::get_nickname() {
    return (this->nickname);
}
std::string Contact::get_phone_number() {
    return (this->phone_number);
}
std::string Contact::get_darkest_secret() {
    return (this->darkest_secret);
}