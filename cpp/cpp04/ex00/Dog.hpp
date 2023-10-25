/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:34:44 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 09:17:13 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog: public Animal
{
    private:
    public:
        Dog(void);
        Dog(const Dog& src);
        virtual ~Dog(void);
        Dog& operator=(Dog const& rhs);

        const std::string &getType(void) const;

        virtual void    makeSound(void) const;
};

#endif