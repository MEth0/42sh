/*
** copy.c for copy.c in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
** 
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
** 
** Started on  Thu Jan 21 10:48:08 2016 mathis rousselot
** Last update Thu Jan 28 14:54:48 2016 mathis rousselot
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char    **copy_double_array(char **str)
{
  int	cur;
  int	curs_2;
  char  **str2;

  if ((str2 = malloc(sizeof(char *) * (my_arraylen(str) + 2))) == NULL)
    return (NULL);
  cur = 0;
  while (str[cur] != NULL)
    {
      curs_2 = 0;
      if ((str2[cur] = malloc(sizeof(char) * my_strlen(str[cur]) + 3)) == NULL)
        return (NULL);
      while (str[cur][curs_2] != '\0')
	{
	  str2[cur][curs_2] = str[cur][curs_2];
	  curs_2++;
	}
      str2[cur][curs_2] = '\0';
      cur++;
    }
  str2[cur] = NULL;
  return (str2);
}
