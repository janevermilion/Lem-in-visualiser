
#include "lemin.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>

t_lem_in	*ft_init_lem_in(void)
{
	t_lem_in	*lemin;

	if (!(lemin = (t_lem_in *)ft_memalloc(sizeof(t_lem_in))))
		RaiseError(0);
	lemin->ants = 0;
	lemin->commands = (char**)malloc(sizeof(char*) * 10);
	lemin->comments = (char**)malloc(sizeof(char*) * 10);
	lemin->rooms = NULL;
	lemin->cmd = 0;
	lemin->cmt = 0;
	lemin->ants = NULL;
	lemin->matrix = NULL;
	return (lemin);

}

int main(int argc, char *argv[])

{
	int 		fd;
    int 		fd1;
	int fd2;
	char		*line;
	int 		i;
	int 		count;
	t_lem_in	*lem_in;

/*
	fd1 = open("test.txt", O_RDONLY);//mac
	printf("fd is: %i\n", fd1);
*/
	i = 0;
	lem_in = ft_init_lem_in();

    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, mode);
    printf("fd is: %i\n", fd);/////this is linux fd bitch


	while ((get_next_line(fd, &line)) == 1)
	{
	    printf("%s\n", line);
	    free(line);

	    /*
		if (is_comment(line, i))
		{
			add_comment(lem_in, line, i);
		}
		if (is_command(line, i))
		{
			add_command(lem_in, line, i);
		}
		if (is_ants(line, i))
		{
			add_ant(lem_in, line, i);
		}
		if (is_room(ft_strsplit(line, ' ')))
		{
			add_room(lem_in, ft_strsplit(line, " "), i);
		}*/
		i++;

	}
	if(i == 0)
	    printf("PROBLEM WITH GNL BITCH\n");//for jane

    char st1[100];
    char st2[100];
//определяем указатель на файл
    FILE *fin;
// настриваем работу с Кириллицей
    setlocale(LC_ALL, "Russian");
// открываем файл на чтение
    fin =  open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, mode);
// считываем первую строку из файла
    if ( NULL != fgets ( st1, 100, fin ) )
    {
// выводим строку на экран
        printf("%s ",st1);}
// считываем вторую строку из файла
    if ( NULL != fgets ( st2, 100, fin ) )
    {
// выводим строку на экран
        printf("%s\n",st2);}
// закрываем файл на чтение
    fclose(fin);
	return 0;
}