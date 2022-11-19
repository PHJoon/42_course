/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwook <sungwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:48:01 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/15 11:14:30 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

void	ft_putstr(char *str);
void	ft_write_result(char **result, int row);
char	*ft_strcpy(char *dest, char *src);
char	**ft_square_in_map(char **map, int row, int col);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_read_file(char *argv);
char	**ft_file_to_map(char *buf);
char	buf_fill(char *buf);
char	buf_obs(char *buf);
char	buf_empty(char *buf);
char	ft_fill(char **map);
char	ft_obs(char **map);
char	ft_empty(char **map);
int		valid_buf(char *buf);
int		valid_check(char **map);
int		get_col_len(char **map);
int		get_sqr_len(char **map);
int		ft_strlen(char *str);
int		ft_int_row(char **map);
int		ft_get_row(char *buf);
int		check_firstline_num(char **map);

#endif
