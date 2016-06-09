/*
** alias.c for 42_sh in /home/desria-m/rendu/PSU/PSU_2015_42sh
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu Jun  2 13:58:30 2016 Desriac
** Last update Sun Jun  5 17:38:34 2016 mathis rousselot
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my_sh.h"
#include "struct_sh.h"
#include "my.h"

int	remplace(t_alias *alias, t_command *command)
{
  int	i;
  int	len;
  char	**tmp;

  i = 0;
  len = my_arraylen(command->current);
  if ((tmp = malloc(sizeof(char *) * (len + alias->size))) == NULL)
    fatal_error_exit("Malloc failed\n");
  while (i != alias->size)
    {
      if ((tmp[i] = strdup(alias->command[i])) == NULL)
	fatal_error_exit("Malloc failed\n");
      i++;
    }
  len = 1;
  while (command->current[len])
    {
      if ((tmp[i++] = strdup(command->current[len++])) == NULL)
	fatal_error_exit("Malloc failed\n");
    }
  tmp[i] = NULL;
  free_double(command->current);
  command->current = tmp;
  return (0);
}

int     rp_alias(t_env *env, t_command *command)
{
  int	i;

  i = 0;
  while (i != env->nb_alias)
    {
      if (!strcmp(env->alias[i].s_command, command->current[0]))
      	remplace(&env->alias[i], command);
      i++;
    }
  return (0);
}

int	add_alias(t_env *env, int ac, char **av)
{
  int	i;

  i = 0;
  env->nb_alias += 1;
  if ((env->alias =
       realloc(env->alias, sizeof(t_alias) * env->nb_alias)) == NULL)
    fatal_error_exit("Malloc failed\n");
  if ((env->alias[env->nb_alias - 1].s_command = strdup(av[1])) == NULL)
    fatal_error_exit("Malloc failed\n");
  if ((env->alias[env->nb_alias - 1].command =
       malloc(sizeof(char*) * (ac - 1))) == NULL)
    fatal_error_exit("Malloc failed\n");
  while ((i + 2) != ac)
    {
      if ((env->alias[env->nb_alias - 1].command[i]
	   = strdup(av[i + 2])) == NULL)
	fatal_error_exit("Malloc failed\n");
      i++;
    }
  env->alias[env->nb_alias - 1].command[i] = NULL;
  env->alias[env->nb_alias - 1].size = ac - 2;
  return (0);
}

int	my_alias(t_env *env)
{
  int   ac;

  ac = my_arraylen(env->current);
  if (ac == 1)
    aff_all_alias(env);
  else if (ac == 2)
    aff_alias(env, env->current);
  else
    if (add_alias(env, ac, env->current))
      return (1);
  return (0);
}
