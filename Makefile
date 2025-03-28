# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 07:11:17 by sel-jari          #+#    #+#              #
#    Updated: 2025/03/28 07:11:19 by sel-jari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCF = fractol_render.c cal_utils.c fractol_events.c fractol.c fractol_utils.c ft_putstr_fd.c extra_utils.c

NAME = fractol

OBJF = ${SRCF:.c=.o}

CC = cc

FLAGS = -Wall -Wall -Werror

MLX = -Lmlx_linux -lmlx -lXext -lX11

RM = rm -f

all: ${NAME}

${NAME}: ${OBJF}
	${CC} ${OBJF} ${MLX} -o ${NAME}

clean:
	${RM} ${OBJF}
fclean:
	${RM} ${NAME} ${OBJF}
re: fclean all
