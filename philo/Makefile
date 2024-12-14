# Executable file
NAME		=	philo

# Source files
FILE_NAME	=	free_philo.c \
				getms.c \
				init_philo.c \
				launch.c \
				main.c \
				person.c \
				process_input.c \
				state_message.c \
				supervisor.c \
				util1.c \
				util2.c

SRCS		=	$(wildcard src/*.c)

# Object files
OBJS		=	$(SRCS:.c=.o)

# Compiler
CC			=	cc

# Flags (philo)
CFLAGS		=	-Wall -Wextra -Werror
LFALGS		=	-Wall -Wextra -Werror
SANITIZE	=	-fsanitize=address

ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	CFLAGS	+=	$(DEBUG)
	LFLAGS	+=	$(DEBUG)
endif

# Rules
.DEFAULT_GOAL	=	all

$(NAME): $(OBJS)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

debug: $(NAME)

.PHONY: all clean fclean re debug
