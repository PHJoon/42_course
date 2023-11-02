/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:13 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/02 16:58:31 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include <string>
# include <iostream>

class ScalarConverter
{
    private:
    public:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& src);
        virtual ~ScalarConverter(void);
        ScalarConverter& operator=(ScalarConverter const& rhs);

        char    toChar(const double input);
        int     toInt(const double input);
        float   toFloat(const double input);
        double  toDouble(const double input);

        void    convert(const std::string &str);
};

#endif