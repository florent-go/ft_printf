NAME	=	libftprintf.a

OBJ	=	$(SRC:.c=.o)

SRC	=	ft_convert.c \
		ft_fonc2.c \
		ft_g_flags.c \
		ft_printf.c \
		ft_printnumber.c \
		ft_printnumber2.c \
		ft_printmodulo.c \
		ft_printstring.c \
		ft_printchar.c \
		ft_printhexa.c \
		ft_printpointer.c \
		ft_put.c \
		ft_fonc.c

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re all
