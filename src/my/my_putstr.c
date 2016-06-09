/*
** my_putstr.c for my_putstr in /home/rousse_i/rendu/Piscine_C_J04
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Thu Oct  1 17:21:12 2015 mathis rousselot
** Last update Sat Jun  4 14:54:38 2016 Morgan SIMON
*/

#include <unistd.h>
#include <string.h>
#include "my.h"

void	my_putstr(char *str)
{
  write(STDOUT_FILENO, str, strlen(str));
}

void    my_putstr_err(char *str)
{
  write(STDERR_FILENO, str, strlen(str));
}
