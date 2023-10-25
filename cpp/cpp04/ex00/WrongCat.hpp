/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:18:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 09:49:21 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
# define WrongCat_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    private:
    public:
        WrongCat(void);
        WrongCat(const WrongCat& src);
        virtual ~WrongCat(void);
        WrongCat& operator=(WrongCat const& rhs);

        const std::string &getType(void) const;

        void makeSound(void) const;
};

#endif