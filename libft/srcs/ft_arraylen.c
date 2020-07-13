//
// Created by janevermilion on 13.07.2020.
//

#include "libft.h"

int         ft_arraylen(void **array)
{
    int i;
    i = 0;
    while (array[i])
    {
        char *test = array[i];
        i++;
    }

    return i;
}