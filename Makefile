NAME		= push_swap
CHECKER		= checker
SRCS		= main.c \
				gnl/get_next_line_utils.c \
				util_arrop.c \
				util_lib.c \
				util_print.c \
				stackop_swap.c \
				stackop_push.c \
				stackop_rotate.c \
				stackop_reverse_rotate.c \
				sort_divconq.c \
				sort_divconq_fixedop12.c \
				sort_divconq_fixedop3.c \
				sort_small_fixed.c
C_SRCS		= checker.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				util_arrop.c \
				util_lib.c \
				util_print.c \
				stackop_swap.c \
				stackop_push.c \
				stackop_rotate.c \
				stackop_reverse_rotate.c
OBJS		= $(SRCS:.c=.o)
C_OBJS		= $(C_SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME) $(CHECKER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(CHECKER): $(C_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER) $(C_OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(C_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
