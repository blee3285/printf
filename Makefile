# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blee <blee@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 17:58:25 by blee              #+#    #+#              #
#    Updated: 2017/05/11 18:48:41 by blee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a

CFLAGS		:= -Wall -Wextra -Werror

LIBSRC		:= ft_atoi.c \
			   ft_bzero.c \
	           ft_is{alnum,alpha,ascii,digit,print}.c \
	           ft_itoa.c \
	     	   ft_lst{add,del,delone,iter,map,new}.c \
	     	   ft_mem{alloc,ccpy,chr,cmp,cpy,del,move,set}.c \
	     	   ft_put{char,char_fd,endl,endl_fd,nbr,nbr_fd,str,str_fd}.c \
	     	   ft_str{cat,chr,clr,cmp,cpy,del,dup,equ,iter,iteri,join}.c \
	     	   ft_str{lcat,len,map,mapi}.c \
	     	   ft_strn{cat,cmp,cpy,equ,ew,str}.c \
	     	   ft_str{rchr,split,str,sub,trim}.c \
	     	   ft_to{lower,upper}.c \
	     	   ft_abs.c \
	     	   ft_swap.c \
	     	   ft_sort_int.c \
	     	   ft_numlen.c \
	     	   ft_strsplit_lst.c \
	     	   ft_isprime.c \
	     	   ft_lstdelnode.c \
	     	   ft_itoa_base.c

LIBFT		:= $(addprefix libft/, $(LIBSRC))
OBJLIBFT	:= $(LIBSRC:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(NAME):
	gcc	-c $(CFLAGS) $(LIBFT)
	ar rc $(NAME) $(OBJLIBFT)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJLIBFT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
