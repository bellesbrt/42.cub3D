LIBFT_PATH=./libft
LIBFT_FULL_PATH=$(LIBFT_PATH)/libft.a

NAME=cub3D
CC=cc
CFLAGS=-g3 -Wall -Werror -Wextra

INCLUDES_USR=-I./usr/include
INCLUDES=-I$(LIBFT_PATH)/includes -I./src/includes

LIBRARY_MLX_PATH= -L/usr/lib -lmlx -lXext -lX11 -lm -lz

SRCS=	./src/cub3D.c ./src/map_wall_validation.c ./src/game.c ./src/game_init.c \
		./src/imgs.c ./src/error.c ./src/game_exit.c \
		./src/free.c ./src/file_utils.c \
		./src/map_list_utils.c ./src/utils.c \
		./src/map_properties_utils.c ./src/map_content_utils.c \
		./src/player_content.c ./src/map_color.c \
		./src/map_loaders.c ./src/player.c \
		./src/player_utils.c ./src/graphics.c \
		./src/calc_rays.c ./src/ray_direction.c ./src/calc_vertical_coordinates.c \
		./src/calc_horizontal_coordinates.c ./src/invert_direction.c \
		./src/vertical_utils.c ./src/horizontal_utils.c  ./src/cast_rays.c\
		./src/walls.c ./src/dist_wall.c \

OBJS=$(SRCS:.c=.o)

all: $(NAME)
bonus: all

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES_USR) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT_FULL_PATH) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY_MLX_PATH) $(LIBFT_FULL_PATH) -o $(NAME)

$(LIBFT_FULL_PATH):
	@make -C libft

clean:
	@rm -f $(OBJS) $(MLX_LINUX_LIB)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

valgrind: re
	@valgrind -s --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --trace-children=yes --log-fd=9 ./$(NAME) map.cub

test:
	./$(NAME) map.cub

.PHONY: all clean fclean re bonus