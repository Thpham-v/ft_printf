SRCS		= 	ft_b_and_a.c			\
				ft_print_diux.c		\
				ft_print_flag.c			\
				ft_printf.c				\
				printf_utils_3.c		\
				printf_utils_1.c		\
				printf_utils_2.c		\
				printf_utils_4.c		\
				ft_init_struct.c		\
				ft_print_s.c			\
				ft_print_c.c			\
				ft_print_p.c			\

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re