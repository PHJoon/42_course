/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:37:14 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 16:07:46 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor(void): _size(0)
{
    for (int i = 0; i < 4; i++)
    {
        _floor[i] = NULL;
    }
}

Floor::Floor(const Floor& src)
{
    _size = src._size;
    for (int i = 0; i < 4; i++)
    {
        *_floor[i] = *(src._floor[i]);
    }
}

Floor::~Floor(void)
{
    for (int i = 0; i < 4; i++)
    {
        delete _floor[i];
        _floor[i] = NULL;
    }
}

Floor& Floor::operator=(Floor const& rhs)
{
    if (this != &rhs)
    {
        _size = rhs._size;
        for (int i = 0; i < 4; i++)
        {
            *_floor[i] = *(rhs._floor[i]);
        }    
    }
    return *this;
}

void    Floor::putFloor(AMateria *m)
{
    if (_size == 4)
    {
        delete _floor[0];
        for (int i = 0; i < 3; i++)
        {
            _floor[i] = _floor[i + 1];
        }
        _size -= 1;
    }
    _floor[_size] = m;
    _size += 1;
}

void    Floor::showFloor(void) const
{
    for (int i = 0; i < _size; i++)
    {
        std::cout << i << " : " << _floor[i] << std::endl;
    }
}