/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:40:05 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/01/05 13:42:58 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	put_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	put_perror(char *str, t_pipex *n_pipex, int res)
{
	if (res == 127)
		exit(127);
	perror(str);
	free_pipex(n_pipex);
	exit(EXIT_FAILURE);
}
