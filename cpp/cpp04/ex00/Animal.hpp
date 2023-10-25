/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:24:40 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 09:17:00 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_HPP
# define Animal_HPP

# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(const Animal& src);
        virtual ~Animal(void);
        Animal& operator=(Animal const& rhs);
        
        const std::string&    getType(void) const;

        virtual void    makeSound(void) const;
};

#endif