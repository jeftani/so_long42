NAME = so_long_bonus
libarch = ../libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = so_long.c checker_v1.c check_path.c get_map.c moves.c image_to_window.c images_code.c map_error_countmove.c images_codeV2.c image_to_windowV1.c ft_continuous.c\
game_status.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(libarch) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
