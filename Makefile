NAME = libftprintf.a

SRC = ft_printf.c\
		ft_char.c\
		ft_hex.c\
		ft_ptr.c\
		ft_uphex.c\
		ft_str.c\
		ft_nbr.c\
		ft_unnbr.c
		

OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re