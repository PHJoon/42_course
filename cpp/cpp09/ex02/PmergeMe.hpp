/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/29 16:35:43 by hyungjpa         ###   ########.fr       */
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

typedef std::vector<int>::iterator vecIter;
typedef std::list<int>::iterator listIter;

class PmergeMe
{
    private:
        std::vector<int>    _beforeVec;
        std::vector<int>    _afterVec;

        std::list<int>      _beforeList;
        std::list<int>      _afterList;

    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& src);
        ~PmergeMe(void);
        PmergeMe& operator=(PmergeMe const& rhs);



        
        void    execute(void);
        
};

#endif