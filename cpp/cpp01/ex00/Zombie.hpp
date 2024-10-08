/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 04:39:34 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 10:17:13 by hyungjpa         ###   ########.fr       */
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
        Zombie(std::string z_name);
        ~Zombie();
        void    announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);


#endif
