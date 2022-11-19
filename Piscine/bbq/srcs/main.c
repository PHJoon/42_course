/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwook <sungwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:28:23 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/15 11:18:57 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_use_av(char *argv)
{
	char	*buf;
	char	**map;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	buf = ft_read_file(argv);
	if (!valid_buf(buf))
		return ;
	map = ft_file_to_map(buf);
	free(buf);
	if (!valid_check(map))
		return ;
	ft_write_result(ft_square_in_map(map, ft_int_row(map), \
		get_col_len(map)), ft_int_row(map));
	k = ft_int_row(map) + 1;
	while (j < k)
	{
		free(map[j]);
		j++;
	}
	free(map);
}

void	ft_use_av2(char *buf)
{
	char	**map;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!valid_buf(buf))
		return ;
	map = ft_file_to_map(buf);
	if (!valid_check(map))
		return ;
	ft_write_result(ft_square_in_map(map, ft_int_row(map), \
		get_col_len(map)), ft_int_row(map));
	k = ft_int_row(map) + 1;
	while (j < k)
	{
		free(map[j]);
		j++;
	}
	free(map);
}

void	ft_no_input(void)
{
	char	arr[1024];
	char	*tmp;
	int		cnt;

	cnt = 0;
	tmp = arr;
	while (1)
	{
		if (!read(0, tmp, 1))
			break ;
		cnt++;
		tmp++;
	}
	ft_use_av2(arr);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		ft_no_input();
	else
	{
		while (i < argc)
		{
			ft_use_av(argv[i]);
			if (i != argc - 1)
				ft_putstr("\n");
			i++;
		}
	}
	return (0);
}
