/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:19:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/01/10 21:21:53 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

t_pipex	*init_pipex(void)
{
	t_pipex	*n_pipex;

	n_pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!n_pipex)
		return (NULL);
	n_pipex->fd[0] = -1;
	n_pipex->fd[1] = -1;
	n_pipex->infile = -1;
	n_pipex->outfile = -1;
	n_pipex->cmd1 = NULL;
	n_pipex->cmd2 = NULL;
	n_pipex->path = NULL;
	return (n_pipex);
}
