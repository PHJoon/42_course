/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:54 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/05 14:58:55 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
    private:
            std::string f_name;
            std::string l_name;
            std::string n_name;
            std::string p_number;
            std::string d_secret;
    public:
            Contact();
            ~Contact();
            void    setFName(std::string first);
            void    setLName(std::string last);
            void    setNName(std::string nick);
            void    setPNumber(std::string phone);
            void    setDSecret(std::string darkest);


};

#endif