/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:11:43 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/24 11:13:44 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include "ClapTrap.hpp"

# include <iostream>
# include <string>

class ScavTrap: public ClapTrap
{
    private:
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& src);
        virtual ~ScavTrap(void);
        ScavTrap& operator=(ScavTrap const& rhs);

        virtual void attack(const std::string &target);
        void    guardGate(void);
};

#endif