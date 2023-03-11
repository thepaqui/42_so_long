# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 09:25:02 by thepaqui          #+#    #+#              #
#    Updated: 2023/03/10 19:18:18 by thepaqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

INCLUDES_M= -Isrcs -Iutils -Iparsing -Ichecking -Iprocess

INCLUDES_B= -Ibonus/srcs -Ibonus/utils -Ibonus/parsing \
			-Ibonus/checking -Ibonus/process

ifdef WITH_BONUS
INCLUDES= $(INCLUDES_B) -Imlx
else
INCLUDES= $(INCLUDES_M) -Imlx
endif

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
		process/end.c \
		process/process.c \
		process/window.c \
		process/wall_detection.c \
		process/wall_linking.c \
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

SRCS_B= bonus/utils/text_bonus.c \
		bonus/utils/mem_bonus.c \
		bonus/utils/free_bonus.c \
		bonus/utils/free_other_bonus.c \
		bonus/utils/str_bonus.c \
		bonus/utils/numbers_bonus.c \
		bonus/utils/ft_atoi_base_bonus.c \
		bonus/utils/ft_split_bonus.c \
		bonus/utils/gnl/gnl_bonus.c \
		bonus/utils/gnl/gnl_utils_bonus.c \
		bonus/utils/error_bonus.c \
		bonus/parsing/parse_bonus.c \
		bonus/parsing/coins_bonus.c \
		bonus/parsing/palette_info_bonus.c \
		bonus/parsing/palette_bonus.c \
		bonus/parsing/color_keyword_bonus.c \
		bonus/parsing/spritesheet_bonus.c \
		bonus/parsing/xpm_bonus.c \
		bonus/checking/check_input_bonus.c \
		bonus/checking/check_map_bonus.c \
		bonus/checking/check_map_help_bonus.c \
		bonus/checking/check_xpm_bonus.c \
		bonus/process/end_bonus.c \
		bonus/process/secret_bonus.c \
		bonus/process/process_bonus.c \
		bonus/process/window_bonus.c \
		bonus/process/wall_detection_bonus.c \
		bonus/process/wall_linking_bonus.c \
		bonus/process/background_bonus.c \
		bonus/process/collection_bonus.c \
		bonus/process/collisions_bonus.c \
		bonus/process/projectile_bonus.c \
		bonus/process/projectile_collisions_bonus.c \
		bonus/process/player_bonus.c \
		bonus/process/ui_bonus.c \
		bonus/process/mouse_bonus.c \
		bonus/process/text_bonus.c \
		bonus/process/put_nbr_bonus.c \
		bonus/process/color_bonus.c \
		bonus/process/xpm_bonus.c \
		bonus/process/draw_bonus.c \
		bonus/process/image_bonus.c \
		bonus/process/key_handling_bonus.c \
		bonus/srcs/init_bonus.c \
		bonus/srcs/main_bonus.c

OBJS_M= $(SRCS_M:.c=.o)

OBJS_B= $(SRCS_B:.c=.o)

ifdef WITH_BONUS
OBJS= $(OBJS_B)
else
OBJS= $(OBJS_M)
endif

UP= "\033[A"

GREEN= "\033[32m"

PURPLE= "\033[35m"

WHITE= "\033[0m"

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	@$(CCBIN) -o $(NAME) $(OBJS)
ifdef WITH_BONUS
	@echo 'Compiled so_long with bonuses!'
else
	@echo 'Compiled so_long.'
endif

%.o: %.c 
	@printf $(UP)
	@echo $(GREEN) "Compiling: " $@ "                        " $(WHITE)
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
	@rm -f $(NAME)
	@echo 'Deleted so_long.'

mlxclean:
	@rm -f $(MLX)
	@echo 'Deleted mlx library.'

allclean: fclean mlxclean

re: fclean all

bonus:
	@make WITH_BONUS=1 all

rebonus: fclean bonus

.PHONY: all clean fclean mlxclean allclean re bonus rebonus
