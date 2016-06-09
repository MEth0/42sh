/*
** compare.c for compare in /home/rousse_i/rendu/pre_minishell2/PSU_2015_minishell1_f/lib/my
** 
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
** 
** Started on  Sat Jan 30 10:59:13 2016 mathis rousselot
** Last update Sat Jan 30 11:01:21 2016 mathis rousselot
*/

#include <stdio.h>
#include "my.h"

int     compare(char *str_1, char *str_2)
{
  int   curs;

  curs = 0;
  if (str_1 == NULL || str_2 == NULL)
    return (0);
  if (my_strlen(str_1) != my_strlen(str_2))
    return (0);
  while (str_1[curs] != '\0' && str_1[curs] == str_2[curs])
    curs++;
  if (str_1[curs] == str_2[curs])
    return (1);
  return (0);
}
