# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quentin <quentin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 13:38:32 by qbonvin           #+#    #+#              #
#    Updated: 2022/09/02 15:53:13 by quentin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
OBJ = ${SRCS:.c=.o}
SRCS = main.c utils.c init_philo.c philo_eat.c maintoloog.c

all : ${NAME}

${NAME} : ${OBJ}
	${CC} -lpthread ${CFLAGS} -o ${NAME} ${OBJ}

clean :
	rm -rf ${OBJ}
	rm -rf ${NAME}

fclean : clean
	rm -rf ${NAME}

re : fclean all