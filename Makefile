NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIB = ranlib #index library

SRCS = ft_printf.c \
	utils.c 

OBJS = ${SRCS:.c=.o}

all: $(NAME)

${NAME} : ${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# Cleaning up obj
clean:
	${RM} ${OBJS}

# Full clean (obj + lib)
fclean: clean
	${RM} ${NAME}

# Re-make the lib
re: fclean all

# Dependency of header file for all obj
$(OBJS): libftprintf.h

.PHONY: all clean fclean re
