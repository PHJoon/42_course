/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:48:09 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 15:15:21 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
# define Cure_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
    private:
    public:
        Cure(void);
        Cure(const Cure& src);
        virtual ~Cure(void);
        Cure& operator=(Cure const& rhs);

        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
};

#endif