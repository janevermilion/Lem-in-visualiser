//
// Created by janevermilion on 12.07.2020.
//

#include "lemin.h"

void	RaiseError(int e)
{
    if (e == 0)
    {
        ft_putstr(">>Malloc error, sorry...\n");
        exit(1);
    }
}