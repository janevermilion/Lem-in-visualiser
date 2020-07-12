
#include "lemin.h"
#include <stdio.h>
#include <stdlib.h>

t_lem_in	*ft_init_lem_in(void)
{
	t_lem_in	*lemin;

	if (!(lemin = (t_lem_in *)ft_memalloc(sizeof(t_lem_in))))
		RaiseError(0);
	lemin->ants = 0;
	lemin->commands = (char**)malloc(sizeof(char*) * 10);
	lemin->comments = (char**)malloc(sizeof(char*) * 10);
	lemin->rooms = NULL;
	lemin->cmd = 0;
	lemin->cmt = 0;
	lemin->ants = NULL;
	lemin->matrix = NULL;
	return (lemin);

}

int main(int argc, char **argv)

{
	char		*line;
	t_lem_in	*lem_in;
    int i;
    char *line_result;
    int lines;

    lines = 0;
    i = 0;
	lem_in = ft_init_lem_in();
    line_result = ft_strnew(1);///free
	while ((get_next_line(0,&line)) > 0)
	{
	    line = ft_strjoinfree_both(line,ft_strdup( "*"));
        line_result = ft_strjoinfree_both(line_result, line);
        lines++;
	}
    char **array_for_validity_check = ft_strsplit(line_result,'*');
    ft_memdel((void **) &line_result);
    while(array_for_validity_check[i])
    {
        printf("%s\n", array_for_validity_check[i]);
        i++;
    }
    if(i!=lines)
        RaiseError(1);
    else
        if(!(lem_in = check_validity_of_input_data(array_for_validity_check, lem_in)))
            RaiseError(2);
        else
            if(!get_solution(lem_in))
                RaiseError(3);
    return 0;
}