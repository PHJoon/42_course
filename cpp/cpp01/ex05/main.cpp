/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:32:32 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/17 03:16:07 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
    Harl    harl;

    for (int i = 0; i < 2; i++) {
        harl.complain("debug");
        harl.complain("info");
        harl.complain("warning");
        harl.complain("error");
    }
    harl.complain("complain");
    return (0);
}