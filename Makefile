# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 18:32:51 by cjackows          #+#    #+#              #
#    Updated: 2023/06/28 19:45:21 by cjackows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			=	\033[38;5;160m
RED_B		=	\033[48;5;160m
DELETED		=	\033[48;5;160m[DELETED]\033[0m
GREEN		=	\033[38;5;40m
GREEN_B		=	\033[48;5;40m
COMPILATION	=	\033[48;5;40m[COMPILATION]\033[0m $(GREEN)
BLUE		=	\033[38;5;123m
BLUE_B		=	\033[48;5;39m
INFO		=	\033[48;5;39m[INFORMATION]\033[0m $(BLUE)
RESET		=	\033[0m


PROGRESS_WIDTH = 20
PROGRESS_DONE_CHAR = 🟩
PROGRESS_TODO_CHAR = ⬜️
CURRENT_PROGRESS = 0
TOTAL_PROGRESS = $(words $(OBJ))

NAME		=	cub3D
CC			=	cc
CFLAGS		=	-O3 -Wall -Wextra -Werror -g

LIBFT		=	./inc/42-libft/libft.a
LIBFT_DIR	=	./inc/42-libft/
HDRS_DIR	=	./inc/
OBJ_DIR		=	./obj

ifeq ($(shell uname), Linux)
	OS				=	Linux
	MLX_DIR 		=	./inc/mlx/mlx_linux
	MLX_LIB			=	$(MLX_DIR)/libmlx.a
	MLX_FLAGS		=	-lXext -lX11 -lm -lz
	DEFINE_FLAGS 	= 	-DKEY_ESC=65307 -DKEY_LEFT=65361 -DKEY_RIGHT=65363 \
						-DKEY_W=119 -DKEY_A=97 -DKEY_S=115 -DKEY_D=100 -DKEYS

else
	OS				=	Mac
	MLX_DIR 		=	./inc/mlx/mlx_mac
	MLX_LIB			=	$(MLX_DIR)/libmlx.a
	MLX_FLAGS		=	-framework OpenGL -framework AppKit -lz
	DEFINE_FLAGS 	= 	-DKEY_ESC=53 -DKEY_LEFT=123 -DKEY_RIGHT=124 \
						-DKEY_W=13 -DKEY_A=0 -DKEY_S=1 -DKEY_D=2 -DKEYS
endif

SRC_DIR		=	./src

SRC			=	$(SRC_DIR)/_main.c \
				$(SRC_DIR)/initialization/initialization.c \
				$(SRC_DIR)/initialization/textures_init.c \
				$(SRC_DIR)/miscellaneous/exit.c \
				$(SRC_DIR)/miscellaneous/helpers.c \
				$(SRC_DIR)/miscellaneous/player_control.c \
				$(SRC_DIR)/miscellaneous/window_menager.c \
				$(SRC_DIR)/parsing/input_validation.c \
				$(SRC_DIR)/parsing/map_validtion.c \
				$(SRC_DIR)/parsing/read_map.c \
				$(SRC_DIR)/parsing/read_map_file.c \
				$(SRC_DIR)/rendering/drawers.c \
				$(SRC_DIR)/rendering/fps_counter.c \
				$(SRC_DIR)/rendering/pixels_drawings.c \
				$(SRC_DIR)/rendering/ray_casting.c \
				$(SRC_DIR)/rendering/texture_drawings.c\

HDRS 		=	-I$(LIBFT_DIR)inc -I$(MLX_DIR) -I$(HDRS_DIR)
LIBS		=	-L$(LIBFT_DIR) -L$(MLX_DIR) $(MLX_FLAGS)
OBJ				=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: mlx libft ascii-art $(NAME)

$(NAME): $(OBJ)
	@echo "$(COMPILATION)Program \"$(NAME)\" compilation:"
	$(CC) $(CFLAGS) $(LIBS) $(HDRS) $(OBJ) -o $(NAME) $(LIBFT) $(MLX_LIB) $(DEFINE_FLAGS)
	@echo "$(RESET)$(INFO)$@ executable has been created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HDRS) $(DEFINE_FLAGS) -c $^ -o $@
	$(eval CURRENT_PROGRESS=$(shell echo $$(($(CURRENT_PROGRESS)+1))))
	$(eval PERCENTAGE=$(shell echo $$(($(CURRENT_PROGRESS)*100/$(TOTAL_PROGRESS)))))
	@if [ $(CURRENT_PROGRESS) -eq $(TOTAL_PROGRESS) ]; then \
		printf "\r\033[K$(GREEN_B)[COMPILATION]$(RESET) \033[38;5;40m$(PERCENTAGE)%% [$$(printf '%*s' $$(($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS))) | tr ' ' '$(PROGRESS_DONE_CHAR)')$$(printf '%*s' $$(($(PROGRESS_WIDTH)-($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS)))) | tr ' ' '$(PROGRESS_TODO_CHAR)')] $<\033[0m ✅                   $(RESET)\n"; \
	else \
		printf "\r\033[K$(GREEN_B)[COMPILATION]$(RESET) \033[38;5;51m$(PERCENTAGE)%% [$$(printf '%*s' $$(($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS))) | tr ' ' '$(PROGRESS_DONE_CHAR)')$$(printf '%*s' $$(($(PROGRESS_WIDTH)-($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS)))) | tr ' ' '$(PROGRESS_TODO_CHAR)')] $<$(RESET)"; \
	fi
	@sleep 0.01


libft:
	@make all -C $(LIBFT_DIR)
	@clear

mlx:
	@make -C $(MLX_DIR)

clean:
	@printf "$(RED_B)[DELETED]$(RESET) $(RED)$(MLX_DIR)\n"
	@for obj in $(OBJ); do \
		rm -f $$obj; \
		printf "$(RED_B)[DELETED]$(RESET) $(RED)$$obj$(RESET)\n"; \
	done

fclean: clean
	@make clean --quiet -C $(MLX_DIR)
	@make fclean --quiet -C $(LIBFT_DIR)
	@rm -f $(NAME);
	@printf "$(RED_B)[DELETED]$(RESET) $(RED)$(NAME)$(RESET)\n"; \

re: fclean all

sre: clean all

ascii-art:
	@echo "\033[1m\033[38;5;231m    +.   ✦         .     ✦     ✦       .        .       ⢀⣀⣤⣄⡀                                             .+"
	@echo "\033[1m\033[38;5;231m    | '.  .    ✦          ✦  . ✦             ✦         ⣴⣿⡟⠁      .       ✦ .        ✦     .       ✦     .' |"
	@echo "\033[1m\033[38;5;231m    |   +------------+.            ✦      .           ⢸⣿⣿      ✦      .                   .+-----------+   |" 
	@echo "\033[1m\033[38;5;195m    |   |            | '.     .        ✦    .         ⠸⣿⣿⣆                  ✦          .'  |           |   |"
	@echo "\033[1m\033[38;5;195m    |   |            |   +--------+      ✦       . ✦   ⠈⠻⠿⣿⠿⠞⠋    .    ✦           ✦  |    |           |   |"
	@echo "\033[1m\033[38;5;195m    |   |            |   |        |   _____ ________           _________      ___.   ________  ________'   | "
	@echo "\033[1m\033[38;5;195m    |   |            |   |        |  /  |  |\_____  \          \_   ___ \ __ _\_ |__ \_____  \ \______ \   | "
	@echo "\033[1m\033[38;5;159m    |   |            |   +--------+ /   |  |_/  ____/   ______ /    \  \/|  |  \ __ \  _(__  <  |    |  \  | "
	@echo "\033[1m\033[38;5;123m    |   |            | .'          /    ^   /       \  /_____/ \     \___|  |  / \_\ \/       \ |    \`   \ |"
	@echo "\033[1m\033[38;5;123m    |   +------------+'............\____   |\_______ \..........\______  /____/|___  /______  //_______  / | "
	@echo "\033[1m\033[38;5;123m    | .'                                |__|        \/                 \/          \/       \/         \/. | "
	@echo "\033[3m\033[38;5;123m    +'.....................................................made with ♥ by @kgebski & @cjackows............'+ "
	@echo

.PHONY: all clean fclean re sre mlx libft
