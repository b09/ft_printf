# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/03 16:52:44 by bprado         #+#    #+#                 #
#    Updated: 2019/12/11 22:10:52 by bprado        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror -g

SRC 	= $(wildcard src/*.c)

LIB 	= ./libft

INC 	= -I inc -I libft/includes

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))


all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@echo "compiling ..."
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

obj/%.o: src/%.c inc/ft_printf.h
	@mkdir -p obj
	$(CC) -c $(CFLAGS) $(INC) -o $@ $<

libft/libft.a: $(wildcard libft/*.c)
	@$(MAKE) -C $(LIB)

clean:
	@echo "cleaning ..."
	@make clean -C $(LIB)
	@rm -rf obj

fclean:	clean
	@make fclean -C $(LIB)
	@rm -rf $(NAME) test

test: test.c $(NAME)
	@$(CC) -o $@ -Wall -Wextra -g $(INC) $^

re:	fclean all
