/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:34:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/16 12:59:45 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
typename T::iterator easyfind(T &container, int target)
{
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (ret == container.end()) {
        throw std::runtime_error("no target in container");
    } else return it;
}