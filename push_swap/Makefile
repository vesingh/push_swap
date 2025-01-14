# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 13:33:16 by vesingh           #+#    #+#              #
#    Updated: 2019/09/13 16:56:30 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH = push_swap
NAME = checker

C_DIR = ./checker_inc/
P_DIR = ./push_swap_inc/

LIBRARY_NAME = libft.a
LIBRARY_DIR = ./libft/
LIBRARY = $(addprefix $(LIBRARY_DIR), $(LIBRARY_NAME))

FLAGS = -Wall -Werror -Wextra

CHECK_FUNC =	checker.c\
				ft_lst_swap_init_b.c\
				ft_lst_rotate.c\
				ft_lst_push.c\
				ft_init_list_a.c\
				ft_operands.c\
				ft_check_ints.c\
				ft_error.c\
				ft_test.c\
				ft_norm_checker.c\
				ft_args.c\
				ft_printstacks.c\

PUSH_FUNC = 	push_swap.c\
				ft_sortlists.c\
				ft_simplesort.c\
				ft_push_ops1.c\
				ft_push_ops2.c\
				ft_push_ops3.c\
				ft_big_sort.c\
				ft_stack_ops.c\
				../checker_inc/ft_lst_swap_init_b.c\
				../checker_inc/ft_lst_rotate.c\
				../checker_inc/ft_lst_push.c\
				../checker_inc/ft_init_list_a.c\
				../checker_inc/ft_operands.c\
				../checker_inc/ft_check_ints.c\
				../checker_inc/ft_error.c\
				../checker_inc/ft_test.c\
				../checker_inc/ft_norm_checker.c\
				../checker_inc/ft_args.c\
				../checker_inc/ft_printstacks.c\

CHECK_FILES = $(addprefix $(C_DIR), $(CHECK_FUNC))
PUSH_FILES = $(addprefix $(P_DIR), $(PUSH_FUNC))

all: $(NAME) $(PUSH)

$(NAME): $(LIBRARY_NAME) 
	@gcc $(FLAGS) -o $(NAME) $(CHECK_FILES) $(LIBRARY) 
	@echo "Checker Built!"

$(PUSH): $(LIBRARY_NAME) 
	@gcc $(FLAGS) -o $(PUSH) $(PUSH_FILES) $(LIBRARY) 
	@echo "Push_Swap Built!"

$(LIBRARY_NAME):
	@make -C $(LIBRARY_DIR)
	@echo "Libft Built!"

clean:
	@echo "Removing Objects..."
	@make clean -C $(LIBRARY_DIR)
	@echo "Clean complete!"

fclean:
	@echo "Removing Objects..."
	@/bin/rm -f $(NAME) $(PUSH)
	@make fclean -C $(LIBRARY_DIR)
	@echo "Fclean complete!"

re: fclean all