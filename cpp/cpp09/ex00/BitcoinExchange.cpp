/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:37:08 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/12/14 09:25:11 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    getDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    (void)src;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
    (void)rhs;
    return *this;
}


float   BitcoinExchange::stringToFloat(const std::string &input)
{
    char    *end = NULL;
    float   ret = std::strtof(input.c_str(), &end);

    return ret;
}

bool    BitcoinExchange::checkValue(const std::string &input)
{
    if (input.find('.') == std::string::npos) {
        long long llTmp = std::atoll(input.c_str());
        if (llTmp < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            return false;
        } else if (llTmp > 1000) {
            std::cout << "Error: too large number." << std::endl;
            return false;
        }
        return true;
    } else {
        float fTmp = stringToFloat(input);
        if (fTmp < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            return false;
        } else if (fTmp > 1000) {
            std::cout << "Error: too large number." << std::endl;
            return false;
        }
        return true;
    }
}

void    BitcoinExchange::getDataBase(void)
{
    std::ifstream   dbFile;
    std::string     line;
    std::string     key;
    std::string     value;
    std::string::size_type idx;

    dbFile.open("data.csv");
    if (dbFile.is_open()) {
        getline(dbFile, line);
        while (getline(dbFile, line)) {
            idx = line.find(',');
            key = line.substr(0, idx);
            value = line.substr(idx + 1);
            _db.insert(std::make_pair(key, stringToFloat(value)));
        }
        dbFile.close();
    } else {
        std::cout << "Error: dbFile open error" << std::endl;
    }
}

void    BitcoinExchange::displayValue(std::string file)
{
    std::ifstream   infile;
    std::string     line;
    std::string     key;
    std::string     value;
    std::string::size_type idx;

    std::tm st_tm;

    infile.open(file.c_str());
    if (infile.is_open()) {
        getline(infile, line);

        while (getline(infile, line)) {
            idx = line.find(" | ");
            key = line.substr(0, idx);
            value = line.substr(idx + 3);

            if (strptime(key.c_str(), "%Y-%m-%d", &st_tm) == NULL) {
                std::cout << "Error: bad input => " << key << std::endl;
            } else if (!checkValue(value)) {
                continue ;
            } else {
                std::map<std::string, float>::iterator lb = _db.lower_bound(key);
                if (lb != _db.begin()) {
                    if (lb->first > key) lb--;
                    std::cout << key << " => " << value << " = " <<  stringToFloat(value) * (lb->second) << std::endl;
                } else {
                    std::cout << "Error: no data before => " << key << std::endl;                    
                }
            }
        }
    } else {
        std::cout << "Error: infile open error" << std::endl;
    }
}



