GREEN = $(shell printf "\e[38;5;10m")
WHITE = $(shell printf "\e[39m")
PLUS = $(GREEN)+$(WHITE)

NAME = lem-in
SOURCE = main lemin room file error hashing_funct print_file make_connect breadth_first dist
INCLUDES = -Iincludes -Ilibft/includes
CFILES = $(SOURCE:%=source/%.c)
OFILES = $(SOURCE:%=.objects/%.o)
LIB = libft/printflibft.a
FLAGS = -Wall -Wextra -Werror #ADD LATER

all: $(NAME)

$(NAME): $(LIB) .objects $(OFILES)
	@gcc -g -o $(NAME) $(OFILES) $(LIB) $(INCLUDES)
	@echo "$(NAME) compiled successfully"

.objects:
	@mkdir .objects

$(LIB):
	@make -C libft
	@echo "$(PLUS) $(LIB)"

.objects/%.o: source/%.c includes/lem-in.h
	@gcc -o $@ -c $< $(INCLUDES)
	@echo "$(PLUS) $@"

clean:
	@rm -f $(OFILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
