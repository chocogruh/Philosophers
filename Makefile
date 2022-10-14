# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 11:10:46 by mthiesso          #+#    #+#              #
#    Updated: 2022/10/14 21:23:56 by mthiesso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYN = \033[36m
YEL = \033[33m
GRN = \033[32m
RST = \033[0m

CC =	gcc
CFLAGS =	-Wall -Wextra -Werror -g #-fsanitize=address
NAME =	philosophers
AR =	ar rcs
SRC =	srcs/main.c \
		srcs/time_manager.c \
		srcs/errors.c \
		srcs/utils.c \
		srcs/init.c \

OBJ =	${SRC:.c=.o}
DEL = 	rm -rf

all:	${NAME}

%.o:	%.c
			@${CC} ${CFLAGS} -c $< -o $@
${NAME}:	${OBJ}
			@echo "[PHILOSOPHERS]	${CYN}Compilating... 🔨${RST}"
			@${CC} ${OBJ} ${CFLAGS} \
			-o ${NAME}
			@echo "[PHILOSOPHERS]	${GRN}OK 🍝${RST}"
exec:	all
		./${NAME}
norm:	all
		norminette ${SRC} philo.h
clean:
			@echo "[PHILOSOPHERS]	${YEL}Deleting...${RST}"
			@${DEL} ${OBJ}
			@echo "[PHILOSOPHERS]	${GRN}Cleaned 🧽${RST}"

fclean:		clean
			@${DEL} ${NAME}
			@echo "${GRN}Cleaning complete. 🗑${RST}"

re:			fclean all

.PHONY:		all clean fclean
