//
// Created by janevermilion on 12.07.2020.
//


#include "lemin.h"



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





