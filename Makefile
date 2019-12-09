# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/03 16:52:44 by bprado         #+#    #+#                 #
#    Updated: 2019/12/09 12:30:17 by bprado        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# https://stackoverflow.com/questions/14639794/getting-make-to-create-sect-files-in-a-specific-directory
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean
# http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables


NAME 	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror -g

SRC 	= $(wildcard src/*.c)

LIB 	= ./libft

INC 	= -I inc -I libft/includes

s		= $(patsubst src/%.c,s/%.o,$(SRC))


all: $(NAME)

$(NAME): $(s) libft/libft.a
	@echo "compiling ..."
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) $(s)
	@ranlib $(NAME)

s/%.o: src/%.c inc/ft_printf.h
	@mkdir -p s
	$(CC) -c $(CFLAGS) $(INC) -o $@ $<

libft/libft.a: $(wildcard libft/*.c)
	@$(MAKE) -C $(LIB)

clean:
	@echo "cleaning ..."
	@make clean -C $(LIB)
	@rm -rf s

fclean:	clean
	@make fclean -C $(LIB)
	@rm -rf $(NAME) test

test: test.c $(NAME)
	@$(CC) -o $@ -Wall -Wextra -g $(INC) $^

re:	fclean all
