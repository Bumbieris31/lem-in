#include "lem-in.h"

void	add_to_paths(t_link **paths, t_link *new_path, int path_id)
{
	if (!paths || !new_path)
		return ;
	new_path->next = *paths;
	*paths = new_path;
	(*paths)->id = path_id;
}

void		lemin(void)
{
	t_lemin *lemin;

	lemin = MEM(t_lemin);
	lemin->winner = MEM(t_path);
	get_map_info(lemin);
	PATHS = get_path(lemin);
	if (!PATHS)
		error_check(NO_PATH_ERROR);
	PATHS->id = 1;
	if (PATHS->ptr->id == END->id)
	{
		START->to = END;
		START->path = 1;
	}
	count_lines(lemin);
	if (lemin->ants > 1)
		find_solution(lemin);
	print_all_paths(PATHS, END, START->name);
	ft_printf("ANTS : %d\nLINES : %d\n", lemin->ants, WINNER->lines	);
	// print_map(&lemin->map, lemin->ants);
	// print_winner();
	// free_lemin_struct(lemin);
}
