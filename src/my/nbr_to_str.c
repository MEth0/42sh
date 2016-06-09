/*
** nbr_to_str.c for 42sh in /home/desria-m/rendu/PSU/PSU_2015_42sh
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sat Jun  4 00:25:17 2016 Desriac
** Last update Sat Jun  4 15:22:46 2016 Desriac
*/

#include <stdlib.h>
#include "my_sh.h"

static int	my_pow(int nb, unsigned int i)
{
  int		res;
  unsigned int	j;

  j = 0;
  res = 1;
  while (j != i)
    {
      res *= nb;
      j++;
    }
  return (res);
}

static int	power(int nb)
{
  int	i;

  i = 0;
  while (nb / 10 != 0)
    {
      nb /= 10;
      i++;
    }
  return (i);
}

static char	get_power(int nb, int puiss)
{
  int	res;
  int	i;

  i = my_pow(10, puiss);
  res = nb % (i * 10);
  res = res / i;
  return ((char)res);
}

char	*nbr_to_str(int	nb)
{
  int	j;
  int	i;
  char	*tmp;

  i = power(nb);
  (nb < 0) ? (i++) : (0);
  j = 0;
  if ((tmp = malloc(sizeof(char) * i + 2)) == NULL)
    fatal_error_exit("Malloc failed\n");
  (nb < 0) ? (tmp[j++] = '-') : (0);
  while (j != i + 1)
    {
      tmp[j] = (get_power(nb, (i - j)) + '0');
      j++;
    }
  tmp[j] = '\0';
  return (tmp);
}
