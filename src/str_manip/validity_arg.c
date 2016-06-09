/*
** validity_arg.c for validity_arg in /home/rousse-i/rendu/PSU/PSU_2015_42sh/src/str_manip
**
** Made by mathis rousselot
** Login   <rousse-i@epitech.net>
**
** Started on  Sun May 29 23:32:14 2016 mathis rousselot
** Last update Sun Jun  5 19:00:55 2016 mathis rousselot
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_sh.h"

int	invalid_argument(t_env *env, int curs)
{
  if (env->arg[curs].flag == OR || env->arg[curs].flag == AND)
    if (env->arg[curs + 1].flag == -1)
      {
	fprintf(stderr, "Invalid null command.\n");
	return (1);
      }
  return (0);
}

int	not_a_comm(char c)
{
  if (c == '<' || c == '>')
    return (1);
  return (0);
}

int	missing_name(t_env *env, int curs, int curs_2)
{
  if (env->arg[curs].arg[curs_2] == NULL
      || env->arg[curs].arg[curs_2][0] == '|')
    {
      fprintf(stderr, "Missing name for redirect.\n");
      return (1);
    }
  return (0);
}

int     invalid_comment(t_env *env, int curs, int curs_2)
{
  int	check;

  while (env->arg[curs].arg[curs_2] != NULL)
    {
      check = 0;
      while (env->arg[curs].arg[curs_2] != NULL
	     && env->arg[curs].arg[curs_2][0] != '|')
	{
	  if (not_a_comm(env->arg[curs].arg[curs_2][0]) == 1)
	    curs_2++;
	  else
	    check++;
	  if (missing_name(env, curs, curs_2) == 1)
	    return (1);
	  curs_2++;
	}
      if (check == 0)
	{
	  fprintf(stderr, "Invalid null command.\n");
	  return (1);
	}
      (env->arg[curs].arg[curs_2] != NULL) ? (curs_2++) : 0;
    }
  return (0);
}

int     check_validity_arg(t_env *env)
{
  int   curs;

  curs = 0;
  while (env->arg[curs].flag != -1)
    {
      env->arg[curs].exit = NO_EXIT;
      if (invalid_argument(env, curs) == 1)
	{
	  env->retrn = 1;
	  free_arg(env->arg);
	  return (1);
	}
      if (invalid_comment(env, curs, 0) == 1)
	{
	  free_arg(env->arg);
	  env->retrn = 1;
	  return (1);
	}
      curs++;
    }
  return (0);
}
