# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blee <blee@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 17:58:25 by blee              #+#    #+#              #
#    Updated: 2017/05/25 15:27:30 by blee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a

CFLAGS		:= -Wall -Wextra -Werror

LIBSRC		:= ft_atoi.c \
			   ft_bzero.c \
			   ft_isalnum.c \
			   ft_isalpha.c \
			   ft_isascii.c \
			   ft_isdigit.c \
			   ft_isprint.c \
	           ft_itoa.c \
			   ft_lstadd.c \
			   ft_lstdel.c \
			   ft_lstdelone.c \
			   ft_lstiter.c \
			   ft_lstmap.c \
			   ft_lstnew.c \
			   ft_memalloc.c \
			   ft_memccpy.c \
			   ft_memchr.c \
			   ft_memcmp.c \
			   ft_memcpy.c \
			   ft_memdel.c \
			   ft_memmove.c \
			   ft_memset.c \
			   ft_putchar.c \
			   ft_putchar_fd.c \
			   ft_putendl.c \
			   ft_putendl_fd.c \
			   ft_putnbr.c \
			   ft_putnbr_fd.c \
			   ft_putstr.c \
			   ft_putstr_fd.c \
			   ft_strcat.c \
			   ft_strchr.c \
			   ft_strclr.c \
			   ft_strcmp.c \
			   ft_strcpy.c \
			   ft_strdel.c \
			   ft_strdup.c \
			   ft_strequ.c \
			   ft_striter.c \
			   ft_striteri.c \
			   ft_strjoin.c \
			   ft_strlcat.c \
			   ft_strlen.c \
			   ft_strmap.c \
			   ft_strmapi.c \
			   ft_strncat.c \
			   ft_strncmp.c \
			   ft_strncpy.c \
			   ft_strnequ.c \
			   ft_strnew.c \
			   ft_strnstr.c \
			   ft_strrchr.c \
			   ft_strsplit.c \
			   ft_strstr.c \
			   ft_strsub.c \
			   ft_strtrim.c \
			   ft_tolower.c \
			   ft_toupper.c \
	     	   ft_abs.c \
	     	   ft_swap.c \
	     	   ft_sort_int.c \
	     	   ft_numlen.c \
	     	   ft_strsplit_lst.c \
	     	   ft_isprime.c \
	     	   ft_lstdelnode.c \
	     	   ft_itoa_base.c

PFSRC		:= ft_printf.c \
			   formats.c \
			   conversion.c \
			   width.c \
			   precision.c

LIBFT		:= $(addprefix libft/, $(LIBSRC))
PFC			:= $(addprefix src/, $(PFSRC))
OBJLIBFT	:= $(LIBSRC:.c=.o)
OBJPF		:= $(PFSRC:.c=.o)

.PHONY = all clean fclean re test

all: $(NAME)

$(OBJLIBFT): $(LIBFT)
	@gcc -c $(CFLAGS) $^

$(OBJPF): $(PFC)
	@gcc -c $(CFLAGS) $^

$(NAME): $(OBJLIBFT) $(OBJPF)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

test: $(NAME) main.c
	@gcc main.c $(NAME)

clean:
	@/bin/rm -f $(OBJLIBFT) $(OBJPF)

fclean: clean
	@/bin/rm -f $(NAME) a.out

re: fclean all
