# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 13:38:32 by qbonvin           #+#    #+#              #
#    Updated: 2022/09/06 12:02:06 by qbonvin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
OBJ = ${SRCS:.c=.o}
SRCS = main.c utils.c utils2.c display_message.c dead_exit.c parsing.c routine.c

all : ${NAME}

${NAME} : ${OBJ}
	${CC} -lpthread ${CFLAGS} -o ${NAME} ${OBJ}

clean :
	rm -rf ${OBJ}
	rm -rf ${NAME}

fclean : clean
	rm -rf ${NAME}

re : fclean all