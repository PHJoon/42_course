/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:36:13 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/12/30 02:05:07 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	parent_process(t_pipex *n_pipex, char **envp, int res)
{
	close(n_pipex->fd[1]);
	if (dup2(n_pipex->outfile, STDOUT_FILENO) == -1)
		put_perror("dup2 error!", n_pipex, res);
	if (dup2(n_pipex->fd[0], STDIN_FILENO) == -1)
		put_perror("dup2 error!", n_pipex, res);
	if (execve(n_pipex->cmd2[0], n_pipex->cmd2, envp) == -1)
		put_perror("execve error!", n_pipex, res);
}

void	do_fork(t_pipex *n_pipex, char **envp, int res)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
		put_perror("fork error!", n_pipex, res);
	else if (pid1 == 0)
	{
		close(n_pipex->fd[0]);
		if (dup2(n_pipex->infile, STDIN_FILENO) == -1)
			put_perror("dup2 error!", n_pipex, res);
		if (dup2(n_pipex->fd[1], STDOUT_FILENO) == -1)
			put_perror("dup2 error!", n_pipex, res);
		if (execve(n_pipex->cmd1[0], n_pipex->cmd1, envp) == -1)
			put_perror("execve error!", n_pipex, res);
	}
	else
	{
		waitpid(pid1, NULL, WNOHANG);
		parent_process(n_pipex, envp, res);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*n_pipex;
	int		res;

	res = 0;
	if (ac != 5)
		put_error("argument error!");
	n_pipex = init_pipex();
	n_pipex = open_files(n_pipex, av[1], av[4]);
	n_pipex = get_path(n_pipex, envp);
	n_pipex = get_cmd(n_pipex, av[2], av[3]);
	n_pipex = get_cmd_path(n_pipex, &res);
	if (pipe(n_pipex->fd) == -1)
		put_perror("pipe error!", n_pipex, res);
	do_fork(n_pipex, envp, res);
	n_pipex = close_all(n_pipex);
	free_pipex(n_pipex);
	return (0);
}
