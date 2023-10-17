/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:02:23 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 10:12:04 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie  zombie_a = Zombie("Apple");
    zombie_a.announce();

    Zombie *zombie_b = newZombie("Banana");
    zombie_b->announce();
    delete zombie_b;

    randomChump("Cat");
    return (0);
}