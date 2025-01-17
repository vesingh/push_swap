/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 09:04:05 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/13 16:53:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

/*
** ft_is descending: checks if stack is sorted in descending order
** Will be used for stack be, before pushing all back to stack a.
*/

int			ft_is_descending(t_dlist **head)
{
	t_dlist	*current;
	t_dlist	*second;

	current = *head;
	second = current->next;
	while (second != NULL)
	{
		if (second->n > current->n)
			return (0);
		current = current->next;
		second = second->next;
	}
	return (1);
}

/*
** ft_is_ascending: checks if the list given is in ascending order
** differs from ft_check_sort in that it diregards whatever is in the
** stack. eg. we usually check order of stack A, this disregards whether
** stack B is empty or not.
*/

int			ft_is_ascending(t_dlist **head)
{
	t_dlist	*current;
	t_dlist	*second;

	current = *head;
	second = current->next;
	while (second != NULL)
	{
		if (second->n < current->n)
			return (0);
		current = current->next;
		second = second->next;
	}
	return (1);
}

/*
** ft_small_to_top: used more for sorting 3list.
** calls ft_smallest to find smallest node.
** applies "ra" until the smallest number is at the top of the stack
** if stack A is now sorted in ascending it returns 1. else it pushes that
** smallest number to the top of stack B by calling "pb"
*/

int			ft_small_to_top(t_dlist **head_a, t_dlist **head_b, t_env **flags)
{
	t_dlist	*small;

	small = ft_smallest(head_a);
	while (small->n != (*head_a)->n)
	{
		ft_push_rota(head_a, head_b, flags);
	}
	if (ft_is_ascending(head_a) == 1)
		return (1);
	ft_push_pb(head_a, head_b, flags);
	return (0);
}

/*
** ft_sortsize: calls ft_lst_size to get the size of list of int arguments
** that were generated. It then calls the relevant sorting function
** dependant on that list size
*/

void		ft_sortsize(t_dlist **head_a, t_dlist **head_b, t_env **flags)
{
	int	lstlen;

	lstlen = ft_lst_size(head_a);
	if (lstlen == 0)
		ft_error(head_a);
	else if (lstlen == 1)
		return ;
	else if (lstlen == 2)
		ft_2list(head_a, head_b, flags);
	else if (lstlen == 3)
		ft_3list(head_a, head_b, flags);
	else if (lstlen <= 5)
		ft_5list(head_a, head_b, flags);
	else
		ft_big_list(head_a, head_b, lstlen, flags);
	ft_flag_moves(flags);
}
