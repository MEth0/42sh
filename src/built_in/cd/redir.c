/*
** redir.c for redir.c in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Jan 23 18:06:56 2016 mathis rousselot
** Last update Wed Jun  8 09:24:30 2016 mathis rousselot
*/

#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_sh.h"

int     accessible(char *str, char *dir)
{
  if (opendir(str) == NULL)
    {
      if (errno == ENOTDIR && dir != NULL)
	fprintf(stderr, "%s: Not a directory.\n", dir);
      if (errno == ENOENT && dir != NULL)
	fprintf(stderr, "%s: No such file or directory.\n", dir);
      if (errno == EACCES && dir != NULL)
	fprintf(stderr, "%s: Permission denied.\n", dir);
      return (1);
    }
  return (0);
}

int	go_root(t_env *env)
{
  int	error;

  error = acces_dir(env->current[1], env);
  return (error);
}

int	go_oldpath(t_env *env)
{
  char  *str;
  int	error;
  int	curs;

  if ((curs = get_name(env->env, "OLDPWD\0")) == -1)
    return (0);
  if (env->env[curs][8] == '\0')
    return (0);
  str = get_str_name(env->env[curs]);
  error = acces_dir(str, env);
  free(str);
  return (error);
}

int	go_since_home(t_env *env)
{
  char  *str;
  int	curs;
  int	error;

  if ((curs = get_name(env->env, "HOME\0")) == -1)
    return (0);
  if (env->env[curs][5] == '\0')
    return (0);
  str = get_directory(env->current[1], env->env[curs]);
  error = acces_dir(str, env);
  free(str);
  return (error);
}
