//
// Created by janevermilion on 15.07.2020.
//
#include "lemin.h"

char            *create_string_with_connections(char *conn, t_parsed_room **pRoom, t_parsed_room *curRoom)
{
    int i;
    int k;

    i = 0;
    while(pRoom[i])
    {
        k = 0;
        while (pRoom[i]->conn && (pRoom[i]->conn)[k])
        {
            if(ft_strcmp(pRoom[i]->conn[k], curRoom->name) == 0)
            {
                conn = ft_strjoinfree_s2(pRoom[i]->name, conn);
                conn = ft_strjoinfree_both(ft_strdup(","), conn);
            }
            k++;
        }
        i++;
    }
    return conn;
}

void check_connections_for_rooms(t_parsed_room **pRoom, char **data, t_main_indexes *indexes)
{
    int j;
    char *connections;

    connections = ft_strdup("");
    j = 0;

    while(pRoom[j])
    {
        if (!pRoom[j]->conn)
        {
            if(connections = create_string_with_connections(connections,pRoom, pRoom[j]))
            {
                pRoom[j]->conn = ft_strsplit(connections, ',');
                ft_memdel((void **)&connections);
            }

        }
        j++;
    }
    if(connections)
        ft_memdel((void **)&connections);
}

void create_connections_for_this_room(t_parsed_room *room, int j, char **data, int size)
{
    int ind;

    ind = 0;
    room->conn = (char **)ft_memalloc(sizeof(char *) * (size+1));
    while (data[j] && ind < size)
    {
        char *trimed = ft_strtrim(data[j]);
        char **splited_line = ft_strsplit(trimed, '-');
        if(splited_line[1] && splited_line[0])
        {
            if(ft_strcmp(room->name, splited_line[1]) == 0)
            {
                room->conn[ind] = ft_strdup(splited_line[0]);
                ind++;
            }
            else if(ft_strcmp(room->name, splited_line[0]) == 0)
            {
                room->conn[ind] = ft_strdup(splited_line[1]);
                ind++;
            }
        }
        ft_memdel((void **)&trimed);
        ft_free_2d_array((void **)splited_line);
        j++;
    }
    room->conn[ind] = NULL;
}

//fill_connections_for_rooms

int     free_lines_and_return_err(int err, char *trimed, char *trimed2, char **splited_line, char **splited_line2)
{
    ft_memdel((void **)&trimed);
    ft_free_2d_array((void **)splited_line);
    ft_memdel((void **)&trimed2);
    ft_free_2d_array((void **)splited_line2);
    return (err);
}

int     check_errors_for_current_line_path(char *datai, char *dataj, t_parsed_room **rooms_array, t_main_indexes *indexes)
{
    char *trimed;
    char **splited_line;
    char *trimed2;
    char **splited_line2;

    trimed = ft_strtrim(datai);
    splited_line = ft_strsplit(trimed, '-');
    trimed2 = ft_strtrim(dataj);
    splited_line2 = ft_strsplit(trimed2, '-');
    if(trimed2 && splited_line2[0] && splited_line2[1])
    {
        if(this_room_is_appeared(splited_line2[1], rooms_array) == -1 ||
           this_room_is_appeared(splited_line2[0], rooms_array) == -1)
            return free_lines_and_return_err(-4, trimed,trimed2,splited_line,splited_line2);
        else if(ft_strcmp(splited_line2[0], splited_line2[1]) ==0)
            return free_lines_and_return_err(-12, trimed,trimed2,splited_line,splited_line2);
        else if(ft_strcmp(splited_line2[1], splited_line[0]) == 0 ||
                ft_strcmp(splited_line2[0], splited_line[0]) == 0)
            return free_lines_and_return_err(1, trimed,trimed2,splited_line,splited_line2);
    }
    return free_lines_and_return_err(0, trimed,trimed2,splited_line,splited_line2);
}

void calculate_needed_size(char **data, int i, t_parsed_room **rooms_array, t_main_indexes *indexes, int ind)
{
    int needed_size;
    int j;
    int test;

    j = indexes->paths;

    needed_size = 0;
    while (data[j])
    {
        test = check_errors_for_current_line_path(data[i],data[j],rooms_array,indexes);
        if(test < 0)
            parseError(test*(-1), rooms_array,indexes,data);
        needed_size+=test;
        j++;
    }
    if(needed_size)
        create_connections_for_this_room(rooms_array[ind], indexes->paths, data, needed_size);
}


void   fill_connections_for_rooms(int i, t_parsed_room **rooms_array, char **data, t_main_indexes *indexes)
{
    int ind;
    char **splited_line;
    char *trimed;

    while (data[i])
    {
        if(data[i][0] != '#')
        {
            trimed = ft_strtrim(data[i]);
            splited_line = ft_strsplit(trimed, '-');
            if(trimed && splited_line && splited_line[0])
            {
                if(((ind = this_room_is_appeared(splited_line[0],rooms_array)) != -1 && ind != -5) && ft_arraylen((void **)splited_line) == 2)
                    calculate_needed_size(data, i,rooms_array, indexes, ind);
                else if(ind == -1)
                    parseError(4, rooms_array,indexes, data);
                ft_memdel((void **)&trimed);
                ft_free_2d_array((void **)splited_line);
            }
        }
        i++;
    }
}