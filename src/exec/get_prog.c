/*
** get_prog.c for get_prog in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Wed Jan 20 12:26:22 2016 mathis rousselot
** Last update Fri Jun  3 15:48:58 2016 mathis rousselot
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_sh.h"

void    create_path(char *prog, char *path, int *curs, char *dir)
{
  int   curs_2;
  int   curs_3;

  curs_2 = 0;
  curs_3 = 0;
  while (path[(*curs)] != '\0' && path[(*curs)] != ':')
    {
      dir[curs_2] = path[(*curs)];
      (*curs)++;
      curs_2++;
    }
  dir[curs_2] = '/';
  curs_2++;
  while (prog[curs_3] != '\0')
    {
      dir[curs_2] = prog[curs_3];
      curs_2++;
      curs_3++;
    }
  dir[curs_2] = '\0';
}

int	different_prog(char *dir, char *prog)
{
  int	curs;
  char	*str;

  curs = 0;
  dir[0] = '\0';
  str = getcwd(NULL, 0);
  dir = str_copy_end(dir, str, 1);
  dir[my_strlen(dir) + 1] = '\0';
  dir[my_strlen(dir)] = '/';
  dir = str_copy_end(dir, prog, 0);
  if (access(dir, O_RDONLY) != -1 && prog[0] == '.' && prog[1] == '/')
    return (0);
  while (prog[curs] != '\0')
    {
      if (prog[curs] == '/')
	return (2);
      curs++;
    }
  return (1);
}

int     different_path(char *dir, char *prog, int *curs)
{
  int	curs_2;

  curs_2 = 0;
  (*curs) = 4;
  dir[0] = '\0';
  dir = str_copy_end(dir, prog, 0);
  while (dir[curs_2] != '\0' && dir[curs_2] != '/')
    curs_2++;
  if (dir[curs_2] == '\0')
    return (1);
  if (access(dir, O_RDONLY) != -1)
    return (0);
  return (1);
}

char    *search_prog(char *prog, char *path, int exit, int curs)
{
  char  *dir;
  int   fd;

  if ((dir = dir_malloc_path(prog, path, curs)) == NULL)
    return (NULL);
  if (different_path(dir, prog, &curs) == 0)
    return (dir);
  if ((dir = dir_malloc_prog(prog, path, curs, dir)) == NULL)
    return (NULL);
  if (different_prog(dir, prog) == 0)
    return (dir);
  if (different_prog(dir, prog) == 2)
    {
      free(dir);
      return (NULL);
    }
  while (path[curs] != '\0')
    {
      1 ? (curs++, create_path(prog, path, &curs, dir)) : 0;
      1 ? (fd = access(dir, O_RDONLY), exit += (fd != -1 ? 1 : 0)) : 0;
      if (exit == 1)
        return (dir);
    }
  free(dir);
  return (NULL);
}

char	*lobby(t_env *env, int arg)
{
  int	curs;
  char	*dir;

  curs = 0;
  curs = get_name(env->env, "PWD");
  if (curs != -1)
    {
      curs = my_strlen(env->env[curs]);
      if ((dir = malloc(my_strlen(env->command[arg].current[0])
			+ curs)) == NULL)
	fatal_error_exit("Malloc failed\n");
      if (different_path(dir, env->command[arg].current[0], &curs) == 0)
	return (dir);
      free(dir);
      curs = my_strlen(env->env[get_name(env->env, "PWD")]);
    }
  if (env->path == -1)
    return (NULL);
  if (env->env[env->path][5] == '\0')
    return (NULL);
  return (search_prog(env->command[arg].current[0],
		      env->env[env->path], 0, curs));
}
