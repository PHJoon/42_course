/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwook <sungwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:42:59 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/15 10:33:51 by sungwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_read_file(char *argv)
{
	char	c;
	char	*buf;
	int		file_len;
	int		fd;

	file_len = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	while (0 < (read(fd, &c, sizeof(char))))
		file_len++;
	close(fd);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = (char *)malloc(sizeof(char) * (file_len + 1));
	if (!buf)
		return (0);
	read(fd, buf, file_len);
	buf[file_len] = '\0';
	close(fd);
	return (buf);
}

char	**ft_file_to_map2(char *buf, char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			i++;
		else
		{
			j = 0;
			while (buf[i + j] != '\n')
				j++;
			map[k] = (char *)malloc(sizeof(char) * (j + 2));
			if (!map[k])
				return (0);
			ft_strncpy(map[k], &buf[i], j);
			k++;
			i += j;
		}
	}
	return (map);
}

char	**ft_file_to_map(char *buf)
{
	char	**map;
	int		row_cnt;

	row_cnt = ft_get_row(buf);
	map = (char **)malloc(sizeof(char *) * (row_cnt + 1));
	if (!map)
		return (0);
	map = ft_file_to_map2(buf, map);
	return (map);
}
