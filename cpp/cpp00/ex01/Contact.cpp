/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 06:05:24 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/14 07:15:39 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
    this->firstName = "";
    this->lastName = "";
    this->nickName = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
}

Contact::Contact(std::string first, std::string last, std::string nick, std::string phone, std::string darkest) {
    this->firstName = first;
    this->lastName = last;
    this->nickName = nick;
    this->phoneNumber = phone;
    this->darkestSecret = darkest;
}

Contact::~Contact() {

}

std::string Contact::getFirstName() {
    return (this->firstName);
}

std::string Contact::getLastName() {
    return (this->lastName);
}

std::string Contact::getNickName() {
    return (this->nickName);
}

std::string Contact::getPhoneNumber() {
    return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() {
    return (this->darkestSecret);
}