# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/03 16:52:44 by bprado         #+#    #+#                 #
#    Updated: 2019/09/27 14:48:29 by bprado        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= ft_printf

FLAGS	= -Wall -Wextra -Werror -g

SRC 	= ft_printf.c play_with_printf.c

LIB 	= ./libft

HDR 	= ./ft_printf.h

OBJ 	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C $(LIB) re
		gcc -o $(NAME) $(SRC) -I $(HDR) $(LIB)/libft.a
		# gcc -o $(NAME) $(SRC) -I $(HDR) $(LIB)/libft.a $(FLAGS) #

clean:
		rm -f $(OBJ)
		make -C $(LIB) clean

fclean:	clean
		rm -rf $(NAME)
		make -C $(LIB) fclean

re:	fclean all