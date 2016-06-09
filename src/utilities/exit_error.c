/*
** exit_error.c for exit in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Mon Apr  4 13:35:04 2016 mathis rousselot
** Last update Thu Jun  2 22:06:21 2016 mathis rousselot
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_sh.h"

void    forked_exit(t_env *env)
{
  close(0);
  close(1);
  close(2);
  exit(env->retrn);
}

void    send_error(int id)
{
  if (id == MISSING)
    fprintf(stderr, "Missing name for redirect.\n");
  if (id == AMBIGOUS_IN)
    fprintf(stderr, "Ambiguous input redirect.\n");
  if (id == AMBIGOUS_OUT)
    fprintf(stderr, "Ambiguous output redirect.\n");
  if (id == NOTHING)
    fprintf(stderr, "Invalid null command.\n");
}

void	fatal_error_exit(char *str)
{
  fprintf(stderr, "%s", str);
  exit(1);
}

char	*no_command(char *str)
{
  my_putstr_err(str);
  my_putstr_err(": Command not found.\n");
  return (NULL);
}
