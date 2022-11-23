# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 15:54:04 by lboulatr          #+#    #+#              #
#    Updated: 2022/11/23 16:13:28 by lboulatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c count.c ft_pnbr_bhexa.c ft_putchar_fd_count.c ft_putnbr_fd_count.c ft_putnbr_fd_usign.c \
		ft_putstr_fd_count.c
	
OBJS = ${SRCS:.c=.o}

CC = cc

FLAGS = -Wall -Werror -Werror

HEADERS = libftprintf.h 

NAME = libftprintf.a

LIB = ar rc

RM = rm -f

%.o:	%.c ${HEADERS} Makefile
	${CC} ${FLAGS} -I${HEADERS} -c %.c -o %.o  
	
all:	${NAME} Makefile libft

libft:
	make -C libft

${NAME}:	libft ${OBJS} Makefile
	cp libft/libft.a ./${NAME}
	${LIB} ${NAME} ${OBJS}

clean:	
	${RM} ${OBJS} libft/libft.a libft/*.o 

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re libft
