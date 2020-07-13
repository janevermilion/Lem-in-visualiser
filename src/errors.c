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