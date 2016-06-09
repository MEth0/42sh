/*
** functions.c for function in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Wed Jan 20 09:46:47 2016 mathis rousselot
** Last update Thu Jun  2 16:04:58 2016 mathis rousselot
*/

#include <stdlib.h>
#include "my_sh.h"

void    no_quote(char **arg)
{
  int   curs;
  int   curs_2;

  curs = 1;
  while (arg[curs] != NULL)
    {
      curs_2 = 1;
      if (arg[curs][0] == '"')
        {
          while (arg[curs][curs_2] != '"')
            {
              arg[curs][curs_2 - 1] = arg[curs][curs_2];
              curs_2++;
            }
          arg[curs][curs_2 - 1] = '\0';
        }
      curs++;
    }
}

char    *no_ascii(char *str, char *search, int curs, int delete)
{
  int   curs_2;
  int   curs_3;

  curs_2 = 0;
  curs_3 = 0;
  while (str[curs] != '\0')
    {
      str[curs_2] = str[curs];
      if (str[curs] != search[curs_3])
        curs_3 = 0;
      if (str[curs] == search[curs_3])
        curs_3++;
      if (search[curs_3] == '\0')
        {
          if (delete != 0)
            curs_2 -= curs_3;
          curs_3 = 0;
          delete--;
        }
      curs_2++;
      curs++;
    }
  str[curs_2] = '\0';
  return (str);
}

void	phrase_space(char *str, int *curs, int *curs_2)
{
  if (str[(*curs)] == '"' || str[(*curs)] == '\'')
    {
      str[(*curs_2)] = str[(*curs)];
      (*curs_2)++;
      (*curs)++;
      while (str[(*curs)] != '"' && str[(*curs)] != '\0')
	{
	  str[(*curs_2)] = str[(*curs)];
	  (*curs_2)++;
	  (*curs)++;
	}
      while (str[(*curs)] != '\'' && str[(*curs)] != '\0')
	{
	  str[(*curs_2)] = str[(*curs)];
	  (*curs_2)++;
	  (*curs)++;
	}
      if (str[(*curs)] != '\0')
	{
	  str[(*curs_2)] = str[(*curs)];
	  (*curs_2)++;
	  (*curs)++;
	}
    }
}

void	no_spaces(char *str, int curs)
{
  int	curs_2;

  curs_2 = 0;
  while ((str[curs] == '\t' || str[curs] == ' ') && str[curs] != '\0')
    curs++;
  while (str[curs] != '\0')
    {
      phrase_space(str, &curs, &curs_2);
      while ((str[curs] == '\t' || str[curs] == ' ') && str[curs] != '\0')
	curs++;
      if (curs != 0 && str[curs] != '\0')
	if ((str[curs - 1] == ' ' || str[curs - 1] == '\t') && str[curs] != '\0'
	    && curs_2 != 0)
	  1 ? (str[curs_2] = ' ', curs_2++) : 0;
      if (str[curs] != '\0')
	1 ? (str[curs_2] = str[curs], curs_2++, curs++) : 0;
    }
  str[curs_2] = '\0';
}

void	read_double(t_env *env)
{
  int	curs;

  curs = 0;
  while (env->env[curs] != NULL)
    {
      my_putstr(env->env[curs]);
      my_putstr("\n");
      curs++;
    }
}
