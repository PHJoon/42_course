/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:59 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/09/04 15:56:54 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
            Contact phonebook[8];
            int     count;
    public:
            PhoneBook();
            ~PhoneBook();
            void    Add(void);
            void    Search(void);
            void    Exit(void);
};

#endif
