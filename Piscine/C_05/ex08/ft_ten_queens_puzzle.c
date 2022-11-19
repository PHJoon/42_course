/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:22:45 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/07 16:53:47 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	print_board(int *board)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

int	check_board(int *board, int i)
{
	int	x;

	x = 0;
	while (x < i)
	{	
		if (board[x] == board[i])
			return (0);
		if (ft_abs(board[x] - board[i]) == ft_abs(x - i))
			return (0);
		x++;
	}
	return (1);
}

void	recur_queens(int *board, int i, int *cnt)
{
	int	j;

	j = 0;
	if (i == 10)
	{
		print_board(board);
		write(1, "\n", 1);
		(*cnt)++;
		return ;
	}
	while (j < 10)
	{
		board[i] = j;
		if (check_board(board, i))
			recur_queens(board, i + 1, cnt);
		j++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	cnt;

	cnt = 0;
	recur_queens(board, 0, &cnt);
	return (cnt);
}

int main()
{
	ft_ten_queens_puzzle();
}
