NAME	= 	libftprintf.a

LIBFT	=	./libft

BASE	=	./base

PARSER	=	./parser

PROCE	=	./processor

HEADER	= 	./includes

SRCS	=	$(BASE)/ft_printf.c 				\
			$(BASE)/ft_additional_func.c		\
			$(BASE)/ft_itoa_base.c				\
			$(PARSER)/ft_parser.c 				\
			$(PARSER)/ft_parse_flags.c 			\
			$(PARSER)/ft_parse_width.c			\
			$(PARSER)/ft_parse_precision.c		\
			$(PARSER)/ft_parse_type.c			\
			$(PROCE)/ft_processor.c				\
			$(PROCE)/ft_char_type.c				\
			$(PROCE)/ft_percent_type.c			\
			$(PROCE)/ft_string_type.c			\
			$(PROCE)/ft_un_xx_type.c			\
			$(PROCE)/ft_un_int_type.c			\
			$(PROCE)/ft_pointer_type.c			\
			$(PROCE)/ft_int_type.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I

.c.o:
			gcc $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o) 

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) bonus -C $(LIBFT)
			cp $(LIBFT)/libft.a $(NAME)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(MAKE) clean -C $(LIBFT)
			rm -f $(OBJS) $(OBJS_B)

fclean:		clean
			rm -f $(NAME)
			$(MAKE) fclean -C $(LIBFT)

re:			fclean all
			$(MAKE) re -C $(LIBFT)

.PHONY:		all clean fclean re
