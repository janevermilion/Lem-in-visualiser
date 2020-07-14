//
// Created by janevermilion on 12.07.2020.
//


#include "lemin.h"

t_main_indexes *find_indexes(char **data, t_main_indexes *indexes)
{
    int i;
    if (!(indexes = (t_main_indexes *)ft_memalloc(sizeof(t_main_indexes))))
        parseError(1, NULL, indexes, data);
    i = 1;
    indexes->end_room = -1;
    indexes->start_room = -1;
    indexes->paths = -1;
    indexes->commented_lines = 0;
    indexes->paths_count = 0;
    indexes->ants = 0;
    if(ft_is_int(data[0]) == 1)
        indexes->ants = ft_atoi(data[0]);
    if(indexes->ants <= 0)
        parseError(5, NULL, indexes, data);
    while(data[i])
    {
        if(ft_strstr(data[i], "-") != NULL && data[i][0] != '#')
        {
            if(indexes->paths == -1)
                indexes->paths = i;
            indexes->paths_count++;
        }
        i++;
    }
    i = 1;
    while(data[i])
    {
        if(data[i][0] == '#')
            indexes->commented_lines++;
        if(ft_strcmp(data[i],"##start") == 0)
        {
            if(indexes->start_room != -1 || data[i+1] == NULL)
                parseError(6, NULL, indexes, data);
            indexes->start_room = i+1;
            i++;
        }
        else if(ft_strcmp(data[i],"##end") == 0)
        {
            if(indexes->end_room != -1 || data[i+1] == NULL)
                parseError(6, NULL, indexes, data);
            indexes->end_room = i+1;
            i++;
        }
        i++;
    }

    if(indexes->paths == -1 || indexes->start_room == -1 || indexes->end_room == -1)
        parseError(7, NULL, indexes, data);
    if(indexes->start_room >= indexes->paths || indexes->end_room >= indexes->paths)
        parseError(8, NULL, indexes, data);
    return indexes;
}


void print_rooms_array(t_parsed_room **pRoom) {
    int i;
    int j;

    i = 0;
    printf("PARSER INFO FOR JTERRELL:\n");
    printf("Quantity of ants: %i\n", pRoom[0]->ants);
    printf("Quantity of rooms: %i\n", ft_arraylen((void **)pRoom));
    printf("Rooms:\n");
    while (pRoom[i])
    {
        printf("   name: %s\n", pRoom[i]->name);
        printf("   coordinates: x:%i, y:%i\n", pRoom[i]->x, pRoom[i]->y);
        char *type;
        if(pRoom[i]->type == 1)
            type = "start";
        if(pRoom[i]->type == 2)
            type = "normal";
        if(pRoom[i]->type == 3)
            type ="end";
        if(pRoom[i]->type == -1)//////////del
            type ="later";//////////
        printf("   type: %s\n", type);
        printf("      connected with rooms: ");
        j = 0;
        if(pRoom[i]->conn)
        {
            while((pRoom[i]->conn)[j])
            {
                printf("%s ", (pRoom[i]->conn)[j]);
                j++;
            }

        }
        printf("\n--------\n");
        i++;
    }
    printf("\n");
}

int this_room_is_appeared(char *room, t_parsed_room **rooms)
{
    int i;
    i = 0;
    while (rooms[i])
    {
        if(ft_strcmp(room, rooms[i]->name) == 0)
        {
            if(!rooms[i]->conn)
                return (i);
            else
                return -5;
        }

        i++;
    }
    return -1;
}

t_parsed_room **memory_allocate_for_rooms_array(t_parsed_room **pRoom, int quantRooms)
{
    int i;

    i = 0;
    pRoom = (t_parsed_room **)ft_memalloc(sizeof(t_parsed_room *) * (quantRooms + 1));
    if(!pRoom)
        return NULL;
    while (i < quantRooms)
    {
        pRoom[i] = (t_parsed_room *)ft_memalloc(sizeof(t_parsed_room));
        if(!pRoom[i])
            return NULL;
        pRoom[i]->ants = -1;
        pRoom[i]->x = -1;
        pRoom[i]->y = -1;
        pRoom[i]->name = NULL;
        pRoom[i]->type = -1;
        pRoom[i]->conn = NULL;
        i++;
    }
    pRoom[i] = NULL;
    return pRoom;
}

int if_all_coordinates_is_zero(t_parsed_room **pRoom) {
    int i;
    int zeroes;

    zeroes = 0;
    i = 0;
    while(pRoom[i])
    {
        if(pRoom[i]->x == 0 && pRoom[i]->y == 0)
            zeroes++;
        else
            return (0);
        i++;
    }
    if(zeroes == i)
        return (1);
    return (1);
}

void check_connections_for_rooms(t_parsed_room **pRoom, char **data, t_main_indexes *indexes) {
    int i;
    int j;
    int k;
    char *connections;

    connections = ft_strdup("");
    j = 0;


    while(pRoom[j])
    {
        if (!pRoom[j]->conn)
        {
            i = 0;
            while(pRoom[i])
            {
                k = 0;
                while (pRoom[i]->conn && (pRoom[i]->conn)[k])
                {
                    if(ft_strcmp(pRoom[i]->conn[k], pRoom[j]->name) == 0)
                    {
                        connections = ft_strjoinfree_s2(pRoom[i]->name, connections);
                        connections = ft_strjoinfree_s2(",", connections);
                    }
                    k++;
                }
                i++;
            }
            pRoom[j]->conn = ft_strsplit(connections, ',');
            ///freee connections
        }

        j++;
    }
}


void create_connections_for_this_room(t_parsed_room *room, int j, char **data, int size)
{
    int ind;
    ind = 0;
    room->conn = (char **)ft_memalloc(sizeof(char *) * (size+1));
    while (data[j] && ind < size)
    {
        char *trimed = ft_strtrim(data[j]);
        char **splited_line = ft_strsplit(trimed, '-');///freeeee
        if(splited_line[1] && splited_line[0])
        {
            if(ft_strcmp(room->name, splited_line[1]) == 0)
            {
                (room->conn)[ind] = ft_strdup(splited_line[0]);
                ind++;
            }
            else if(ft_strcmp(room->name, splited_line[0]) == 0)
            {
                (room->conn)[ind] = ft_strdup(splited_line[1]);
                ind++;
            }
        }

        j++;
    }
    (room->conn)[ind] = NULL;
}



