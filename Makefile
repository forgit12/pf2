#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oborysen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 21:59:45 by oborysen          #+#    #+#              #
#    Updated: 2017/03/01 17:37:28 by oborysen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./includes

SRC =	ft_printf.c\
		count_p_f_w_sm.c\
		conv_recog.c\
		print_x_o.c\
		ft_put_s_nbr_per_siz.c\
		print_i_d.c\
		print_s_c.c\
		print_p_u.c\
		print_c.c\
		conv_sm.c\
		ft_null.c\
		print_ch.c\
		add.c\
		add2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	gcc $(FLAGS) -c -o $@ $<

$(NAME) :
		gcc -c $(FLAGS) $(SRC) $(INCLUDES)
		ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all