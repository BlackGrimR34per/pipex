# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 13:41:35 by yosherau          #+#    #+#              #
#    Updated: 2025/04/20 16:56:48 by yosherau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=			pipex

CC			=			cc

CFLAGS		=			-Wall -Wextra -Werror -g3

RM			=			rm -rf

LIBFT_DIR	=			./libft

LIBFT		=			$(LIBFT_DIR)/libft.a

SRCS_DIR	=			./srcs

SRCS		=			$(wildcard $(SRCS_DIR)/*.c) pipex.c

OBJS_DIR	=			objs

OBJS		=			$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all:					$(NAME)

$(NAME):				$(OBJS) $(LIBFT)
						$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
						$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o:		$(SRCS_DIR)/%.c | $(OBJS_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/so_long.o:	pipex.c | $(OBJS_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
						mkdir -p $(OBJS_DIR)

clean:
						$(RM) $(OBJS_DIR) pipex.o
						$(MAKE) -C $(LIBFT_DIR) clean

fclean:					clean
						$(RM) $(NAME)
						$(MAKE) -C $(LIBFT_DIR) fclean

re:						fclean all

.PHONY:					fclean all re clean