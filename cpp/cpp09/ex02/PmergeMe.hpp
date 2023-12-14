/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/12/14 09:06:22 by hyungjpa         ###   ########.fr       */
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
        double  _listDuration;
        
        VEC _jacobsthalVec;
        LIST _jacobsthalList;

        PmergeMe(void);
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(PmergeMe const& rhs);
        
        bool checkArgs(int ac, char **av);

        void setOriginVec(int ac, char **av);
        void setOriginList(int ac, char **av);

        VEC jacobsthalVector(int n);
        int myLowerBoundVector(VEC &v, int len, int target);
        int findFromPairVector(VECPAIR &pairVec, int target);
        VEC pendSortByMainVector(VEC &main, VECPAIR &pairVec);
        VEC fordJohnsonVector(VEC &v);
        void displayVector(VEC &v);

        LIST jacobsthalList(int n);
        int myLowerBoundList(LIST &l, int len, int target);
        int findFromPairList(LISTPAIR &pairList, int target);
        LIST pendSortByMainList(LIST &main, LISTPAIR &pairList);
        LIST fordJohnsonList(LIST &l);
        void displayList(LIST &l);
    
    public:
        PmergeMe(int ac, char **av);
        ~PmergeMe(void);

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