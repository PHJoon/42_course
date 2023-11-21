/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/21 14:48:49 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <algorithm>
# include <stack>


template<typename T>
class MutantStack: public std::stack<T>
{

    public:
        MutantStack(void);
        MutantStack(const MutantStack& src);
        ~MutantStack(void);
        MutantStack& operator=(MutantStack const& rhs);

        // typedef typename MutantStack<T>::container_type::iterator iterator;
        // iterator begin(void);

        typename MutantStack<T>::container_type::iterator begin(void);
        typename MutantStack<T>::container_type::const_iterator cbegin(void);
        typename MutantStack<T>::container_type::reverse_iterator rbegin(void);
        typename MutantStack<T>::container_type::const_reverse_iterator crbegin(void);
        
        typename MutantStack<T>::container_type::iterator end(void);
        typename MutantStack<T>::container_type::const_iterator cend(void);
        typename MutantStack<T>::container_type::reverse_iterator rend(void);
        typename MutantStack<T>::container_type::const_reverse_iterator crend(void);

};

# include "MutantStack.tpp"

#endif