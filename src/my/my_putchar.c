/*
** my_putchar.c for my_putchar in /home/rousse_i/rendu/fonctions
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Tue Oct  6 13:29:22 2015 mathis rousselot
** Last update Thu May 12 15:36:24 2016 Morgan SIMON
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(STDOUT_FILENO, &c, 1);
}

void	my_putchar_err(char c)
{
  write(STDERR_FILENO, &c, 1);
}
