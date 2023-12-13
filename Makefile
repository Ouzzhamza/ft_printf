
CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRC =  ft_printf.c ft_putchar.c ft_putchar_hex.c ft_putstr.c ft_strlen.c ft_putnbr.c \

AR  = ar -rcs

OBJ = ${SRC:%.c=%.o}

NAME = libftprintf.a

all : ${NAME}

${NAME} : ${OBJ} 
		${AR} $@ $^

%.o : %.c ft_printf.h
	${CC} ${CFLAGS} -c $<


clean : 
		 @rm -f ${OBJ}

fclean : clean 
			@ rm -f ${NAME}

re : fclean all

bonus : all

.PHONY : all clean fclean re

