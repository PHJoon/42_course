/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:12:48 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 11:03:16 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Default Constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = "blah";
    }
}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = src._ideas[i];
    }
}

Brain::~Brain(void)
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain& Brain::operator=(Brain const& rhs)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
        {
            _ideas[i] = rhs._ideas[i];
        }
    }
    return *this;
}

void Brain::showIdeas(void) const
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << i << ": " << _ideas[i] << " ";
    }
    std::cout << std::endl;
}

void Brain::setIdeas(std::string idea)
{
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = idea;
    }
}
