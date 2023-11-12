/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:13 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/12 17:31:48 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include <string>
# include <cstring>
# include <iostream>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& src);
        virtual ~ScalarConverter(void);
        ScalarConverter& operator=(ScalarConverter const& rhs);

        static char _char;
        static int  _int;
        static float _float;
        static double _double;

        static bool _displayableFlag;
        static bool _cImpossibleFlag;
        static bool _iImpossibleFlag;
        static bool _fImpossibleFlag;

        static bool _infFlag;

        static void convertChar(double n);
        static void convertInt(double n);
        static void convertFloat(double n);
        static void convertDouble(double n);

        static bool checkPseudoLiterals(double n);
        static void printAll(void);
        
    public :
        static void convert(const std::string &input);
};

#endif