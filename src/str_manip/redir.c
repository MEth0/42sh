/*
** redir.c for redir in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/str_manip
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Mon Apr  4 16:40:36 2016 mathis rousselot
** Last update Sun Jun  5 18:48:51 2016 Morgan SIMON
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_sh.h"

t_redir	func_redir[] =
  {
    {&my_pipe, "|"},
    {&new_file, ">"},
    {&end_of_file, ">>"},
    {&check_keyword, "<<"},
    {&open_file, "<"},
  };

void    set_current(t_env *env)
{
  env->command[COM].in = 0;
  env->command[COM].out = 0;
  if ((CURRENT = malloc(sizeof(char *) *
			(my_arraylen(env->arg[ARG].arg) + 1))) == NULL)
    fatal_error_exit("Malloc failed\n");
  if (COM != 0)
    if (env->command[COM - 1].out == PIPE_OUT)
      env->command[COM].in = PIPE_IN;
  CURRENT[0] = NULL;
}

int	isend(t_env *env, int *curs)
{
  int	tmp;

  tmp = 0;
  while (tmp != 5)
    {
      if (env->arg[ARG].arg[(*curs)] == NULL)
	return (R_END);
      if (my_strcmp(func_redir[tmp].name, env->arg[ARG].arg[(*curs)]) == 0)
	{
	  if (func_redir[tmp].func(env, (*curs)) == ERROR)
	    return (ERROR);
	  if (tmp == 0)
	    return (PIPE);
	  else
	    {
	      (*curs) += 2;
	      tmp = -1;
	    }
	}
      tmp++;
    }
  return (0);
}

int	get_redir(t_env *env, int *tmp)
{
  int	check;

  if ((check = isend(env, &ARG_POS)) != NONE)
    {
      if (check == PIPE || check == R_END)
	{
	  env->command[COM].current[(*tmp)] = NULL;
	  (*tmp) = 0;
	  COM++;
	  if (check == R_END)
	    {
	      env->command[COM].out = NONE;
	      env->command[COM].in = END;
	    }
	  else
	    set_current(env);
	}
      if (check == ERROR)
	{
	  env->command[COM + 1].in = END;
	  env->command[COM].current[(*tmp)] = NULL;
	}
      ARG_POS++;
    }
  return (check);
}

void	send_redir(t_env *env)
{
  int   tmp;
  int	check;

  1 ? (ARG_POS = 0, COM = 0, tmp = 0) : 0;
  if ((env->command = malloc(sizeof(t_command) *
			     (my_arraylen(env->arg[ARG].arg) + 1))) == NULL)
    fatal_error_exit("Malloc failed\n");
  set_current(env);
  while (42)
    {
      env->path = get_name(env->env, "PATH");
      check = get_redir(env, &tmp);
      if (check == ERROR || check == R_END)
	{
	  pre_analyse(env);
	  return;
	}
      if (env->arg[ARG].arg[ARG_POS] != NULL && check != PIPE)
        {
          env->command[COM].current[tmp] = strdup(env->arg[ARG].arg[ARG_POS]);
          ARG_POS++;
	  tmp++;
        }
    }
}
