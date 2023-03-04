/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 02:18:54 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/05 15:41:13 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nn;

	nn = n;
	if (nn < 0)
	{
		ft_putchar_fd('-', fd);
		nn *= -1;
	}
	if (nn < 10)
	{
		ft_putchar_fd((nn + 48), fd);
	}
	else
	{
		ft_putnbr_fd((nn / 10), fd);
		ft_putchar_fd((nn % 10) + 48, fd);
	}
}
