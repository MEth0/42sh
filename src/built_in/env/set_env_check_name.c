/*
** set_env_check_name.c for check_nam in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/built_in/env
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Apr  9 16:23:20 2016 mathis rousselot
** Last update Wed Jun  1 11:43:46 2016 mathis rousselot
*/

#include <stdio.h>
#include "my.h"

int	set_env_check_name(char *name)
{
  int	curs;

  curs = 0;
  if (name[0] < 'A' || (name[0] < 'a' && name[0] > 'Z')|| name[0] > 'z')
    {
      fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
      return (1);
    }
  while (name[curs] != '\0')
    {
      if ((name[curs] < 'A' || name[curs] > 'Z') &&
	  (name[curs] < 'a' || name[curs] > 'z') &&
	  (name[curs] < '0' || name[curs] > '9'))
	{
	  fprintf(stderr, "setenv: Variable name must contain ");
	  fprintf(stderr, "alphanumeric characters.\n");
	  return (1);
	}
      curs++;
    }
  return (0);
}
