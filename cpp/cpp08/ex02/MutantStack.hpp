/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/22 09:08:32 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <algorithm>
# include <stack>
# include <deque>

template<typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
        MutantStack(void);
        MutantStack(const MutantStack& src);
        ~MutantStack(void);
        MutantStack& operator=(MutantStack const& rhs);

        typedef typename Container::iterator iterator;
        iterator begin(void);
        iterator end(void);
        
        typedef typename Container::const_iterator const_iterator;
        const_iterator begin(void) const;
        const_iterator end(void) const;

        typedef typename Container::reverse_iterator reverse_iterator;
        reverse_iterator rbegin(void);
        reverse_iterator rend(void);

        typedef typename Container::const_reverse_iterator const_reverse_iterator;
        const_reverse_iterator rbegin(void) const;
        const_reverse_iterator rend(void) const;
};

# include "MutantStack.tpp"

#endif