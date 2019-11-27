NAME = lem-in
INCLUDES = -Iincludes -Ilibft/includes
CFILES = $(SOURCE:%=source/%.c)
OFILES = $(SOURCE:%=.objects/%.o)
LIB = libft/printflibft.a
FLAGS = -Wall -Wextra -Werror
OPT = -O3 -funroll-loops -g
