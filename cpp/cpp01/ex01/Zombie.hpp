/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:13:05 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 10:23:04 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();
        void    announce(void);
        void    setName(std::string name);
        
};

Zombie *zombieHorde(int N, std::string name);

#endif