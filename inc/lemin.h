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

typedef struct      s_parsed_room
{
    int ants;//quant of ants
    int x;//coord x
    int y;//coord y
    char *name;//name of room
    int type;//type -1 -error, type 1 start,type 2 normal,type3 end
    char **conn;//array with all connections of this room

}                   t_parsed_room;
typedef struct s_main_indexes
{
    int start_room;
    int end_room;
    int paths;
    int commented_lines;
    int paths_count;
    int ants;
    int rooms;
}               t_main_indexes;
/*
 * errors.c
 */
void	RaiseError(int e);
void        parseError(int e, t_parsed_room **rooms, t_main_indexes *indexes, char **data);
/*
 * add_comment-room-ant.c
 */
void	add_comment(t_lem_in *lem_in, char *line, int i);
void	add_command(t_lem_in *lem_in, char *line, int i);
void	add_ant(t_lem_in *lem_in, char *line, int i);
void	add_stroke(t_lem_in *lem_in);
void	add_room(t_lem_in *lem_in, char **line, int i);
/*
 * parse-validity-utils.c
 */
void check_connections_for_rooms(t_parsed_room **pRoom, char **data, t_main_indexes *indexes);
t_parsed_room **memory_allocate_for_rooms_array(t_parsed_room **pRoom, int quantRooms);
void create_connections_for_this_room(t_parsed_room *room, int j, char **data, int size);
int if_all_coordinates_is_zero(t_parsed_room **pRoom);
t_main_indexes *find_indexes(char **data, t_main_indexes *indexes);
void print_rooms_array(t_parsed_room **pRoom);
int this_room_is_appeared(char *room, t_parsed_room **rooms);
/*
 * parse-validity-main.c
 */
t_parsed_room    **check_validity_of_input_data(char **data);

#endif
