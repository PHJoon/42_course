/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:07 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/01/05 14:04:36 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

t_pipex	*get_path(t_pipex *n_pipex, char **envp)
{
	size_t	i;
	char	**path;

	i = 0;
	while (envp != 0)
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != 0)
			break ;
		i++;
	}
	path = ft_split(envp[i] + 5, ':');
	n_pipex->path = path;
	return (n_pipex);
}

void	get_cmd1_path(t_pipex *n_pipex, char **path, char **cmd, int *res)
{
	size_t		i;
	char		*path_tmp;
	char		*acc_tmp;

	i = 0;
	if (!access(cmd[0], X_OK))
		return ;
	while (path[i])
	{
		path_tmp = ft_strjoin(path[i], "/");
		acc_tmp = ft_strjoin(path_tmp, cmd[0]);
		free(path_tmp);
		if (!access(acc_tmp, X_OK))
		{
			free(cmd[0]);
			n_pipex->cmd1[0] = acc_tmp;
			return ;
		}
		free(acc_tmp);
		i++;
	}
	*res = 127;
	write(2, "command not found!\n", 19);
}

void	get_cmd2_path(t_pipex *n_pipex, char **path, char **cmd, int *res)
{
	size_t		i;
	char		*path_tmp;
	char		*acc_tmp;

	i = 0;
	if (!access(cmd[0], X_OK))
		return ;
	while (path[i])
	{
		path_tmp = ft_strjoin(path[i], "/");
		acc_tmp = ft_strjoin(path_tmp, cmd[0]);
		free(path_tmp);
		if (!access(acc_tmp, X_OK))
		{
			free(cmd[0]);
			n_pipex->cmd2[0] = acc_tmp;
			return ;
		}
		free(acc_tmp);
		i++;
	}
	*res = 127;
	write(2, "command not found!\n", 19);
}

t_pipex	*get_cmd_path(t_pipex *n_pipex, int *res)
{
	get_cmd1_path(n_pipex, n_pipex->path, n_pipex->cmd1, res);
	get_cmd2_path(n_pipex, n_pipex->path, n_pipex->cmd2, res);
	return (n_pipex);
}
