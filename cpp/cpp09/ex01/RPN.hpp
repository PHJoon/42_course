/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:17 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/28 10:53:14 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <cctype>
# include <string>

enum token {
    plus, minus, multiple, divide, operand, space, error
};

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN(void);
        RPN(const RPN& src);
        virtual ~RPN(void);
        RPN& operator=(RPN const& rhs);

        token   operationCheck(char c);
        int stackPop(void);
        bool calculate(const std::string &input);
        void execute(const std::string &input);
};

#endif