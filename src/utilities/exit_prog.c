/*
** exit_prog.c for exit_prog in /home/rousse-i/rendu/PSU/PSU_2015_42sh/src/utilities
**
** Made by mathis rousselot
** Login   <rousse-i@epitech.net>
**
** Started on  Tue May 31 14:41:39 2016 mathis rousselot
** Last update Sun Jun  5 21:01:15 2016 mathis rousselot
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_sh.h"

void    check_exit(t_env *env)
{
  if (env->arg[ARG].exit != NO_EXIT && env->exit == NO_EXIT)
    {
      env->exit = env->arg[ARG].exit;
      if (env->arg[ARG].exit == ARG_EXIT)
	env->value = env->arg[ARG].value;
    }
}

void    close_prog(t_env *env)
{
  if (compare("exit", env->current[0]) == 1 &&
      my_arraylen(env->current) <= 2 && nbr_check(env->current[1]))
    {
      if (env->current[1] != NULL)
	{
	  env->arg[ARG].exit = ARG_EXIT;
	  env->arg[ARG].value = my_getnbr(env->current[1]);
	}
      else
	env->arg[ARG].exit = SIMPLE_EXIT;
    }
}

void	free_alias(t_env *env)
{
  int	i;

  if (env->alias == NULL)
    return;
  i = 0;
  while (i != env->nb_alias)
    {
      free_double(env->alias[i].command);
      free(env->alias[i].s_command);
      i++;
    }
  free(env->alias);
}

void    close_final(t_env *env)
{
  if (env->exit != NO_EXIT)
    {
      if (env->fd.fd_hist != -1)
	close(env->fd.fd_hist);
      free_double(env->env);
      free_alias(env);
      if (env->exit == ARG_EXIT)
	exit(env->value);
      else
	exit(env->retrn);
    }
}
