# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhignett <fhignett@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/25 13:29:28 by fhignett       #+#    #+#                 #
#    Updated: 2019/11/29 13:06:10 by fhignett      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include makefilesrc/clrs.mk
include makefilesrc/src.mk
include makefilesrc/var.mk

all: $(NAME)

$(NAME): $(LIB) .objects $(OFILES)
	@$(CC) -o $(NAME) $(OFILES) $(LIB) $(INCLUDES) $(FLAGS)
	@echo "$(NAME) compiled successfully"

.objects:
	@mkdir .objects

$(LIB):
	@make -C libft
	@echo "$(PLUS) $(LIB)"

.objects/%.o: source/%.c includes/lemin.h
	@$(CC) -o $@ -c $< $(INCLUDES) $(FLAGS)
	@echo "$(PLUS) $@"

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -rf .objects
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
