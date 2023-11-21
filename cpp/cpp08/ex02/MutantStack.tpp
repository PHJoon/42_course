/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:38 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/21 14:48:55 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& src)
{
    (void)src;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& rhs)
{
    (void)rhs;
    return *this;
}

template<typename T>
typename MutantStack<T>::container_type::iterator MutantStack<T>::begin(void)
{
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::container_type::const_iterator MutantStack<T>::cbegin(void);
{
    return this->c.cbegin();
}

template<typename T>
typename MutantStack<T>::container_type::reverse_iterator MutantStack<T>::rbegin(void);
{
    return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::container_type::const_reverse_iterator MutantStack<T>::crbegin(void);
{
    return this->c.crbegin();    
}

template<typename T>
typename MutantStack<T>::container_type::iterator MutantStack<T>::end(void);
{
    return this->c.end();
}

template<typename T>
typename MutantStack<T>::container_type::const_iterator MutantStack<T>::cend(void);
{
    return this->c.cend();    
}

template<typename T>
typename MutantStack<T>::container_type::reverse_iterator MutantStack<T>::rend(void);
{
    return this->c.rend();    
}

template<typename T>
typename MutantStack<T>::container_type::const_reverse_iterator MutantStack<T>::crend(void);
{
    return this->c.crend();
}
