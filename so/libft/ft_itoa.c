/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:09:59 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/04 17:26:09 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intcounter(int number)
{
	int	lentgh;

	lentgh = 0;
	if (number <= 0)
		lentgh++;
	while (number != 0)
	{
		lentgh++;
		number = number / 10;
	}
	return (lentgh);
}

char	*ft_itoa(int n)
{
	char		*myres;
	int			lentgh;
	long long	number;

	lentgh = ft_intcounter(n);
	number = (long)n;
	myres = (char *)malloc((lentgh + 1) * sizeof(char));
	if (!myres)
		return (0);
	if (number < 0)
	{
		myres[0] = '-';
		number *= -1;
	}
	if (number == 0)
		myres[0] = '0';
	myres[lentgh--] = '\0';
	while (number)
	{
		myres[lentgh--] = (number % 10) + '0';
		number /= 10;
	}
	return (myres);
}
