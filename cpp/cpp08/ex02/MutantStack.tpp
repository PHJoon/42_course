/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:38 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/22 07:50:49 by hyungjpa         ###   ########.fr       */
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
    (void)src;
}

template<typename T, class Container>
MutantStack<T, Container>::~MutantStack(void)
{
}

template<typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(MutantStack<T, Container> const& rhs)
{
    (void)rhs;
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
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cbegin(void) const
{
    return this->c.cbegin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cend(void) const
{
    return this->c.cend();
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

template<typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crbegin(void) const
{
    return this->c.crbegin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crend(void) const
{
    return this->c.crend();
}
