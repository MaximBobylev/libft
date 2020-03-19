# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxim <maxim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/19 15:12:06 by maxim             #+#    #+#              #
#    Updated: 2020/03/19 15:12:11 by maxim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o \
ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o \
ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putchar.o \
ft_putendl.o ft_putendl_fd.o ft_putnbr_fd.o ft_putnbr.o ft_putstr_fd.o ft_putstr.o ft_strcat.o \
ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o \
ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o \
ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o \
ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o \
ft_tolower.o ft_toupper.o \
ft_strccpy.o ft_strrev.o ft_memrchr.o ft_sqrt.o ft_power.o ft_intswap.o \
ft_get_words_count.o get_next_line.o \
hex_to_dec.o rad2deg.o deg2rad.o

INCLUDE = ./

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc libft.a $(OBJ)

$(OBJ): %.o : %.c libft.h
	@gcc -Wall -Wextra -Werror -c $< -o $@ -I$(INCLUDE)
	
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf libft.a

re: fclean all