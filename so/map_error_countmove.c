/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_countmove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:28:51 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/24 14:07:48 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	print_moves(int i)
{
	write(1, "move ", 5);
	ft_putnbr(i);
	write(1, "\n", 1);
}

void	error(int n)
{
	if (n == 1)
	{
		write(1, "less or too many element\n", 26);
		exit(1);
	}
	if (n == 2)
	{
		write(1, "error no existing file", 22);
		exit(1);
	}
}

void	protect(int n)
{
	if (n < 0)
		error(2);
}

void	mlx_protection(void)
{
	write(1, "mlx error\n", 10);
	exit(1);
}
