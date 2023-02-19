# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 09:25:02 by thepaqui          #+#    #+#              #
#    Updated: 2023/02/19 22:40:29 by thepaqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

INCLUDES= -Isrcs -Iutils -Iparsing -Ichecking -Iprocess -Imlx

CC= cc -Wall -Wextra -Werror

CCOBJ= $(CC) $(INCLUDES)

CCBIN= $(CC) -L./ -lmlx -framework OpenGL -framework AppKit

MLX= libmlx.a

SRCS_M= utils/text.c \
		utils/mem.c \
		utils/free.c \
		utils/free_other.c \
		utils/str.c \
		utils/numbers.c \
		utils/ft_atoi_base.c \
		utils/ft_split.c \
		utils/gnl/gnl.c \
		utils/gnl/gnl_utils.c \
		utils/error.c \
		parsing/parse.c \
		parsing/coins.c \
		parsing/palette_info.c \
		parsing/palette.c \
		parsing/color_keyword.c \
		parsing/spritesheet.c \
		parsing/xpm.c \
		checking/check_input.c \
		checking/check_map.c \
		checking/check_map_help.c \
		checking/check_xpm.c \
		process/process.c \
		process/window.c \
		process/background.c \
		process/collection.c \
		process/collisions.c \
		process/player.c \
		process/text.c \
		process/put_nbr.c \
		process/color.c \
		process/xpm.c \
		process/draw.c \
		process/image.c \
		process/key_handling.c \
		srcs/init.c \
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

$(NAME): $(MLX) $(OBJS)
	@$(CCBIN) -o $(NAME) $(OBJS)
ifdef WITH_BONUS
	@echo 'Compiled so_long with bonuses!'
else
	@echo 'Compiled so_long.'
endif

%.o: %.c
	@$(CCOBJ) -o $@ -c $<

$(MLX): ./mlx/Makefile
	@make -C mlx
	@mv mlx/libmlx.a ./
	@make -C mlx clean
	@echo 'Compiled mlx library.'

clean:
	@rm -f $(OBJS_M) $(OBJS_B)
	@echo 'Deleted all temporary files.'

fclean: clean
	@rm -f $(MLX)
	@echo 'Deleted mlx library.'
	@rm -f $(NAME)
	@echo 'Deleted so_long.'

re: fclean all

bonus:
	@make WITH_BONUS=1 all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
