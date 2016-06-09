/*
** env.c for env in /home/rousse_i/rendu/PSU_2015_minishell1_f/src/built_in
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Thu Jan 28 15:36:44 2016 mathis rousselot
** Last update Wed Jun  8 09:24:58 2016 mathis rousselot
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_sh.h"

int	display_env(t_env *env)
{
  int   curs;

  curs = 0;
  if (my_arraylen(env->current) == 1)
    while (env->env[curs] != NULL)
      {
	write(1, env->env[curs], my_strlen(env->env[curs]));
        write(1, "\n", 1);
        curs++;
      }
  else
    {
      fprintf(stderr, "env: %s", env->current[1]);
      fprintf(stderr, ": No such file or directory.\n");
    }
  return (0);
}
