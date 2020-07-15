//
// Created by janevermilion on 14.07.2020.
//
#include "libft.h"

void 					ft_free_2d_array(void **array)
{
    int i;
    int len_of_array;

    i = 0;
    if(array)
    {
        len_of_array = ft_arraylen(array);
        if(len_of_array)
            while (i < len_of_array)
            {
                ft_memdel((void **)&array[i]);
                i++;
            }
         if(array)
             free(array);
    }
    array = NULL;
}
