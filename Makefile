# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 12:58:08 by jiheo             #+#    #+#              #
#    Updated: 2022/07/24 11:57:50 by jiheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME = minishell
CC = gcc
FLAG = -Wall -Wextra -Werror

SRCS = minishell.c other/env_utils.c other/getpaths.c other/cd.c other/echo.c other/env.c other/exit.c \
other/export.c other/pwd.c other/unset.c other/pipe.c other/redir.c other/init.c other/pipe_command.c other/execute.c \
other/signal.c other/heredoc.c \
tree/tree.c tree/utils.c tree/find.c tree/advlst.c tree/destroy.c tree/extract.c tree/new_data.c \
tree/strings.c tree/translate.c tree/check.c tree/queue.c tree/error.c tree/parse.c

OBJS = $(SRCS:.c=.o)

LIBFT = ohw
LIBFT_DIR = libohw
LIBFT_INC = $(LIBFT_DIR)/include

RL = readline
RL_DIR = /opt/homebrew/opt/readline
RL_LIB = $(RL_DIR)/lib
RL_INC = $(RL_DIR)/include

INC = -I. -I$(RL_INC) -I$(LIBFT_INC)
LIB = -l$(LIBFT) -l$(RL) -L$(RL_LIB) -L$(LIBFT_DIR)

%.o: %.c
	$(CC) -c $(FLAG) $(INC) $< -o $@

$(PROJECT_NAME): compilelib $(OBJS)
	$(CC) $(FLAG) $(OBJS) $(LIB) -o $(PROJECT_NAME)

all: $(PROJECT_NAME)

compilelib:
	cd $(LIBFT_DIR) && make
	cd ..

clean:
	rm -rf *.o **/*.o

fclean: clean
	rm $(PROJECT_NAME)

re: fclean
	make all

PHONY: all clean fclean re