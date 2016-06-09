/*
** exit.c for exit in /home/rousse_i/rendu/PSU_2015_minishell1_f/src/built_in
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Thu Jan 28 15:32:41 2016 mathis rousselot
** Last update Mon May 30 16:02:25 2016 mathis rousselot
*/

#include "my_sh.h"

int     message_exit(t_env *env)
{
  if (my_arraylen(env->current) > 2 || nbr_check(env->current[1]) == 0)
    {
      my_putstr_err("exit: Expression Syntax.\n");
      return (0);
    }
  return (0);
}
