/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/14 04:46:35 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
    return ;
}

Contact::~Contact() {
    return ;
}

void    Contact::setFName(std::string first) {
    _f_name = first;
}

void    Contact::setLName(std::string last) {
    _l_name = last;
}

void    Contact::setNName(std::string nick) {
    _n_name = nick;
}

void    Contact::setPNumber(std::string phone) {
    _p_number = phone;
}

void    Contact::setDSecret(std::string darkest) {
    _d_secret = darkest;
}

std::string const&    Contact::getFName(void) const {
    return _f_name;
}

std::string const&    Contact::getLName(void) const {
    return _l_name;
}

std::string const&    Contact::getNName(void) const {
    return _n_name;
}

std::string const&    Contact::getPNumber(void) const {
    return _p_number;
}

std::string const&    Contact::getDSecret(void) const {
    return _d_secret;
}
