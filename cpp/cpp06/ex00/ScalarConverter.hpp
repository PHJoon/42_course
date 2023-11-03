/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:13 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/03 16:15:01 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include <string>
# include <iostream>
# include <stdlib.h>

class ScalarConverter
{
    private:
        std::string  _input;
        double  _inputD;
        char    _c;
        int     _i;
        float   _f;
        double  _d;

        bool    _nFlag;
        bool    _pFlag;
    public:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& src);
        virtual ~ScalarConverter(void);
        ScalarConverter& operator=(ScalarConverter const& rhs);

        
        

        void    setValue(const char *str);

        void    convert(const char *str);
};

#endif