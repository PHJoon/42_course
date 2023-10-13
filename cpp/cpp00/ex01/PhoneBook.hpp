/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:59 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/14 05:33:08 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
    private:
            Contact _contact[8];
            int     _count;
    public:
            PhoneBook();
            ~PhoneBook();
            void    Add(void);
            void    Search(void);
            void    Exit(void);
};

#endif
