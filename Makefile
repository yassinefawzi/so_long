SRC =	so_long.c \
		getnext_line/get_next_line.c \
		getnext_line/get_next_line_utils.c \
		mapcheck.c \
		error.c \
		findpath.c \
		image.c \
		keys.c \
		libft/ft_strjoin.c \
		libft/ft_split.c \
		libft/ft_strlen.c \
		libft/ft_strncmp.c \
		libft/ft_substr.c \
		libft/ft_putstr_fd.c \
		libft/ft_itoa.c \
		helper.c

obj = $(SRC:.c=.o)
rm = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
CC = cc	

all: $(NAME)

$(NAME): $(obj)
	$(CC) $(CFLAGS) -I /usr/local/include $(obj) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(rm) $(obj)
fclean:
	$(rm) $(obj) $(NAME) 
re: fclean $(NAME)