/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:12:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/11 11:40:56 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie  *horde;
    int n = 7;

    horde = zombieHorde(n, "hyungjpa");
    for (int i = 0; i < n; i++) {
        horde[i].announce();
    }

    delete[] horde;
}
