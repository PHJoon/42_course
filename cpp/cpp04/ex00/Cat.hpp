/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:34:39 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 09:17:07 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat: public Animal
{
    private:
    public:
        Cat(void);
        Cat(const Cat& src);
        virtual ~Cat(void);
        Cat& operator=(Cat const& rhs);

        const std::string &getType(void) const;

        virtual void makeSound(void) const;
};

#endif