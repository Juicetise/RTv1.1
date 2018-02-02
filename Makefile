NAME = RTv1

SDLFLAGS = -framework SDL2 -F ./frameworks

SDL2_HEADER = -I ./frameworks/SDL2.framework/Headers/

SDL2_P = -rpath @loader_path/frameworks/

SRCS = ./srcs/main.c \
		./srcs/parser.c \
		./srcs/init.c \
		./srcs/intersection.c \
		./srcs/light.c \
		./srcs/ray.c \
		./srcs/vector.c \
		./srcs/normalize.c \

HEADER = ./includes/rtv1.h

FLAGS = -Wall -Wextra -Werror  -I./includes/rtv1.h

OBJ = $(SRCS:.c=.o)

LIB = libft

$(NAME): $(OBJ)
	@make -C $(LIB)
	@gcc -o $(NAME) $(FLAGS) $(SRCS) $(SDL2_P) $(SDLFLAGS) $(SDL2_HEADER) ./libft/libft.a
	@echo "Rtv1 compilation done"

all: $(NAME)

clean:
		@rm -f $(OBJ)
		@rm -f rtv1.h.gch
		make -C $(LIB) clean

fclean: clean
		@rm -f $(NAME)
		make -C $(LIB) fclean

re: fclean all
