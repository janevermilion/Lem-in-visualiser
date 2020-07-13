//
// Created by janevermilion on 13.07.2020.
//

#include "libft.h"

int 	ft_is_int(char *str)
{
    int 	i;

    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}