/*
** free.c for free in /home/rousse_i/rendu/pre_minishell2/PSU_2015_minishell1_f/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sun Jan 31 16:30:22 2016 mathis rousselot
** Last update Sun Jun  5 18:48:18 2016 Morgan SIMON
*/

#include <stdlib.h>
#include "my_sh.h"

void	free_arg(t_argument *arg)
{
  int	curs;

  curs = 0;
  while (arg[curs].flag != -1)
    {
      if (arg[curs].arg != NULL)
	free_double(arg[curs].arg);
      curs++;
    }
  free(arg);
}

void    free_command(t_command *com)
{
  int	curs;

  curs = 0;
  while (com[curs].in >= 0)
    {
      free_double(com[curs].current);
      if (com[curs].type == EXEC)
	free(com[curs].dir);
      curs++;
    }
  free(com);
}

void    free_double(char **array)
{
  int   curs;

  curs = 0;
  if (array == NULL)
    return;
  while (array[curs] != NULL)
    {
      free(array[curs]);
      curs++;
    }
  free(array);
}

void    go_free(char ***arg)
{
  int	curs;

  curs = 0;
  while (arg[curs] != NULL)
    {
      free_double(arg[curs]);
      curs++;
    }
  free(arg);
}
