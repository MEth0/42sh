/*
** copy_array.c for copy_array in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/str_manip
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Mon Apr  4 13:23:20 2016 mathis rousselot
** Last update Sun Jun  5 17:24:51 2016 mathis rousselot
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_sh.h"

int    special_array(int *arg, char *str, char **prog, int *curs)
{
  if ((prog[(*arg)] = malloc(sizeof(char) * 3)) == NULL)
    fatal_error_exit("Malloc failed\n");
  prog[(*arg)][0] = str[(*curs)];
  if ((str[(*curs)] == '<' && str[(*curs) + 1] == '<') ||
      (str[(*curs)] == '>' && str[(*curs) + 1] == '>'))
    {
      prog[(*arg)][1] = str[(*curs) + 1];
      (*curs)++;
      prog[(*arg)][2] = '\0';
    }
  else
    prog[(*arg)][1] = '\0';
  (*curs)++;
  return (0);
}

int	move_phrase(char *str, int curs, int *size)
{
  if (str[curs + (*size)] == '"')
    {
      (*size)++;
      while (str[curs + (*size)] != '"' && str[curs + (*size)] != '\0')
	(*size)++;
      if (str[curs + (*size)] == '\0')
	{
	  fprintf(stderr, "Unmatched \".\n");
	  return (-1);
	}
    }
  if (str[curs + (*size)] == '\'')
    {
      (*size)++;
      while (str[curs + (*size)] != '\'' && str[curs + (*size)] != '\0')
	(*size)++;
      if (str[curs + (*size)] == '\0')
	{
	  fprintf(stderr, "Unmatched '.\n");
	  return (-1);
	}
    }
  return (0);
}

int	phrase_size(char *str, int curs, char **prog, int *arg)
{
  int	size;

  size = 0;
  while (check_end_copy(str, curs + size) != 1)
    {
      if (move_phrase(str, curs, &size) == -1)
	return (-1);
      size++;
    }
  if (size == 0)
    {
      prog[(*arg)] = NULL;
      return (1);
    }
  if ((prog[(*arg)] = malloc(sizeof(char) * size + 3)) == NULL)
    fatal_error_exit("Malloc failed\n");
  return (0);
}

int     phrase_array(char *str, char *prog, int *curs, int *curs_prog)
{
  (*curs)++;
  if (str[(*curs) - 1] == '"')
    {
      while (str[(*curs)] != '"' && str[(*curs)] != '\0')
	{
	  prog[(*curs_prog)] = str[(*curs)];
	  (*curs)++;
	  (*curs_prog)++;
	}
    }
  else if (str[(*curs) - 1] == '\'')
    {
      while (str[(*curs)] != '\'' && str[(*curs)] != '\0')
	{
	  prog[(*curs_prog)] = str[(*curs)];
	  (*curs)++;
	  (*curs_prog)++;
	}
    }
  (*curs)++;
  return (0);
}

int	normal_array(int *arg, char *str, char **prog, int *curs)
{
  int	curs_prog;

  if ((curs_prog = phrase_size(str, (*curs), prog, arg)) != 0)
    return (curs_prog);
  while (check_end_copy(str, (*curs)) != 1)
    {
      if (str[(*curs)] == '"' || str[(*curs)] == '\'')
	phrase_array(str, prog[(*arg)], curs, &curs_prog);
      else
	{
	  prog[(*arg)][curs_prog] = str[(*curs)];
	  (*curs)++;
	  curs_prog++;
	}
    }
  prog[(*arg)][curs_prog] = '\0';
  return (0);
}
