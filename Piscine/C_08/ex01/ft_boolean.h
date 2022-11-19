/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:08:49 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/11 13:43:24 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN(x) ((x) % 2 == 0)
# define TRUE 1
# define FALSE 0
# define EVEN_MSG ("I have an even number of arguments.\n")
# define ODD_MSG ("I have an odd number of arguments.\n")
# define SUCCESS 0

typedef int	t_bool;

#endif
