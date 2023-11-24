/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:37:01 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/24 16:05:58 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP


# include <iostream>
# include <algorithm>
# include <map>
# include <string>
# include <utility>
# include <fstream>
# include <cmath>
# include <ctime>


class BitcoinExchange
{
    private:
        std::map<std::string, float> _db;
        void    getDataBase(void);
        float   stringToFloat(const std::string &input);
        bool    checkValue(const std::string &input);

    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& src);
        ~BitcoinExchange(void);
        BitcoinExchange& operator=(BitcoinExchange const& rhs);

        void    displayValue(std::string file);

};

#endif