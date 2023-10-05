/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/05 15:00:28 by hyungjpa         ###   ########.fr       */
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
    this->f_name = first;
}

void    Contact::setLName(std::string last) {
    this->l_name = last;
}

void    Contact::setNName(std::string nick) {
    this->n_name = nick;
}

void    Contact::setPNumber(std::string phone) {
    this->p_number = phone;
}

void    Contact::setDSecret(std::string darkest) {
    this->d_secret = darkest;
}