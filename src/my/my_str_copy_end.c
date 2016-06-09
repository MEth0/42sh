/*
** my_str_copy_end.c for my_str_copy_end in /home/rousse_i/rendu/PSU_2015_minishell1_f/lib/my
** 
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
** 
** Started on  Thu Jan 28 13:51:01 2016 mathis rousselot
** Last update Thu Jan 28 13:54:30 2016 mathis rousselot
*/

#include <stdio.h>
#include <stdlib.h>

char    *str_copy_end(char *str, char *str2, int flag)
{
  int   curs;
  int   curs_2;

  if (str2 == NULL)
    return (str);
  curs = 0;
  curs_2 = 0;
  while (str[curs] != '\0')
    curs++;
  while (str2[curs_2] != '\0')
    {
      str[curs] = str2[curs_2];
      curs++;
      curs_2++;
    }
  str[curs] = '\0';
  if (flag == 1)
    free(str2);
  return (str);
}
