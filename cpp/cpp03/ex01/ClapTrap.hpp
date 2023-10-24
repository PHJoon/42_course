/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:44:15 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/24 11:10:38 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hit_points;
        unsigned int _energy_points;
        unsigned int _attack_damage;
        
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& src);
        virtual ~ClapTrap(void);
        ClapTrap& operator=(ClapTrap const& rhs);

        virtual void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        std::string getName(void) const;
        unsigned int getHP(void) const;
        unsigned int getEP(void) const;
        unsigned int getAD(void) const;

        void    setName(std::string& name);
        void    setHP(unsigned int hp);
        void    setEP(unsigned int ep);
        void    setAD(unsigned int ad);
};

#endif