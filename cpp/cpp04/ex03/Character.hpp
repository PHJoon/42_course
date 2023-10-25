/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:51:15 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 15:40:11 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_HPP
# define Character_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
    private:
        std::string _name;
        std::string _inventory[4];
    public:
        Character(void);
        Character(const Character& src);
        virtual ~Character(void);
        Character& operator=(Character const& rhs);

        virtual std::string const &getName() const;
        virtual void equip(AMateria *m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);
};

#endif