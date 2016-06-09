/*
** my_strcat.c for my_strcat in /home/rousse_i/rendu/Piscine_C_J07/ex_02
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Tue Oct  6 13:14:46 2015 mathis rousselot
** Last update Sat Apr  9 16:12:18 2016 mathis rousselot
*/

#include <stdlib.h>
#include "my.h"

char    *my_strcat_real(char *src_1, char *src_2)
{
  char	*dest;
  int   j;
  int   x;

  j = 0;
  x = 0;
  if ((dest = malloc(sizeof(char) * my_strlen(src_1) + my_strlen(src_2) + 2))
      == NULL)
    return (NULL);
  while (src_1[j] != '\0')
    {
      dest[j] = src_1[j];
      j++;
    }
  dest[j] = '\n';
  j++;
  while (src_2[x] != '\0')
    {
      dest[j] = src_2[x];
      x++;
      j++;
    }
  free(src_1);
  dest[j] = '\0';
  return (dest);
}

char	*my_strcat(char *dest, char *src)
{
  int	j;
  int	x;

  j = 0;
  x = 0;
  while (dest[x] != '\0')
    {
      x++;
    }
  while (src[j] != '\0')
    {
      dest[x] = src[j];
      x++;
      j++;
    }
  return (dest);
}
