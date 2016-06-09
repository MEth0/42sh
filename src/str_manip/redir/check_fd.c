/*
** check_fd.c for check_fd.c in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/str_manip/redir
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Apr  9 17:28:43 2016 mathis rousselot
** Last update Thu Jun  2 22:04:54 2016 mathis rousselot
*/

#include <stdlib.h>
#include "my_sh.h"

int	check_missing_name(t_env *env, int curs)
{
  if (env->arg[ARG].arg[curs + 1] == NULL)
    {
      env->command[COM].out = MISSING;
      return (-1);
    }
  if (my_strcmp(env->arg[ARG].arg[curs + 1], ">") == 0 ||
      my_strcmp(env->arg[ARG].arg[curs + 1], ">>") == 0 ||
      my_strcmp(env->arg[ARG].arg[curs + 1], "<") == 0 ||
      my_strcmp(env->arg[ARG].arg[curs + 1], "<<") == 0 ||
      my_strcmp(env->arg[ARG].arg[curs + 1], "|") == 0)
    {
      env->command[COM].out = MISSING;
      return (-1);
    }
  return (0);
}

int     check_fd_in(t_env *env, int curs)
{
  if (env->command[COM].in != 0)
    {
      env->command[COM].out = AMBIGOUS_IN;
      return (-1);
    }
  curs++;
  while (env->arg[ARG].arg[curs] != NULL && env->arg[ARG].arg[curs][0] != '|')
    {
      if (env->arg[ARG].arg[curs][0] == '<')
        {
	  env->command[COM].out = AMBIGOUS_IN;
          return (-1);
        }
      curs++;
    }
  return (0);
}

int     check_fd_out(t_env *env, int curs)
{
  if (env->command[COM].out != 0)
    {
      env->command[COM].out = AMBIGOUS_OUT;
      return (-1);
    }
  curs++;
  while (env->arg[ARG].arg[curs] != NULL && env->arg[ARG].arg[curs][0] != '|')
    {
      if (env->arg[ARG].arg[curs][0] == '>')
        {
	  env->command[COM].out = AMBIGOUS_OUT;
          return (-1);
        }
      curs++;
    }
  return (0);
}
