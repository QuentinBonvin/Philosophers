# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 13:38:32 by qbonvin           #+#    #+#              #
#    Updated: 2022/06/10 13:47:45 by qbonvin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra 
OBJ = ${SRCS:.c=.o}
SRCS = main.c

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} {OBJ}

clean :
	rm -rf ${OBJ}
	rm -rf ${NAME}

fclean : clean
	rm -rf ${NAME}

re : fclean all