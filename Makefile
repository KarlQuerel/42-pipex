_GREEN=\033[32m

NAME	= pipex

PATH_LIBFT	= libft
LIBFT	= ${PATH_LIBFT}/libft.a

PATH_SRCS	= srcs
SRCS	= ${PATH_SRCS}/main.c\
		# ${PATH_SRCS}/utils.c	\
		# ${PATH_SRCS}/algorithm.c	\
		# ${PATH_SRCS}/lists.c	\
		# ${PATH_SRCS}/lists_utils.c	\
		# ${PATH_SRCS}/check_utils.c	\
		# ${PATH_SRCS}/check.c	\
		# ${PATH_SRCS}/operations.c	\
		# ${PATH_SRCS}/operations_utils.c	\
		# ${PATH_SRCS}/exit.c	\

OBJS	= ${SRCS:.c=.o}

CC	= cc

C_FLAGS	= -Wall -Werror -Wextra -g3

RM	= rm -f

all: ${LIBFT} ${NAME}

${NAME}: ${OBJS}
		${CC} ${C_FLAGS} -o ${NAME} ${OBJS} ${LIBFT}
		clear
		@toilet PIPEX COMPILED -F border -f future
		@echo "$(_GREEN)		⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ "
		@echo "$(_GREEN)		⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀ca⠀⠀⠀⠀ "
		@echo "$(_GREEN)		⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀ compile "
		@echo "$(_GREEN)		⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀ "
		@echo "$(_GREEN)		⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆ "
		@echo "$(_GREEN)		⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿ "
		@echo "$(_GREEN)		⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀ "
		@echo "$(_GREEN)		⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ "
		@echo "$(_GREEN)		⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ "
		@echo "$(_GREEN)		⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ "
		@echo "$(_GREEN)		⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀ "
		@echo "$(_GREEN)		⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀bravo⠀ "
		@echo "$(_GREEN)		⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀ "
		@echo "$(_GREEN)		⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀ "
		@echo "$(_GREEN)		⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉"

${LIBFT}:
		make -C ${PATH_LIBFT}
		clear
		@toilet LIBFT -F border -f future


.c.o:
	${CC} ${C_FLAGS} -c $< -o ${<:.c=.o}

clean:
		make -C ${PATH_LIBFT} clean
		${RM} ${OBJS}
		clear
		@toilet CLEAN -F border -f future

fclean:	clean
		make -C ${PATH_LIBFT} fclean
		${RM} ${NAME}
		clear
		@toilet FCLEAN -F border -f future

norminette:
		@toilet NORMINETTE -F border -f future
		@echo NORMINETTE SRCS
		@norminette srcs
		@echo NORMINETTE INCLUDES
		@norminette includes

re:	fclean all

.PHONY:	all clean fclean re
