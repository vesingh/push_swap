/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:21:07 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/16 11:25:09 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"

# define SLOW 50000

/*
** t_env: environment struct to allow for flags (Bonus)
*/

typedef struct		s_env
{
	int				moves;
	int				vis;
	int				col;
	int				opp;
	int				slow;
}					t_env;

/*
** t_dlist: Struct to make doubly linked list for stacks A and B
** n holds value given in
** norm hold normalised value, or postion of number when in ascending order.
*/

typedef struct		s_dlist
{
	struct s_dlist	*prev;
	int				n;
	int				norm;
	struct s_dlist	*next;
}					t_dlist;

/*
** Error handling
*/

int					ft_error(t_dlist **head);
int					ft_usage(void);

/*
** Operations
*/

void				ft_lst_swap(t_dlist **head);
void				ft_ss_swap_ab(t_dlist **head_a, t_dlist **head_b);
void				ft_push_to_a(t_dlist **head_a, t_dlist **head_b);
void				ft_push_to_b(t_dlist **head_a, t_dlist **head_b);
void				ft_lst_rot(t_dlist **head);
void				ft_lst_rot_ab(t_dlist **head_a, t_dlist **head_b);
void				ft_lst_rev_rot(t_dlist **head);
void				ft_lst_rev_rot_ab(t_dlist **head_a, t_dlist **head_b);
void				ft_push_new_b(t_dlist **head_a, t_dlist **head_b);
void				ft_push_new_a(t_dlist **head_a, t_dlist **head_b);

/*
** Init list & reading ops functions
*/

int					ft_checkint(char **av);
t_dlist				*ft_newnode(char *av);
int					ft_fill_list(t_dlist **head, int ac, char **av, int a);
int					ft_init_list(int ac, char **av, t_dlist **head);
t_dlist				*ft_init_list_b(int a, int norm);
t_dlist				*ft_newnode_b(int a, int norm);
int					ft_check_sort(t_dlist **head_a, t_dlist **head_b);
int					ft_do_op(char *line, t_dlist **head_a, t_dlist **head_b);
void				ft_read_op(t_dlist **head_a, t_dlist **head_b,\
					t_env **flags);
void				ft_lst_del(t_dlist **head);
int					ft_check_dup(t_dlist **head);
int					ft_check_int_inner(char **av, int *i, int *j);
int					ft_fill_list_inner(char **av, int *a, int *i, \
					t_dlist **new_node);
void				ft_assign_newnode(t_dlist **head, t_dlist **current,\
					t_dlist **new_node);
long long			ft_atoll(char *str);
void				ft_end_check(t_dlist **head_a, t_dlist **head_b,\
					t_env **flags);

void				ft_addnorms_checker(t_dlist **head_a);
int					ft_lst_size(t_dlist **head);

/*
** Printing functions
*/

void				ft_print_stack(t_dlist **head);
void				ft_rev_print_stack(t_dlist **head);
void				ft_print_stackboth(t_dlist **head_a, t_dlist **head_b);
void				ft_print_stackcol(t_dlist **head_a, t_dlist **head_b);

/*
** Flags functions
*/

void				ft_flag_args(int *ac, char ***av, t_env **flags);
void				ft_check_flags(t_dlist **head_a, t_dlist **head_b,\
					t_env **flags);
void				ft_flag_moves(t_env **flags);
void				ft_flags_first(t_dlist **head_a, t_dlist **head_b,\
					t_env **flags);

#endif
