NAME = philo

SRCS = 	utils.c \
		destroyers.c \
		inits.c \
		main_philo.c \
		simulation.c \
		outputs.c \
		inputs.c \
		living.c \
		theGod.c

HDRS 		= philo.h

OBJS		= ${SRCS:.c=.o}

DIR_SRCS	= ./srcs/

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= ./includes/

all:	${NAME}

${OBJS}: ${INCLUDES}${HDRS}

%.o: $(DIR_SRCS)%.c	
		${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

$(NAME): ${OBJS}
		${CC} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS} ${OBJS_FULL}

fclean:	clean
		${RM} ${NAME}

re:		fclean
	make all

.PHONY : all clean fclean re
