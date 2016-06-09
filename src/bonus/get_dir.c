/*
** get_dir.c for 42sh in /home/desria-m/rendu/PSU/PSU_2015_42sh
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sat Jun  4 16:30:51 2016 Desriac
** Last update Sat Jun  4 19:14:32 2016 Desriac
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

char	**get_dir(char *path)
{
  int		i;
  DIR           *rep;
  struct dirent *read;
  char		**dir;

  dir = NULL;
  i = 0;
  if ((rep = opendir(path)) == NULL)
    return (NULL);
  while ((read = readdir(rep)) != NULL)
    {
      if ((dir = realloc(dir, sizeof(char*) * (i + 2))) == NULL)
	return (NULL);
      dir[i] = strdup(read->d_name);
      dir[++i] = NULL;
    }
  closedir(rep);
  if (i == 0)
    return (NULL);
  return (dir);
}
