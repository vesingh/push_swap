/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:35:23 by vesingh           #+#    #+#             */
/*   Updated: 2019/07/23 14:48:23 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

/*
** ft_push_new_b: take the first element at the top stack a and puts
** at the top of stack b, this function mallocs for stack b if
** there isnt one.
*/

void		ft_push_new_b(j_list **head_a, j_list **head_b)
{
	j_list	*a_first;
	j_list	*b_first;

	a_first = *head_a;
	b_first = ft_init_list_b(a_first->n);
	*head_b = b_first;
	if (a_first->next == NULL)
	{
		ft_lst_del(head_a);
		return ;
	}
	*head_a = a_first->next;
	a_first = *head_a;
	free(a_first->prev);
}

/*
** ft_push_new_a: take the first element at the top of b stack and puts
** at the top of stack a, this function mallocs for stack a if
** there isnt one.
*/

void		ft_push_new_a(j_list **head_a, j_list **head_b)
{
	j_list	*a_first;
	j_list	*b_first;

	b_first = *head_b;
	a_first = ft_init_list_b(b_first->n);
	*head_a = a_first;
	if (b_first->next == NULL)
	{
		ft_lst_del(head_b);
		return ;
	}
	*head_b = b_first->next;
	b_first = *head_b;
	free(b_first->prev);
}

/*
** ft_push_to_a: take the first element at the top of b and put it at the top
** of a. Do nothing if b is empty.
*/

void		ft_push_to_a(j_list **head_a, j_list **head_b)
{
	j_list	*a_first;
	j_list	*b_first;

	if (*head_b == NULL)
		return ;
	if (*head_a == NULL)
		ft_push_new_a(head_a, head_b);
	else
	{
		b_first = *head_b;
		a_first = *head_a;
		*head_b = b_first->next;
		b_first->next = a_first;
		a_first->prev = b_first;
		*head_a = b_first;
		b_first->prev = NULL;
	}
}

/*
** ft_push_to_b: take the first element at the top of a and put it at the top
** of b. Do nothing if a is empty.
*/

void		ft_push_to_b(j_list **head_a, j_list **head_b)
{
	j_list	*a_first;
	j_list	*b_first;

	if (*head_a == NULL)
		return ;
	if (*head_b == NULL)
		ft_push_new_b(head_a, head_b);
	else
	{
		b_first = *head_b;
		a_first = *head_a;
		*head_a = a_first->next;
		a_first->next = b_first;
		b_first->prev = a_first;
		*head_b = a_first;
		a_first->prev = NULL;
	}
}