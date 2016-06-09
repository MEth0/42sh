/*
** analyse.c for analyse in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Apr  2 17:51:32 2016 mathis rousselot
** Last update Thu Jun  2 17:54:33 2016 mathis rousselot
*/

#include "my_sh.h"

int     analyse(t_env *env, int curs)
{
  if (env->command[curs].type == BUILT_IN)
    env->retrn = built_in(env);
  else if (env->command[curs].type == EXEC)
    command(env->command[curs].dir, env);
  else
    env->retrn = 1;
  return (env->retrn);
}
