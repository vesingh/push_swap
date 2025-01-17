/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:44:58 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/12 10:39:24 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	a = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		a = a * -1;
	}
	if (a > 9)
		ft_putnbr_fd((a / 10), fd);
	a = (a % 10) + 48;
	ft_putchar_fd(a, fd);
}

void	ft_putnbr_col_fd(char *colour, int nbr, int fd)
{
	ft_putstr_fd(colour, fd);
	ft_putnbr_fd(nbr, fd);
	ft_putstr_fd(RESET, fd);
}
