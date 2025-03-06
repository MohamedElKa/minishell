# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 15:12:56 by abel-all          #+#    #+#              #
#    Updated: 2023/04/13 06:05:31 by abel-all         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell

CFLAGS	=  -Wall -Wextra -Werror 

LDFLAGS = -L/Users/abel-all/.brew/opt/readline/lib

HEADES	= 	minishell.h libft/libft.h

SRCS	= 	parsing/ft_lstnew_env.c parsing/env_exp_init.c parsing/ft_lstnew_tokens.c \
			parsing/tokenizer.c parsing/check_syntax.c parsing/ft_free.c parsing/tokenizer2.c \
			parsing/expander.c parsing/ft_lstnew_cmds.c parsing/parser.c minishell.c \
			parsing/parser2.c parsing/parser3.c parsing/parser4.c \
			executer.c exec_utils.c exec_funcs.c check_in_out.c exec_utils2.c exec_utils3.c\
			builtins/cd.c builtins/echo.c builtins/env.c builtins/pwd.c  builtins/exit.c choose_cmd.c \
			execute_builtins.c builtins/unset.c builtins/export.c builtins/check_existant.c builtins/final_export.c builtins/export_utils.c\
			add_export.c builtins/num_of_var.c builtins/change_value.c \
			execute_builtins.c builtins/unset.c builtins/export.c builtins/check_existant.c \
			add_export.c parsing/check_syntax_utils.c parsing/expander_utils.c parsing/parser5.c builtins/unset_utils.c

SRCSLIB =	libft/ft_tolower.c libft/ft_toupper.c libft/ft_atoi.c libft/ft_itoa.c \
			libft/ft_putnbr_fd.c libft/ft_strlcpy.c libft/ft_bzero.c libft/ft_memchr.c \
			libft/ft_putstr_fd.c libft/ft_strlen.c libft/ft_calloc.c libft/ft_memcmp.c \
			libft/ft_split.c libft/ft_strmapi.c libft/ft_isalnum.c libft/ft_memcpy.c \
			libft/ft_strchr.c libft/ft_strncmp.c libft/ft_isalpha.c libft/ft_memmove.c \
			libft/ft_strdup.c libft/ft_strnstr.c libft/ft_isascii.c libft/ft_memset.c \
			libft/ft_striteri.c libft/ft_strrchr.c libft/ft_isdigit.c \
			libft/ft_putchar_fd.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_isprint.c \
			libft/ft_putendl_fd.c libft/ft_strlcat.c libft/ft_substr.c libft/get_next_line.c\

OBJSLIB	= 	$(SRCSLIB:.c=.o)

OBJS	= 	$(SRCS:.c=.o)

all		: 	$(NAME)

$(NAME)	: 	$(OBJS) $(OBJSLIB)
	cc $(CFLAGS) $(LDFLAGS)  -lreadline  $^ -o $@

%.o		: 	%.c $(HEADES)
	cc $(CFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJS) $(OBJSLIB)

fclean 	: 	clean
	rm -rf $(NAME)

re		: 	fclean all

.PHONY	: 	fclean all clean re