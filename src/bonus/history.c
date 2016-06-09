/*
** history.c for 42 in /home/simon_z/rendu/PSU/PSU_2015_42sh
**
** Made by Morgan SIMON
** Login   <morgan.simon@epitech.eu>
**
** Started on  Sat Jun  4 15:29:42 2016 Morgan SIMON
** Last update Sun Jun  5 21:00:20 2016 mathis rousselot
*/

#include <string.h>
#include <unistd.h>
#include "my_sh.h"

int	my_history(t_env *env, char *str)
{
  if (HIST_FD == -1)
    return (0);
  if (write(HIST_FD, str, strlen(str)) == -1)
    return (-1);
  if (write(HIST_FD, "\n", 1) == -1)
    return (-1);
  return (0);
}
