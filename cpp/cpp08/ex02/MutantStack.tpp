/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:38 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/22 09:09:01 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T, class Container>
MutantStack<T, Container>::MutantStack(void)
{
}

template<typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& src)
{
    this->c = src.c;
}

template<typename T, class Container>
MutantStack<T, Container>::~MutantStack(void)
{
}

template<typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(MutantStack<T, Container> const& rhs)
{
    this->c = rhs.c;
    return *this;
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{
    return this->c.begin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{
    return this->c.end();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin(void) const
{
    return this->c.begin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end(void) const
{
    return this->c.end();
}

template<typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin(void)
{
    return this->c.rbegin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend(void)
{
    return this->c.rend();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin(void) const
{
    return this->c.rbegin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend(void) const
{
    return this->c.rend();
}

