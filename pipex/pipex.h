/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 01:03:22 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/01/10 21:14:05 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>

typedef struct s_pipex
{
	int		fd[2];
	int		infile;
	int		outfile;
	char	**cmd1;
	char	**cmd2;
	char	**path;
}	t_pipex;

void	put_error(char *str);
void	put_perror(char *str, t_pipex *n_pipex, int res);
void	split_free(char **str);
void	free_pipex(t_pipex *n_pipex);
t_pipex	*init_pipex(void);
t_pipex	*get_path(t_pipex *n_pipex, char **envp);
t_pipex	*get_cmd(t_pipex *n_pipex, char *av2, char *av3);
t_pipex	*get_cmd_path(t_pipex *n_pipex, int *res);
t_pipex	*open_files(t_pipex *n_pipex, char *infile, char *outfile);
t_pipex	*close_all(t_pipex *n_pipex);

#endif
