/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:07:17 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 13:00:05 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICharater_HPP
# define ICharater_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const &getName() const = 0;
        virtual void equip(AMateria *m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter &target) = 0;
};

#endif
