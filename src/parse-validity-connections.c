/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-validity-connections.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:57:49 by jslave            #+#    #+#             */
/*   Updated: 2020/07/15 18:57:49 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
//5
int		free_lines_and_return_err(int err, char *trimed, char *trimed2, char **splited_line, char **splited_line2)
{
	ft_memdel((void **)&trimed);
	ft_free_2d_array((void **)splited_line);
	ft_memdel((void **)&trimed2);
	ft_free_2d_array((void **)splited_line2);
	return (err);
}

int		check_errors_for_current_line_path(char *datai, char *dataj, t_parsed_room **rooms_array, t_main_indexes *indexes)
{
	char *trimed;
	char **splited_line;
	char *trimed2;
	char **splited_line2;

	trimed = ft_strtrim(datai);
	splited_line = ft_strsplit(trimed, '-');
	trimed2 = ft_strtrim(dataj);
	splited_line2 = ft_strsplit(trimed2, '-');
	if (trimed2 && splited_line2[0] && splited_line2[1])
	{
		if (this_room_is_appeared(splited_line2[1], rooms_array) == -1 ||
		this_room_is_appeared(splited_line2[0], rooms_array) == -1)
			return (free_lines_and_return_err(-4, trimed, trimed2, splited_line, splited_line2));
		else if (ft_strcmp(splited_line2[0], splited_line2[1]) == 0)
			return (free_lines_and_return_err(-12, trimed, trimed2, splited_line, splited_line2));
		else if (ft_strcmp(splited_line2[1], splited_line[0]) == 0 ||
				ft_strcmp(splited_line2[0], splited_line[0]) == 0)
			return (free_lines_and_return_err(1, trimed, trimed2, splited_line, splited_line2));
	}
	return (free_lines_and_return_err(0, trimed, trimed2, splited_line, splited_line2));
}
//5
void	calculate_needed_size(char **data, int i, t_parsed_room **rooms_array, t_main_indexes *indexes, int ind)
{
	int		needed_size;
	int		j;
	int		test;

	j = indexes->paths;
	needed_size = 0;
	while (data[j])
	{
		test = check_errors_for_current_line_path(data[i], data[j], rooms_array, indexes);
		if (test < 0)
			parseError(test * (-1), rooms_array, indexes, data);
		needed_size += test;
		j++;
	}
	if (needed_size)
		create_connections_for_this_room(rooms_array[ind], indexes->paths, data, needed_size);
}

void	fill_connections_for_rooms(int i, t_parsed_room **rooms_array, char **data, t_main_indexes *indexes)
{
	int		ind;
	char	**splited_line;
	char	*trimed;

	while (data[i])
	{
		if (data[i][0] != '#')
		{
			trimed = ft_strtrim(data[i]);
			splited_line = ft_strsplit(trimed, '-');
			if (trimed && splited_line && splited_line[0])
			{
				if (((ind = this_room_is_appeared(splited_line[0], rooms_array)) != -1 && ind != -5) && ft_arraylen((void **)splited_line) == 2)
					calculate_needed_size(data, i, rooms_array, indexes, ind);
				else if (ind == -1)
					parseError(4, rooms_array, indexes, data);
				ft_memdel((void **)&trimed);
				ft_free_2d_array((void **)splited_line);
			}
		}
		i++;
	}
}
