/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:17 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/24 16:59:05 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <algorithm>
# include <iostream>
# include <stack>

class RPN
{
    private:
    public:
        RPN(void);
        RPN(const RPN& src);
        virtual ~RPN(void);
        RPN& operator=(RPN const& rhs);
};

#endif