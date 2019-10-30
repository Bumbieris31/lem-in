#include "lem-in.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void		print_file(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while(ft_get_next_line(fd, &line))
	{
		if (line[0] == '#' && (!ft_strequ("##start", line) && !ft_strequ("##end", line)))
			;
		else
			ft_putendl(line);
		free(line);
	}
	ft_putendl("");
	close(fd);
}
