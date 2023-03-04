NAME = so_long
libarch = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = so_long.c checker_v1.c check_path.c get_map.c moves.c image_to_window.c images_code.c map_error_countmove.c images_codeV2.c game_status.c\

OBJ = ${SRC:.c=.o}

all: make_libft $(NAME)

make_libft:
	cd libft && make && cd ../

flibft_clean:
	cd libft && make fclean && cd ../

libft_clean:
	cd libft && make clean && cd ../

bonus: make_bonus

make_bonus:
	cd bonus && make && cd ../

clean_bonus:
	cd bonus && make clean && cd ../

fclean_bonus:
	cd bonus && make fclean && cd ../

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(libarch) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean: libft_clean clean_bonus
	$(RM) $(OBJ)

fclean: clean fclean_bonus
	$(RM) $(NAME)

re: fclean all
