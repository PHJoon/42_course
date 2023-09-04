/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:54 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/09/04 14:46:57 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
    private:
            std::string first_name;
            std::string last_name;
            std::string nickname;
            std::string phone_number;
            std::string darkest_secret;
    public:
            Contact(std::string first, std::string last, std::string nick, std::string phone, std::string darkest);
            ~Contact();
            std::string get_first_name();
            std::string get_last_name();
            std::string get_nickname();
            std::string get_phone_number();
            std::string get_darkest_secret();
};

#endif