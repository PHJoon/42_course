/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:53:44 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/01/06 12:41:00 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

char	*sum_args(char **cmd_split)
{
	char	*tmp_1;
	char	*tmp_2;
	char	*tmp_3;
	size_t	i;

	i = 2;
	tmp_1 = ft_strdup(cmd_split[1]);
	while (cmd_split[i])
	{
		tmp_2 = ft_strjoin(tmp_1, " ");
		tmp_3 = ft_strjoin(tmp_2, cmd_split[i]);
		free(tmp_1);
		free(tmp_2);
		tmp_1 = tmp_3;
		i++;
	}
	return (tmp_1);
}

char	*remove_quotes(char *cmd)
{
	size_t	s_quotes;
	size_t	b_quotes;
	char	*res;

	s_quotes = ft_strchr(cmd, '\'');
	b_quotes = ft_strchr(cmd, '\"');
	if (s_quotes < b_quotes)
		res = ft_strtrim(cmd, "'");
	else
		res = ft_strtrim(cmd, "\"");
	free(cmd);
	return (res);
}

char	**space_cmd(char *cmd)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * 2);
	if (!res)
		return (NULL);
	res[0] = cmd;
	res[1] = NULL;
	return (res);
}

char	**split_space(char *cmd)
{
	char	*tail;
	char	**cmd_split;
	char	**res;

	cmd_split = ft_split(cmd, ' ');
	if (cmd_split == NULL)
		return (NULL);
	if (ft_strchr(cmd, ' ') == ft_strlen(cmd))
		return (cmd_split);
	if (ft_strchr(cmd, '\'') == ft_strlen(cmd) && \
	ft_strchr(cmd, '\"') == ft_strlen(cmd))
		return (cmd_split);
	tail = sum_args(cmd_split);
	tail = remove_quotes(tail);
	res = (char **)malloc(sizeof(char *) * 3);
	if (!res)
	{
		split_free(cmd_split);
		return (NULL);
	}
	res[0] = ft_strdup(cmd_split[0]);
	res[1] = tail;
	res[2] = NULL;
	split_free(cmd_split);
	return (res);
}

t_pipex	*get_cmd(t_pipex *n_pipex, char *av2, char *av3)
{
	if (!access(av2, X_OK))
		n_pipex->cmd1 = space_cmd(av2);
	else
		n_pipex->cmd1 = split_space(av2);
	if (!access(av3, X_OK))
		n_pipex->cmd2 = space_cmd(av3);
	else
		n_pipex->cmd2 = split_space(av3);
	return (n_pipex);
}
