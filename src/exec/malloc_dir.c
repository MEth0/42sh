/*
** malloc_dir.c for malloc_dir in /home/rousse-i/rendu/PSU/PSU_2015_42sh/src/exec
**
** Made by mathis rousselot
** Login   <rousse-i@epitech.net>
**
** Started on  Thu Jun  2 13:57:12 2016 mathis rousselot
** Last update Thu Jun  2 14:02:09 2016 mathis rousselot
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_sh.h"

char    *dir_malloc_path(char *prog, char *path, int curs)
{
  char  *dir;

  if ((dir = malloc(sizeof(char) *
		    (my_strlen(prog) +
		     my_strlen(path) +
		     curs))) == NULL)
    fatal_error_exit("Malloc failed\n");
  return (dir);
}

char    *dir_malloc_prog(char *prog, char *path, int curs, char *dir)
{
  char  *cwd;

  free(dir);
  if ((cwd = getcwd(NULL, 0)) == NULL)
    return (NULL);
  if ((dir = malloc(sizeof(char) *
		    (my_strlen(prog) +
		     my_strlen(path) +
		     curs + my_strlen(cwd)))) == NULL)
    fatal_error_exit("Malloc failed\n");
  free(cwd);
  return (dir);
}
