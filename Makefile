# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsimelio <jsimelio@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/23 00:04:55 by jsimelio      #+#    #+#                  #
#    Updated: 2021/01/14 12:22:37 by jsimelio      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =	ft_printf.c
		# ft_toupper.c
LIBRARY = libft.a
INCLUDES = includes/
OBJS = $(SRCS:.c=.o)
HEADER_FILE = -C include libftprintf.h
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror

vpath %.c srcs

.PHONY: all clean fclean re

all: libft $(NAME)

$(NAME): $(OBJS)
	cp libft/$(LIBRARY) $(NAME)
	ar rcs $(NAME) $^

%.o: %.c $(HEADER_FILE)
	$(CC) $(FLAGS) -I $(INCLUDES) -c $<

bonus:
	all

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re:
	fclean all

libft:
	$(MAKE) -C libft all
