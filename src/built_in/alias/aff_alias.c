/*
** aff_alias.c for aff_alias in /home/rousse_i/PSU_2015_42sh/src/built_in/alias
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sun Jun  5 17:36:28 2016 mathis rousselot
** Last update Sun Jun  5 17:42:05 2016 mathis rousselot
*/

#include <stdio.h>
#include <string.h>
#include "my_sh.h"

int     print_alias(t_alias *alias)
{
  int   i;

  i = 0;
  printf("%s\t", alias->s_command);
  while (alias->command[i])
    {
      if (i == 0)
        printf("(%s", alias->command[i]);
      else
        printf(" %s", alias->command[i]);
      i++;
    }
  printf(")\n");
  return (0);
}

int     aff_alias(t_env *env, char **av)
{
  int   i;

  i = 0;
  while (i != env->nb_alias)
    {
      if (!strcmp((av[1]), env->alias[i].s_command))
        {
          print_alias(&env->alias[i]);
          return (0);
        }
      i++;
    }
  return (0);
}

int     aff_all_alias(t_env *env)
{
  int   i;

  i = 0;
  while (i != env->nb_alias)
    {
      print_alias(&env->alias[i]);
      i++;
    }
  return (0);
}
