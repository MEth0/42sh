/*
** 42shrc.c for 42sh in /home/desria-m/rendu/PSU/PSU_2015_42sh
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu Jun  2 18:25:57 2016 Desriac
** Last update Sun Jun  5 16:29:34 2016 mathis rousselot
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_sh.h"

int	shrc(t_env *env)
{
  char	*str;
  int	fd;
  int	check;

  check = 0;
  if ((fd = open(".42shrc", O_RDONLY)) < 0)
      return (0);
  while ((str = get_next_line(fd)) != NULL && check == 0)
    {
      my_signal();
      if (str[0] != '\0')
      	check = parsing(str, env);
      else
	free(str);
      close_final(env);
    }
  close(fd);
  return (0);
}
