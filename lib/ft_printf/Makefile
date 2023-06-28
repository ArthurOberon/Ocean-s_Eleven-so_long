NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_putstr_int.c \
		ft_check_args.c \
		ft_putnbr_int.c \
		ft_putchar_int.c \
		ft_putnbr_base_int.c \
		ft_print_hexa_int.c \
		ft_print_address_int.c \

LIBFTOBJS =	ft_abs.o \
			ft_atoi.o \
			ft_itoa.o \
			ft_bzero.o \
			ft_split.o \
			ft_lstmap.o \
			ft_lstnew.o \
			ft_strlen.o \
			ft_memset.o \
			ft_memcpy.o \
			ft_strchr.o \
			ft_memchr.o \
			ft_memcmp.o \
			ft_calloc.o \
			ft_strdup.o \
			ft_substr.o \
			ft_putstr.o \
			ft_putnbr.o \
			ft_nbrlen.o \
			ft_strmapi.o \
			ft_strnstr.o \
			ft_strjoin.o \
			ft_strncmp.o \
			ft_strtrim.o \
			ft_isalpha.o \
			ft_isdigit.o \
			ft_isalnum.o \
			ft_isascii.o \
			ft_isprint.o \
			ft_memmove.o \
			ft_strlcpy.o \
			ft_strlcat.o \
			ft_toupper.o \
			ft_tolower.o \
			ft_strrchr.o \
			ft_putchar.o \
			ft_isspace.o \
			ft_putendl.o \
			ft_lstsize.o \
			ft_lstiter.o \
			ft_lstlast.o \
			ft_lstclear.o \
			ft_striteri.o \
			ft_putstr_fd.o \
			ft_lstdelone.o \
			ft_putnbr_fd.o \
			ft_putendl_fd.o \
			ft_putchar_fd.o \
			ft_lstadd_back.o \
			ft_lstadd_front.o \

LIBFTO = $(addprefix libft/,${LIBFTOBJS})

INC = includes

RM = rm -f

CC = gcc -Wall -Wextra -Werror -I${INC}

OBJS = ${SRCS:.c=.o}

all:	${NAME}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C libft
		ar rc ${NAME} ${OBJS} ${LIBFTO}

clean:
	make -C libft clean
	${RM} ${OBJS} 

fclean:	clean
	make -C libft fclean
	${RM} ${NAME}

re:	fclean all


.PHONY:	all clean fclean re
