/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:34:25 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/16 12:59:32 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef easyfind_HPP
# define easyfind_HPP

# include <algorithm>
# include <exception>

template<typename T>
typename T::iterator easyfind(T &container, int target);

# include "easyfind.tpp"

#endif