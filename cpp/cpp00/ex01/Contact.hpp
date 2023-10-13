/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:54 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/14 04:46:39 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    private:
            std::string _f_name;
            std::string _l_name;
            std::string _n_name;
            std::string _p_number;
            std::string _d_secret;
    public:
            Contact();
            ~Contact();
            void    setFName(std::string first);
            void    setLName(std::string last);
            void    setNName(std::string nick);
            void    setPNumber(std::string phone);
            void    setDSecret(std::string darkest);
            std::string const&    getFName(void) const;
            std::string const&    getLName(void) const;
            std::string const&    getNName(void) const;
            std::string const&    getPNumber(void) const;
            std::string const&    getDSecret(void) const;          
};

#endif