/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:11:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/18 21:03:47 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_HPP
# define iter_HPP

# include <iostream>
# include <cstddef>

template<typename T>
void iter(T *arrPtr, std::size_t len, void (*func)(T&))
{
    for (std::size_t i = 0; i < len; i++) {
        func(arrPtr[i]);
    }
}

template<typename T>
void iter(const T *arrPtr, std::size_t len, void (*func)(const T&))
{
    for (std::size_t i = 0; i < len; i++) {
        func(arrPtr[i]);
    }
}

template<typename T>
void printArr(const T &input)
{
    std::cout << input << " | ";
}

template<typename T>
void printArr(T &input)
{
    std::cout << input << " | ";
}

template<typename T>
void addSomething(T &input)
{
    input += 42;
}

template<typename T>
void addSomething(const T &input)
{
    std::cout << "const parameter => " << input << std::endl;
}

template<>
void addSomething(std::string &input)
{
    input += " 추가한 내용";
}

template<>
void addSomething(char &input)
{
    input += 1;
}

template<>
void addSomething(bool &input)
{
    input = !input;
}

#endif