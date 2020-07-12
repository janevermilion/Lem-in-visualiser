//
// Created by janevermilion on 12.07.2020.
//

#include "lemin.h"

int 	ft_is_int(char *str)
{
    int 	i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int		ft_strsplit_len(char **line)
{
    int 	i;

    i = 0;
    while (line[i])
        i++;
    return (i);
}

int 	is_room_name(char *line)
{
    if (line && ft_strlen(line))
    {
        if (line[0] != 'L' && line[0] != '#')
            return (1);
    }
    return (0);
}

int 	is_room(char **line)
{
    if (ft_strsplit_len(line) == 3 && is_room_name(line[0]) && ft_is_int(line[1]) && ft_is_int(line[2]))
        return (1);
    else
        return (0);
}

int 	is_command(char *line, int i)
{
    if ((ft_strlen(line) >= 2) && !ft_strncmp(line, "##", 2))
        return (1);
    return (0);
}

int 	is_comment(char *line, int i)
{
    if (ft_strlen(line) && !is_command(line, i) && !ft_strncmp(line, "#", 1))
        return (1);
    return (0);
}

int 	is_ants(char *line, int i)
{
    if (ft_is_int(line))
        return (1);
    return (0);
}