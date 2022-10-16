# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 11:10:46 by mthiesso          #+#    #+#              #
#    Updated: 2022/10/16 18:28:38 by mthiesso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYN = \033[36m
YEL = \033[33m
GRN = \033[32m
RST = \033[0m
PRP = \033[35m
RED = \033[91m
BPRP = \033[135m

CC =	gcc
CFLAGS =	-Wall -Wextra -Werror -g #-fsanitize=address
NAME =	philosophers
AR =	ar rcs
SRC =	srcs/main.c \
		srcs/time_manager.c \
		srcs/errors.c \
		srcs/utils.c \
		srcs/init.c \
		srcs/philosophers.c \

OBJ =	${SRC:.c=.o}
DEL = 	rm -rf

all:	${NAME}

%.o:	%.c
			@${CC} ${CFLAGS} -c $< -o $@
${NAME}:	${OBJ}
			@echo "${PRP}-----compilation-----${RST}"
			@echo "[PHILOSOPHERS]	${CYN}Compilating... 🔨${RST}"
			@${CC} ${OBJ} ${CFLAGS} -lpthread \
			-o ${NAME}
			@echo "[PHILOSOPHERS]	${GRN}OK ${RST}"
			@echo "${GRN}Ready to execute ✅${RST}"
exec:	all
		./${NAME}
norm:	all
		norminette ${SRC} philo.h
clean:
			@echo "${RED}-----destroying------${RST}"
			@echo "[PHILOSOPHERS]	${YEL}Deleting...${RST}"
			@${DEL} ${OBJ}
			@echo "[PHILOSOPHERS]	${GRN}Cleaned 🧽${RST}"

fclean:		clean
			@${DEL} ${NAME}
			@echo "${GRN}Cleaning complete. 🗑${RST}"

re:			fclean all

.PHONY:		all clean fclean
