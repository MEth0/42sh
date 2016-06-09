/*
** my_arraylen.c for my_arraylen in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/lib/my
** 
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
** 
** Started on  Fri Jan 22 10:23:51 2016 mathis rousselot
** Last update Fri Jan 22 10:25:48 2016 mathis rousselot
*/

#include <stdio.h>

int	my_arraylen(char **str)
{
  int	curs;

  curs = 0;
  while (str[curs] != NULL)
    curs++;
  return (curs);
}
