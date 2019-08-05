/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:24:45 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/05 09:00:02 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

/*
** ft_2lst: for list of size 2
** if not sorted, sa, and return
*/

void		ft_2list(t_dlist **head_a, t_dlist **head_b)
{
	if (ft_check_sort(head_a, head_b) == 1)
		return ;
	ft_lst_swap(head_a);
	ft_putstr("sa");
	ft_putchar('\n');
	return ;
}
