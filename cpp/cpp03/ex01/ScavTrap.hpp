/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:11:43 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/21 18:09:46 by hyungjpa         ###   ########.fr       */
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
        ScavTrap(const ScavTrap& src);
        virtual ~ScavTrap(void);
        ScavTrap& operator=(ScavTrap const& rhs);
        
        ScavTrap(std::string name);
        void    guardGate(void);
};

#endif