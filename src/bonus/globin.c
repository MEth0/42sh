/*
** globin.c for 42sh in /home/desria-m/rendu/PSU/PSU_2015_42sh
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Fri Jun  3 14:31:26 2016 Desriac
** Last update Sun Jun  5 18:38:09 2016 Desriac
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_sh.h"
#include "struct_sh.h"
#include "my.h"

int	add_to_command(t_command *command, int nb, char **tmp)
{
  int	j;
  int	i;
  int	size;
  char	**new;

  j = i = 0;
  size = my_arraylen(command->current) + my_arraylen(tmp);
  if ((new = malloc(sizeof(char*) * size)) == NULL)
    fatal_error_exit("Malloc failed\n");
  while (i != nb)
    {
      new[i] = command->current[i];
      i++;
    }
  free(command->current[nb++]);
  while (tmp[j])
    new[i++] = tmp[j++];
  while (command->current[nb])
    new[i++] = command->current[nb++];
  new[i] = NULL;
  free(command->current);
  command->current = new;
  return (0);
}

int	r_star(t_command *command, int nb)
{
  int	j;
  int	i;
  char	**tmp;
  char	**dir;

  j = i = 0;
  tmp = NULL;
  dir = get_dir(".");
  while (dir && dir[i])
    {
      if (match(dir[i], command->current[nb]))
	{
	  if ((tmp = realloc(tmp, sizeof(char*) * (j + 2))) == NULL)
	    fatal_error_exit("Malloc failed\n");
	  tmp[j] = strdup(dir[i]);
	  tmp[++j] = NULL;
	}
      i++;
    }
  if (tmp != NULL)
    add_to_command(command, nb, tmp);
  free_double(dir);
  if (tmp == NULL)
    return (1);
  return (0);
}

int	r_env(t_env *env, t_command *command, int nb)
{
  int	i;

  if (!strcmp(command->current[nb], "$?"))
    {
      free(command->current[nb]);
      command->current[nb] = nbr_to_str(env->retrn);
      return (0);
    }
  i = get_name(env->env, (command->current[nb] + 1));
  if (i != -1)
    {
      free(command->current[nb]);
      command->current[nb] = get_str_name(env->env[i]);
    }
  return (0);
}

int	globbin(t_env *env, t_command *command)
{
  int	i;

  i = 0;
  while (command->current[i])
    {
      if (command->current[i][0] == '$')
	r_env(env, command, i);
      else if (char_in_str('*', command->current[i]))
	{
	  if (r_star(command, i))
	    {
	      fprintf(stderr, "%s : No match.\n", command->current[0]);
	      env->retrn = 1;
	      return (1);
	    }
	}
      i++;
    }
  return (0);
}
