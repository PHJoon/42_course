/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:51:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 11:54:57 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    // std::cout << "MateriaSource Default Constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        _source[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    // std::cout << "MateriaSource Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        _source[i] = src._source[i]->clone();
    }
}

MateriaSource::~MateriaSource(void)
{
    // std::cout << "MateriaSource Destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete _source[i];
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs)
{
    // std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            _source[i] = rhs._source[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (_source[i] == NULL)
        {
            _source[i] = m;
            return ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_source[i]->getType() == type)
        {
            AMateria *ptr = _source[i]->clone();
            return ptr;
        }
    }
    return 0;
}