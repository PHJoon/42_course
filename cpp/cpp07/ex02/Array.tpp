/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:32:17 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/14 07:44:09 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(void): _array(NULL), _size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n)
{
}

template<typename T>
Array<T>::Array(const Array& src): _array(new T[src._size]), _size(src._size)
{
	for (unsigned int i = 0; i < src._size; i++)
	{
		this->_array[i] = src._array[i];
	}
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] _array;
	_array = NULL;
}

template<typename T>
Array<T>& Array<T>::operator=(Array const& rhs)
{
	if (this != &rhs)
	{
		delete[] this->_array;
		this->_array = new T[rhs._size];
		for (unsigned int i = 0; i < rhs._size; i++)
		{
			this->_array[i] = rhs._array[i];
		}
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= _size) throw OutOfBounds();
	return _array[idx];
}

template<typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
	if (idx >= _size) throw OutOfBounds();
	return _array[idx];
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return _size;
}
