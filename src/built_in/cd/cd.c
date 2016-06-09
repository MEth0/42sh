/*
** cd.c for cd in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Fri Jan 22 19:01:39 2016 mathis rousselot
** Last update Sun Jun  5 11:10:08 2016 mathis rousselot
*/

#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_sh.h"

int	acces_dir(char *str, t_env *env)
{
  int	error;
  char	*av[4];

  error = 0;
  if (accessible(str, env->current[1]) == 0)
    {
      av[0] = "setenv\0";
      av[1] = "OLDPWD\0";
      av[2] = getcwd(NULL, 0);
      av[3] = NULL;
      if (get_name(env->env, "OLDPATH\0") == -1)
        error = my_setenv(av, env);
      free(av[2]);
      chdir(str);
      av[1] = "PWD\0";
      av[2] = getcwd(NULL, 0);
      error = my_setenv(av, env);
      free(av[2]);
    }
  else
    error = 1;
  return (error);
}

int	go_home(t_env *env)
{
  char	*str;
  int	error;
  int	curs;

  if ((curs = get_name(env->env, "HOME\0")) == -1)
    return (0);
  if (env->env[curs][5] == '\0')
    return (0);
  str = get_str_name(env->env[curs]);
  error = acces_dir(str, env);
  free(str);
  return (error);
}

int	normal(t_env *env)
{
  char  *str;
  int	curs;
  int	error;

  if ((curs = get_name(env->env, "PWD\0")) == -1)
    return (0);
  if (env->env[curs][5] == '\0')
    return (0);
  str = get_directory(env->current[1], env->env[curs]);
  error = acces_dir(str, env);
  free(str);
  return (error);
}

int	change_directory(t_env *env)
{
  int	error;

  if (env->current[1][0] == '/')
    error = go_root(env);
  else if (env->current[1][0] == '-')
    error = go_oldpath(env);
  else if (env->current[1][0] == '~')
    error = go_since_home(env);
  else
    {
      no_quote(env->current);
      error = normal(env);
    }
  return (error);
}

int	my_cd(t_env *env)
{
  int	error;

  error = 0;
  if (my_arraylen(env->current) > 2)
    fprintf(stderr, "cd: Too many arguments.\n");
  else if (my_arraylen(env->current) < 2)
    error = go_home(env);
  else
    error = change_directory(env);
  return (error);
}
