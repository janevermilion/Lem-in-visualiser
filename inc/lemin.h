//
// Created by janevermilion on 12.07.2020.
//
#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <float.h>
# include <fcntl.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

typedef struct		s_ant
{
    int 			index;
    int 			curr_room;
    struct s_ant	*next;
}					t_ant;

typedef struct		s_lem_in
{
    int 	*rooms;
    t_ant	*ants;
    char	**commands;
    char 	**comments;
    int 	cmd;
    int 	cmt;
    int 	count_of_ants;
    int 	**matrix;
}					t_lem_in;

typedef struct		s_room
{
    int 			ant;
    int				x;
    int				y;
    int 			name;
    int 			*output;
    int 			*input;
    struct s_room	*next;
}					t_room;

typedef struct      s_parser
{
    char *rooms;
    int     quant_ants;
    char *paths;
    int index_of_paths_list_starting;


}                   t_parser;

/*
 * errors.c
 */
void	RaiseError(int e);
/*
 * add_comment-room-ant.c
 */
void	add_comment(t_lem_in *lem_in, char *line, int i);
void	add_command(t_lem_in *lem_in, char *line, int i);
void	add_ant(t_lem_in *lem_in, char *line, int i);
void	add_stroke(t_lem_in *lem_in);
void	add_room(t_lem_in *lem_in, char **line, int i);
/*
 * parse-validity.c
 */
int 	ft_is_int(char *str);
int		ft_strsplit_len(char **line);
int 	is_room_name(char *line);
int 	is_room(char **line);
int 	is_command(char *line, int i);
int 	is_comment(char *line, int i);
int 	is_ants(char *line, int i);

#endif
