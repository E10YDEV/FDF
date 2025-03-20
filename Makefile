NAME = fdf

MLX_DIR		:= ./MLX42
MLX		:= $(MLX_DIR)/build/libmlx42.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -IMLX42/include
LDFLAGS = MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
RM = rm -rf

SRCS = fdf.c \
	parse_map.c \
	GNL/get_next_line.c \
	GNL/get_next_line_utils.c \
	bresenham.c \
	draw_map.c \
	hook.c \
	fdf_utils.c \
	parse_map_utils.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(MLX): $(MLX_DIR)
	cmake $(MLX_DIR) -B $(MLX_DIR)/build
	make -C $(MLX_DIR)/build -j4

$(MLX_DIR):
	git clone https://github.com/42-Fundacion-Telefonica/MLX42.git 

${OBJS}: $(MLX)

${NAME}: ${OBJS} $(MLX)
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a ${LDFLAGS} -o ${NAME}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@rm -rf $(MLX_DIR)

re: fclean all

.PHONY: $(MLX_DIR) all clean fclean re

