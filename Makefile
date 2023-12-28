CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ./ft_printf.c \
./ft_putchar.c \
./ft_putstr.c \
./ft_putnbr.c \
./ft_putvoid.c

all: ${NAME}

HEADER = ft_printf.h

OBJ = ${SRCS:.c=.o}

${NAME} : 	${OBJ} ${HEADER}
	ar -rc ${NAME} ${OBJ}

%.o 	:	%.c ${HEADER}
	${CC} -c ${FLAGS} $< -o $@

clean	:
	rm -f ${OBJ}

fclean	: 	clean
	rm -f ${NAME}

re	: 	fclean
	$(MAKE) all

.PHONY: clean fclean re all
