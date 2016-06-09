/*
** prepare.c for prepare in /home/rousse-i/rendu/PSU/PSU_2015_42sh/src/analyse
**
** Made by mathis rousselot
** Login   <rousse-i@epitech.net>
**
** Started on  Fri May 27 14:57:47 2016 mathis rousselot
** Last update Sun Jun  5 18:54:11 2016 mathis rousselot
*/

#include <stdlib.h>
#include "my_sh.h"

int     check_invalid_null(t_env *env, int curs)
{
  if ((env->command[curs].out == PIPE_OUT ||
       env->command[curs].in == PIPE_IN) &&
      env->command[curs].current[0] == NULL)
    {
      env->command[curs + 1].out = NOTHING;
      return (1);
    }
  if (env->command[curs].out == PIPE_OUT &&
      env->command[curs + 1].in == END)
    {
      env->command[curs + 1].out = NOTHING;
      return (0);
    }
  return (0);
}

void    prepare_action(t_env *env, int curs)
{
  if (env->command[curs].current[0] == NULL)
    return;
  if (existence_is_paused(env->command[curs].current[0]) == 0)
    env->command[curs].type = BUILT_IN;
  else if ((env->command[curs].dir = lobby(env, curs)) != NULL)
    env->command[curs].type = EXEC;
  else
    env->command[curs].type = NOT_FOUND;
}

int	prepare_command(t_env *env, int *curs)
{
  (*curs) = 0;
  while (env->command[(*curs)].in >= 0 && env->command[(*curs)].out >= 0)
    {
      rp_alias(env, &env->command[(*curs)]);
      if (globbin(env, &env->command[(*curs)]))
	return (-1);
      prepare_action(env, (*curs));
      check_invalid_null(env, (*curs));
      (*curs)++;
    }
  env->retrn = 0;
  if (env->command[(*curs)].out < 0)
    {
      send_error(env->command[(*curs)].out);
      env->retrn = 1;
      return (-1);
    }
  (*curs)--;
  return (0);
}
