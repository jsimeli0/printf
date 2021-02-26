# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ssemanco <ssemanco@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/05 20:21:58 by ssemanco      #+#    #+#                  #
#    Updated: 2021/02/15 15:55:08 by jsimelio      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

HEADER = ft_printf.h

SRC = srcs/ft_printf.c

OBJECTS = ft_printf.o 

vpath %.c srcs

all: library $(NAME)

%.o: %.c
		gcc -Wall -Wextra -Werror -I $(HEADER) -c $<

$(NAME): $(OBJECTS)
	cp libft/$(LIBFT) $(NAME)
	@ar rcs $(NAME) $^

clean:
	rm -rf $(OBJECTS)
	cd libft && $(MAKE) clean

fclean: clean
		rm -rf $(NAME)
		cd libft && $(MAKE) fclean

re: fclean all

library:
	cd libft && $(MAKE) all