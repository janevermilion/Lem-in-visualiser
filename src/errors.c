//
// Created by janevermilion on 12.07.2020.
//

#include "lemin.h"
/*
 * add free al structures here
 */
void	RaiseError(int e)
{
    if(e== 0 || e == 1 || e ==1 || e == 3)
    {
        if(e== 0)
            ft_putstr(">>Malloc error, sorry...\n");
        else if(e ==1)
            ft_putstr(">>Parse error:bad symbols in input\n");
        else if(e ==2)
            ft_putstr(">>Input parse error\n");
        else if(e ==3)
            ft_putstr(">>No solution\n");
        exit(1);
    }
}


void        free_parseStructures(t_parsed_room **rooms, t_main_indexes *indexes, char **data)
{
    int i;
    int j;

    i = 0;
    ft_memdel((void **)&indexes);
    while (i < ft_arraylen((void **)data))
    {
        ft_memdel((void **)&data[i]);
        i++;
    }
    ft_memdel((void **)data);
    i = 0;
    while(rooms && i < ft_arraylen((void **)rooms))
    {
        i++;
        ft_memdel((void **)&rooms[i]->name);
        j = 0;
        while(j < ft_arraylen((void **)rooms[i]->conn))
        {
            ft_memdel((void **)&rooms[i]->conn[j]);
            j++;
        }
        ft_memdel((void **)&rooms[i]);
    }
    ft_memdel((void**) rooms);
}

void        parseError(int e, t_parsed_room **rooms, t_main_indexes *indexes, char **data)
{

        ft_putstr("ERROR\n");
        if(e== 0)
            ft_putstr(">>Parse error: malloc error, sorry...\n");
        else if(e ==1)
            ft_putstr(">>Parse error: no indexes to parse in this map.\n");
        else if(e ==2)
            ft_putstr(">>Parse error: wrong coordinates of room.\n");
        else if(e ==3)
            ft_putstr(">>Parse error: all coordinates have zero values.\n");
        else if(e == 4)
            ft_putstr(">>Parse error: non-existed room in paths-part\n");
        else if(e == 5)
            ft_putstr(">>Parse error: no ants or non-valid quantity of ants\n");
        else if(e == 6)
            ft_putstr(">>Parse error: no room in start or the end\n");
        else if(e == 7)
            ft_putstr(">>Parse error: not finded start/end/paths \n");
        else if(e == 8)
            ft_putstr(">>Parse error: start or end room inside paths part\n");
        else if(e == 9)
            ft_putstr(">>Parse error: no rooms in the map\n");
        free_parseStructures(rooms,indexes,data);
        exit(1);
}
