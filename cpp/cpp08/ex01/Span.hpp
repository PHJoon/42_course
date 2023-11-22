/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:04 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/22 09:00:01 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
# define Span_HPP

# include <algorithm>
# include <exception>
# include <vector>
# include <limits>
# include <utility>
# include <iostream>
# include <ctime>
# include <csdlib>

class Span
{
    private:
        Span(void);
        std::vector<int> _vector;
        unsigned int _vSize;
        unsigned int _idx;
        
    public:
        Span(unsigned int n);
        Span(const Span& src);
        virtual ~Span(void);
        Span& operator=(Span const& rhs);

        void addNumber(int n);
        unsigned int shortestSpan(void) const;
        unsigned int longestSpan(void) const;
        
        std::vector<int>::iterator getBegin(void);
        std::vector<int>::iterator getEnd(void);

        void fillSpan(std::vector<int>::iterator first, std::vector<int>::iterator last);

        void printAll(void) const;

        class FullSpanException: public std::exception
        {
            const char *what(void) const throw();
        };
        
        class NoSpanException: public std::exception
        {
            const char *what(void) const throw();
        };
        
        class NotEmptyException: public std::exception
        {
            const char *what(void) const throw();
        };
};

#endif