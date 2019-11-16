GREEN = $(shell printf "\e[38;5;10m")
WHITE = $(shell printf "\e[39m")
PLUS = $(GREEN)+$(WHITE)

NAME = lem-in
SOURCE = main lemin room map error print_map make_connect \
get_path breadth_first reset check_paths_save_winner \
find_solution links save_links_to_delete move_all_ants_in_paths \
delete_paths_from_paths free_lemin_struct

INCLUDES = -Iincludes -Ilibft/includes
CFILES = $(SOURCE:%=source/%.c)
OFILES = $(SOURCE:%=.objects/%.o)
LIB = libft/printflibft.a
FLAGS = -Wall -Wextra -Werror #ADD LATER

all: $(NAME)

$(NAME): $(LIB) .objects $(OFILES)
	@$(CC) -o $(NAME) $(OFILES) $(LIB) $(INCLUDES) -g
	@echo "$(NAME) compiled successfully"

.objects:
	@mkdir .objects

$(LIB):
	@make -C libft
	@echo "$(PLUS) $(LIB)"

.objects/%.o: source/%.c includes/lem-in.h
	@$(CC) -o $@ -c $< $(INCLUDES) -g
	@echo "$(PLUS) $@"

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -rf .objects
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
