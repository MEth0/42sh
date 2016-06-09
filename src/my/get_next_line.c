/*
** get_next_line.c for get_next_line in /home/heurta_s/rendu/after_pool/B2/prepare/dante
**
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
**
** Started on  Tue May 10 13:56:10 2016 Stanislav HEURTAULT
** Last update Wed Jun  8 10:55:22 2016 mathis rousselot
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "my_sh.h"

int	check_rest(char *rest)
{
  size_t	nb;

  if (rest == NULL)
    return (0);
  nb = 0;
  while (rest[nb] != '\0')
    {
      if (rest[nb] == '\n')
	return (1);
      nb++;
    }
  return (0);
}

char	*add_to_rest(char reader[READ_SIZE + 1], char *rest, int r)
{
  char	*tmp;
  size_t	nb;
  size_t	len;

  (1 ? nb = 0, len = 0 : 0);
  if (rest == NULL)
    {
      if ((tmp = malloc(sizeof(char) * (r + 1))) == NULL)
	fatal_error_exit(MALLOC);
      while (reader[nb] != '\0')
	(1 ? tmp[nb] = reader[nb], nb++ : 0);
      tmp[nb] = '\0';
      return (tmp);
    }
  while (rest[len] != '\0')
    len++;
  if ((tmp = malloc(sizeof(char) * (len + r + 1))) == NULL)
    fatal_error_exit(MALLOC);
  len = 0;
  while (rest[len] != '\0')
    (1 ? tmp[len] = rest[len], len++ : 0);
  while (reader[nb] != '\0')
    (1 ? tmp[len + nb] = reader[nb], nb++ : 0);
  (1 ? tmp[len + nb] = '\0', free(rest) : 0);
  return (tmp);
}

char		*returned(char *rest)
{
  char		*tmp;
  size_t	nb;

  if (rest == NULL)
    return (NULL);
  nb = 0;
  while (rest[nb] != '\n' && rest[nb] != '\0')
    nb++;
  if ((tmp = malloc(sizeof(char) * (nb + 1))) == NULL)
    fatal_error_exit(MALLOC);
  nb = 0;
  while (rest[nb] != '\n' && rest[nb] != '\0')
    {
      tmp[nb] = rest[nb];
      nb++;
    }
  tmp[nb] = '\0';
  return (tmp);
}

char	*truncate_rest(char *rest)
{
  char		*tmp;
  size_t	nb;
  size_t	len;

  (1 ? len = 0, nb = 0 : 0);
  while (rest[nb] != '\n' && rest[nb] != '\0')
    nb++;
  len = nb;
  while (rest[len] != '\0')
    len++;
  if (len == nb)
    {
      free(rest);
      return (NULL);
    }
  if ((tmp = malloc(sizeof(char) * (len - nb))) == NULL)
    fatal_error_exit(MALLOC);
  (1 ? nb++, len = 0 : 0);
  while (rest[len + nb] != '\0')
    (1 ? tmp[len] = rest[len + nb], len++ : 0);
  (1 ? tmp[len] = '\0', free(rest) : 0);
  return (tmp);
}

char		*get_next_line(const int fd)
{
  static char	*rest;
  char		reader[READ_SIZE + 1];
  char		*ret;
  size_t	r;

  r = READ_SIZE;
  while (r == READ_SIZE && check_rest(rest) == 0)
    {
      r = read(fd, reader, READ_SIZE);
      reader[r] = '\0';
      if (r > 0)
	rest = add_to_rest(reader, rest, r);
    }
  if (r == 0)
    return (NULL);
  ret = returned(rest);
  rest = truncate_rest(rest);
  return (ret);
}
