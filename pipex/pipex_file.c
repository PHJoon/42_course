/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:04:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/01/10 21:13:31 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

t_pipex	*open_files(t_pipex *n_pipex, char *infile, char *outfile)
{
	n_pipex->infile = open(infile, O_RDONLY);
	if (n_pipex->infile < 0)
		perror(infile);
	n_pipex->outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (n_pipex->outfile < 0)
		perror(outfile);
	return (n_pipex);
}

t_pipex	*close_all(t_pipex *n_pipex)
{
	close(n_pipex->infile);
	close(n_pipex->outfile);
	close(n_pipex->fd[0]);
	close(n_pipex->fd[1]);
	return (n_pipex);
}
