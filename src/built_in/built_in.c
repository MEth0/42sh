/*
** built_in.c for built_in in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Wed Jan 20 18:23:24 2016 mathis rousselot
** Last update Thu Jun  2 16:07:03 2016 Desriac
*/

#include <stdlib.h>
#include "my_sh.h"

int     my_echo(t_env *env);

t_func  g_func[] =
  {
    {&my_cd, "cd"},
    {&display_env, "env"},
    {&message_exit, "exit"},
    {&pre_setenv, "setenv"},
    {&my_unsetenv, "unsetenv"},
    {&my_echo, "echo"},
    {&my_which, "which"},
    {&my_builtins, "builtins"},
    {&my_alias, "alias"},
    {NULL, NULL},
  };

int	search_built_in(t_env *env)
{
  int	curs;
  int	error;

  curs = 0;
  while (g_func[curs].name != NULL)
    {
      if (my_strcmp(g_func[curs].name, env->current[0]) == 0)
	{
	  error = g_func[curs].func(env);
	  return (error);
	}
      curs++;
    }
  return (0);
}

int	existence_is_paused(char *str)
{
  int	curs;

  curs = 0;
  while (g_func[curs].name != NULL)
    {
      if (my_strcmp(g_func[curs].name, str) == 0)
	return (0);
      curs++;
    }
  return (1);
}

int	built_in(t_env *env)
{
  if (existence_is_paused(env->current[0]) == 1)
    return (1);
  return (search_built_in(env));
}
