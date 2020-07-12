//
// Created by janevermilion on 12.07.2020.
//

#include "lemin.h"

void	add_comment(t_lem_in *lem_in, char *line, int i)
{
    int 	a;

    if (lem_in->cmt == 0)
        lem_in->comments[0] = ft_strjoin(ft_strdup(line), ft_itoa(i));
    else
    {
        a = 0;
        while (a < lem_in->cmt)
            a++;
        lem_in->commands[a] = ft_strjoin(ft_strdup(line), ft_itoa(i));
    }
}

void	add_command(t_lem_in *lem_in, char *line, int i)
{
    int 	a;

    if ((ft_strcmp(line, "##end") == 0) || (ft_strcmp(line, "##start") == 0))
        if (lem_in->cmd == 0)
            lem_in->commands[0] = ft_strjoin(ft_strdup(line), ft_itoa(i));
        else
        {
            a = 0;
            while (a < lem_in->cmd)
                a++;
            lem_in->commands[a] = ft_strjoin(ft_strdup(line), ft_itoa(i));
        }
}

void	add_ant(t_lem_in *lem_in, char *line, int z)
{
    int 	i;
    t_ant	*ants;

    lem_in->count_of_ants = ft_atoi(line);
    i = 0;
    ants = (t_ant*)malloc(sizeof(t_ant));
    lem_in->ants = ants;
    while (i < lem_in->count_of_ants)
    {
        ants->next = (t_ant*)malloc(sizeof(t_ant));
        ants->curr_room = 0;
        ants->index = i;
        ants = ants->next;
        i++;
    }
    ants->next = NULL;
}

void	add_stroke(t_lem_in *lem_in)
{
    lem_in->matrix = (int**)malloc(sizeof(int*) * 10);
}

void	add_room(t_lem_in *lem_in, char **line, int i)
{
    if (!(lem_in->matrix))
        add_stroke(lem_in);

}