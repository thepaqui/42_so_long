# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 09:25:02 by thepaqui          #+#    #+#              #
#    Updated: 2023/02/03 16:38:52 by thepaqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= so_long

INCLUDES= -I./srcs/ -I./utils/ -I./parsing/ -I./checking/# -I./mlx/

CC= cc -Wall -Wextra -Werror $(INCLUDES)

SRCS_M= utils/text.c \
		utils/mem.c \
		utils/str.c \
		utils/gnl/gnl.c \
		utils/gnl/gnl_utils.c \
		utils/error.c \
		parsing/parse.c \
		checking/check_input.c \
		checking/check_map.c \
		checking/check_map_help.c \
		srcs/main.c

SRCS_B=

OBJS_M= $(SRCS_M:.c=.o)

OBJS_B= $(SRCS_B:.c=.o)

ifdef WITH_BONUS
OBJS= $(OBJS_B)
else
OBJS= $(OBJS_M)
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
ifdef WITH_BONUS
	@echo 'Compiled so_long with bonuses!'
else
	@echo 'Compiled so_long.'
endif

%.o: %.c
	@$(CC) -o $@ -c $<

clean:
	@rm -f $(OBJS_M) $(OBJS_B)
	@echo 'Deleted all temporary files.'

fclean: clean
	@rm -f $(NAME)
	@echo 'Deleted so_long.'

re: fclean all

bonus:
	@make WITH_BONUS=1 all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
