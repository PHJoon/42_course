/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:11:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/12 07:33:20 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_HPP
# define iter_HPP

# include <iostream>
# include <cstddef>

template<typename T>
void iter(T *arrPtr, std::size_t len, void func(T&))
{
    for (std::size_t i = 0; i < len; i++) {
        func(arrPtr[i]);
    }
}

template<typename T>
void printArr(T &input)
{
    std::cout << input << " | ";
}

#endif