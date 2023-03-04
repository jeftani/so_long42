# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 15:39:43 by ajeftani          #+#    #+#              #
#    Updated: 2023/02/15 13:21:01 by ajeftani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
	ft_strlen.c ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_strdup.c ft_isprint.c ft_substr.c ft_strjoin.c ft_putendl_fd.c ft_strtrim.c\
	ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strlcat.c ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_split.c get_next_line.c\

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re : fclean all
