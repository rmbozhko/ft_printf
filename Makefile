#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imarakho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 15:31:51 by imarakho          #+#    #+#              #
#    Updated: 2017/05/10 14:48:18 by rbozhko          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a


SRC = ft_strcat.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strsub.c ft_atoi.c ft_memset.c ft_strstr.c \
	 ft_strjoin.c ft_printf.c ft_strnew.c ft_isalpha.c ft_int_numlen.c ft_alter_instruct.c ft_flags.c ft_instruct_type.c \
	 types.c useful_funcs.c ft_isdigit.c ft_itoa.c ft_isalnum.c ft_strcmp.c ft_str_utils.c ft_num_utils.c ft_get_instruction.c \
	 ft_print_instruction.c ft_str_help.c ft_get_arguments_str.c ft_get_arguments_hex.c ft_get_arguments_octal.c ft_get_arguments_dec.c \
	 ft_alter_sml_stuff.c


OBJ = $(SRC:.c=.o)

CFLAGS = -c 
#-Wall -Wextra -Werror
HEADER = ft_printf.h

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) -I $(HEADER)
	ar	rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $<

clean:
	rm	-rf $(OBJ)

fclean: clean
	rm	-rf $(NAME)

re: fclean all
