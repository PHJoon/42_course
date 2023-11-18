/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:04 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/18 20:05:41 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef span_HPP
# define span_HPP

# include <algorithm>
# include <exception>
# include <vector>
# include <limits>

class Span
{
    private:
        span(void);
        std::vector<int> _vector;
        
    public:
        span(unsinged int n);
        span(const span& src);
        virtual ~span(void);
        span& operator=(span const& rhs);

        void addNumber(int n);
        const unsigned int shortestSpan(void) const;
        const unsigned int longestSpan(void) const;

        class FullSpanException: public std::exception
        {
            const char *what(void) const throw();
        }
        
        class NoSpanException: public std::exception
        {
            const char *what(void) const throw();
        }

        
};

#endif