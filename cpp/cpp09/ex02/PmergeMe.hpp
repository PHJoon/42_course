/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/12/13 18:12:30 by hyungjpa         ###   ########.fr       */
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
# include <functional>
# include <cmath>

typedef std::vector<int> VEC;
typedef std::vector<int>::iterator VECITER;
typedef std::vector<std::pair<int, int> > VECPAIR;
typedef std::vector<std::pair<int, int> >::iterator VECPAIRITER;

class PmergeMe
{
    private:
        VEC _originVec;
        VEC _sorteVec;

        VEC jacobsthalVec;

        PmergeMe(void);
    public:
        PmergeMe(int ac, char **av);
        PmergeMe(const PmergeMe& src);
        ~PmergeMe(void);
        PmergeMe& operator=(PmergeMe const& rhs);

        bool checkArgs(int ac, char **av);


        VEC jacobsthal(int n);

        int myLowerBound(VEC &v, int len, int target);
        int findFromPair(VECPAIR &pairVec, int target);
        VEC pendSortByMain(VEC &main, VECPAIR &pairVec);

        
        VEC fordJohnson(VEC &v);
        

        void display(VEC &v);
};

#endif