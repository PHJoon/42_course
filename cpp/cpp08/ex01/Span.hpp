/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:04 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/16 13:05:57 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef span_HPP
# define span_HPP

template<typename T>
class span
{
    private:
        
    public:
        span(void);
        span(const span& src);
        virtual ~span(void);
        span& operator=(span const& rhs);

        void addNumber();
        shortestSpan();
        longestSpan();
};

#endif