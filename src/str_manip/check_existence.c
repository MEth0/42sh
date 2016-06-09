/*
** get_name.c for get_name in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Thu Jan 21 13:04:47 2016 mathis rousselot
** Last update Wed Apr  6 14:29:44 2016 mathis rousselot
*/

#include <stdlib.h>
#include "my_sh.h"

int     nbr_check(char *str)
{
  int   curs;

  curs = 0;
  if (str == NULL)
    return (1);
  if (str[0] == '-' && str[1] != '\0')
    curs++;
  while (str[curs] != '\0')
    {
      if (str[curs] < '0' || str[curs] > '9')
        return (0);
      curs++;
    }
  return (1);
}

int     get_name(char **env, char *srch)
{
  char  *check;
  int   curs;
  int   curs_2;

  curs = 0;
  if (env == NULL || srch == NULL)
    return (-1);
  check = srch;
  while (env[curs] != NULL)
    {
      curs_2 = 0;
      while (env[curs][curs_2] != '=' && env[curs][curs_2] == check[curs_2]
             && check[curs_2] != '\0')
        curs_2++;
      if (env[curs][curs_2] == '=')
        return (curs);
      curs++;
    }
  return (-1);
}
