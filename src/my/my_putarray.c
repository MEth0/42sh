/*
** my_putarray.c for putarray in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/my
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Apr  2 20:13:02 2016 mathis rousselot
** Last update Mon Apr  4 13:44:00 2016 mathis rousselot
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	my_putarray(char **str)
{
  int	curs;

  curs = 0;
  while (str[curs] != NULL)
    {
      write(1, "<", 1);
      my_putstr(str[curs]);
      write(1, "> ", 2);
      curs++;
    }
  write(1, "\n", 1);
}
