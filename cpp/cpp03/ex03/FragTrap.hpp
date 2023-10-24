/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:28:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/24 13:54:21 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& src);
        virtual ~FragTrap(void);
        FragTrap& operator=(FragTrap const& rhs);

        virtual void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif