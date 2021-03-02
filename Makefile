# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsimelio <jsimelio@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/28 23:54:18 by jsimelio      #+#    #+#                  #
#    Updated: 2021/03/01 22:49:23 by jsimelio      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

LIBFT = libft.a

HEADER = ft_printf.h

SRCS =	ft_printf.c\
		ft_printf_char_str.c\
		ft_printf_flags.c\
		ft_printf_int_uint.c\
		ft_printf_ptr_hex.c\
		ft_printf_specifier.c

OBJS = 	$(SRCS:%.c=$(S_PATH)%.o)

vpath %.c srcs

all: library $(NAME)

library:
	cd libft && $(MAKE) all

$(NAME): $(OBJS)
	cp libft/$(LIBFT) $(NAME)
	@ar rcs $(NAME) $^

%.o: %.c
		gcc -Wall -Wextra -Werror -I includes -c $<

clean:
	rm -rf $(OBJS)
	cd libft && $(MAKE) clean

fclean: clean
		rm -rf $(NAME)
		cd libft && $(MAKE) fclean

re: fclean all
