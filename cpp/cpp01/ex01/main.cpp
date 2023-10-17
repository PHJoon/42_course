/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:12:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 10:27:23 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    int n = 7;
    Zombie  *horde;
    
    horde = zombieHorde(n, "hyungjpa");
    for (int i = 0; i < n; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return (0);
}
