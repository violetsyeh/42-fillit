NAME	= fillit
SRCS	= f_main.c f_map.c f_map_check.c f_output_map.c \
		f_solve.c f_sqrt.c f_tetri.c f_top_left.c \
		f_verify_tetri.c \

OBJ		= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= ./libft/libft.a
LIBLINK	= -L./libft -lft

all: libft $(NAME)

libft: $(LIBFT)

$(LIBFT):
	@ make -C ./libft

$(NAME): $(OBJ)
	@ $(CC) $(LIBLINK) -o $(NAME) $(OBJ)

clean:
	@ rm -rf $(OBJ)
	@ make clean -C ./libft

fclean: clean
	@ rm -rf ./$(NAME)
	@ rm -rf ./$(LIBFT)
	
re: fclean all
