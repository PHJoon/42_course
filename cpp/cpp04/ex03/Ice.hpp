/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:48:11 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 15:16:05 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ice_HPP
# define Ice_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{
    private:
    public:
        Ice(void);
        Ice(const Ice& src);
        virtual ~Ice(void);
        Ice& operator=(Ice const& rhs);

        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
};

#endif