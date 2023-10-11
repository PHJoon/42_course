/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:59 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/11 12:45:23 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstdio>
#include "Contact.hpp"

class PhoneBook {
    private:
            Contact contact[8];
            int     count;
    public:
            PhoneBook();
            ~PhoneBook();
            void    Add(void);
            void    Search(void);
            void    Exit(void);
};

#endif
