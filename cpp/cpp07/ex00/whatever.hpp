/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:00:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/12 07:07:40 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef whatever_HPP
# define whatever_HPP

template<typename T>
void    swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
T &min(T &a, T &b)
{
    if (a > b) return b;
    else return a;
}

template<typename T>
T &max(T &a, T &b)
{
    if (a > b) return a;
    else return b;
}

#endif