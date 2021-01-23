# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsimelio <jsimelio@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/23 00:04:55 by jsimelio      #+#    #+#                  #
#    Updated: 2020/11/23 00:05:00 by jsimelio      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
REG_SRCS = 			ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c
BONUS_SRCS =		ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstadd_front.c \
					ft_lstadd_back.c \
					ft_lstsize.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstlast.c
REG_OBJS = $(REG_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
HEADER_FILE = libft.h
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJS) $(BONUS_OBJS)
else
OBJ_FILES = $(REG_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(LIBC) $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER_FILE)
	$(CC) -c $(FLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(REG_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
