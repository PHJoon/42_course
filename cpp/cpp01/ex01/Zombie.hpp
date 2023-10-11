/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:13:05 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/11 11:15:37 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void    announce(void);
        
};

Zombie *zombieHorde(int N, std::string name);

#endif