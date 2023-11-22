/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:37:01 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/22 13:42:12 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

# include <algorithm>


class BitcoinExchange
{
    private:
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& src);
        virtual ~BitcoinExchange(void);
        BitcoinExchange& operator=(BitcoinExchange const& rhs);
};

#endif