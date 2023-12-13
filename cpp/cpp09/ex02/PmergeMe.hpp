/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/12/13 21:44:25 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <iomanip>
# include <algorithm>
# include <vector>
# include <list>
# include <set>
# include <string>
# include <cstdlib>
# include <limits>
# include <exception>
# include <ctime>

typedef std::vector<int> VEC;
typedef std::vector<int>::iterator VECITER;
typedef std::vector<std::pair<int, int> > VECPAIR;
typedef std::vector<std::pair<int, int> >::iterator VECPAIRITER;

typedef std::list<int> LIST;
typedef std::list<int>::iterator LISTITER;
typedef std::list<std::pair<int, int> > LISTPAIR;
typedef std::list<std::pair<int, int> >::iterator LISTPAIRITER;

class PmergeMe
{
    private:
        VEC _originVec;
        VEC _sortedVec;

        LIST    _originList;
        LIST    _sortedList;

        double  _vecDuration;
        double  _ListDuration;
        
        VEC _jacobsthalVec;
        LIST _jacobsthalList;

        PmergeMe(void);
        PmergeMe(const PmergeMe& src);
        ~PmergeMe(void);
        PmergeMe& operator=(PmergeMe const& rhs);
    public:
        PmergeMe(int ac, char **av);

        bool checkArgs(int ac, char **av);


        VEC jacobsthal(int n);

        int myLowerBound(VEC &v, int len, int target);
        int findFromPair(VECPAIR &pairVec, int target);
        VEC pendSortByMain(VEC &main, VECPAIR &pairVec);

        
        VEC fordJohnsonVector(VEC &v);
        

        void display(VEC &v);

        class   InvalidArgsException: public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "Error";
                }
                
        };

};


#endif