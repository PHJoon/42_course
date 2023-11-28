/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/28 11:50:19 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <string>
# include <cstdlib>
# include <limits>

class PmergeMe
{
    private:
        std::vector<int>    _vector;
        std::list<int>  _list;       

        std::vector<int> _before;
        std::vector<int> _after;

    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& src);
        ~PmergeMe(void);
        PmergeMe& operator=(PmergeMe const& rhs);


        bool    setBefore(int ac, const char **argv);

        void    getBefore(void) const;
        void    getAfter(void) const;
        void    displayVectorTime(void) const;
        void    displayListTime(void) const;


        
        void    execute(void);
        
};

#endif