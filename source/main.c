#include "lem-in.h"
#include "ft_printf.h"

int				main(int argc, char **argv)
{
	if (argc != 2)
		ft_printf("usage: %s <filename>\n", argv[0]);
	else
		lemin(argv[1]);
	return (0);
}
