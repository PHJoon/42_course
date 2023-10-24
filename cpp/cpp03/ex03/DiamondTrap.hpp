/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:22:03 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/24 13:57:52 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>
# include <string>

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& src);
        virtual ~DiamondTrap(void);
        DiamondTrap& operator=(DiamondTrap const& rhs);

        virtual void attack(const std::string &target);

        void whoAmI();
};

#endif