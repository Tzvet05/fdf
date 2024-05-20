# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttrave <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 18:16:33 by ttrave            #+#    #+#              #
#    Updated: 2024/03/26 19:05:33 by ttrave           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Make parameters

NAME =		fdf

COMPILER =	cc

CFLAG =		-Wall -Wextra -Werror

LIB =		libft.a
LIB_GRAPH =	libmlx.so

# Directories

LIB_DIR =	libft/
LIB_GRAPH_DIR =	MacroLibX/
HDR_DIR =	hdr/
SRC_DIR =	src/
OBJ_DIR =	obj/
SRC_BONUS_DIR =	src_bonus/
OBJ_BONUS_DIR =	obj_bonus/

# Source code (mandatory)

SRC =	main.c \
	parsing1.c \
	parsing2.c \
	parsing3.c \
	hook.c \
	center_start.c \
	projection.c \
	draw.c \
	utils.c

# Source code (bonus)

SRC_BONUS =	main_bonus.c \
		check_args_bonus.c \
		parsing1_bonus.c \
		parsing2_bonus.c \
		parsing3_bonus.c \
		hook1_bonus.c \
		hook2_bonus.c \
		apply_hooks1_bonus.c \
		apply_hooks2_bonus.c \
		center_start_bonus.c \
		calculate_display_bonus.c \
		projection1_bonus.c \
		projection2_bonus.c \
		draw_bonus.c \
		utils_bonus.c

# Compiled objects (mandatory)

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# Compiled objects (bonus)

OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR), $(SRC_BONUS:.c=.o))

# Compilation (mandatory)

$(NAME) : $(LIB_DIR)$(LIB) $(LIB_GRAPH_DIR)$(LIB_GRAPH) $(OBJ)
	@ echo "[$(NAME)] - $(NAME) compiled (mandatory)."
	@ $(COMPILER) $(CFLAG) $(OBJ) $(LIB_DIR)$(LIB) $(LIB_GRAPH_DIR)$(LIB_GRAPH) -lm -lSDL2 -Wl,-rpath,$(LIB_GRAPH_DIR) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	@ $(COMPILER) $(CFLAG) -I $(HDR_DIR) -c $^ -o $@

# Compilation (bonus)

bonus : $(LIB_DIR)$(LIB) $(LIB_GRAPH_DIR)$(LIB_GRAPH) $(OBJ_BONUS)
	@ echo "[$(NAME)] - $(NAME) compiled (bonus)."
	@ $(COMPILER) $(CFLAG) $(OBJ_BONUS) $(LIB_DIR)$(LIB) $(LIB_GRAPH_DIR)$(LIB_GRAPH) -lm -lSDL2 -Wl,-rpath,$(LIB_GRAPH_DIR) -o $(NAME)

$(OBJ_BONUS_DIR)%.o : $(SRC_BONUS_DIR)%.c | $(OBJ_BONUS_DIR)
	@ $(COMPILER) $(CFLAG) -I $(HDR_DIR) -c $^ -o $@

# Objects directories

$(OBJ_DIR) $(OBJ_BONUS_DIR) :
	@ mkdir -p $@

# Libraries

$(LIB_DIR)$(LIB) :
	@ make -s -C $(LIB_DIR)

$(LIB_GRAPH_DIR)$(LIB_GRAPH) :
	@ make -j -s -C $(LIB_GRAPH_DIR)

# Rules

all : $(NAME)

fclean :
	@ echo "[$(NAME)] - Executable ($(NAME)) cleaned.\n[$(NAME)] - Objects cleaned."
	@ make fclean -s -C $(LIB_DIR)
	@ make fclean -s -C $(LIB_GRAPH_DIR)
	@ rm -rf $(NAME) $(OBJ_DIR) $(OBJ_BONUS_DIR)

clean :
	@ echo "[$(NAME)] - Objects cleaned."
	@ make clean -s -C $(LIB_DIR)
	@ make clean -s -C $(LIB_GRAPH_DIR)
	@ rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)

cleanfdf : clean
	@ echo "[$(NAME)] - Executable ($(NAME)) cleaned."
	@ rm -f $(NAME)

re : fclean all

heheheha :
	@ make heheheha -s -C $(LIB_DIR)

.PHONY : all fclean clean cleanfdf re bonus heheheha
