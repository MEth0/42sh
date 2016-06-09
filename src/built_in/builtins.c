/*
** builtins.c for 42sh in /home/simon_z/rendu/PSU/PSU_2015_42sh
**
** Made by Morgan SIMON
** Login   <morgan.simon@epitech.eu>
**
** Started on  Thu Jun  2 14:22:59 2016 Morgan SIMON
** Last update Thu Jun  2 14:28:09 2016 Morgan SIMON
*/

#include <stdio.h>
#include "my_sh.h"

static int	msg_ret(char *msg)
{
  fprintf(stderr, "%s\n", msg);
  return (1);
}

int	my_builtins(t_env *env)
{
  int	curs;

  if (my_arraylen(env->current) > 1)
    return (msg_ret("builtins: Too many arguments."));
  curs = 0;
  while (g_func[curs].name != NULL)
    printf("%s\n", g_func[curs++].name);
  return (0);
}
