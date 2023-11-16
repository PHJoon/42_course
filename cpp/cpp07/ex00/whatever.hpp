/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:00:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/16 10:30:43 by hyungjpa         ###   ########.fr       */
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
    if (a < b) return a;
    else return b;
}

template<typename T>
T &max(T &a, T &b)
{
    if (a > b) return a;
    else return b;
}

template<typename T>
void    printTest(T& a, T& b)
{
    std::cout << std::boolalpha;
    std::cout << "before swap = "; 
    std::cout << a << " / " << b << std::endl;
    ::swap(a, b);
    std::cout << "after swap = ";
    std::cout << a << " / " << b << std::endl;
    std::cout << "min : " << ::min(a, b) << std::endl;
    std::cout << "max : " << ::max(a, b) << std::endl << std::endl;
}

template<typename T>
void    printTest(const T& a, const T& b)
{
    std::cout << std::boolalpha;
    std::cout << a << " / " << b << std::endl;
    std::cout << "min : " << ::min(a, b) << std::endl;
    std::cout << "max : " << ::max(a, b) << std::endl << std::endl;
}

#endif