/*
** parsing.c for parsing in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Tue Mar 29 13:45:06 2016 mathis rousselot
** Last update Sun Jun  5 16:59:44 2016 Morgan SIMON
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_sh.h"

int	nbr_instruc(char *str)
{
  int	instruc;
  int	curs;
  int	check;

  instruc = 3;
  curs = 0;
  check = 0;
  while ((str[curs] == ';' || str[curs] == ' ') && str[curs] != '\0')
    curs++;
  while (str[curs] != '\0')
    {
      if (str[curs] == '|' || str[curs] == '&')
	check++;
      else
	check = 0;
      if (str[curs] == ';' || check == 2)
	instruc++;
      curs++;
    }
  return (instruc);
}

void		re_inistialize(t_env *env)
{
  env->group = -1;
  env->fd.fd_in = 0;
  env->fd.fd_out = 1;
  env->fd.fd_in_const = 0;
  env->fd.fd_out_const = 1;
  env->fd.pipe = -1;
  env->fd.pipe2 = -1;
}

void	end_command(t_env *env)
{
  check_exit(env);
  close_fd(env);
  check_pipe(env);
  free_double(env->arg[ARG].arg);
  if (env->retrn != 0 && env->arg[ARG].flag == AND)
    1 ? (ARG += 2, free_double(env->arg[ARG - 1].arg)) : 0;
  else if (env->arg[ARG].flag == AND)
    ARG++;
  else if (env->retrn != 0 && env->arg[ARG].flag == OR)
    ARG ++;
  else if (env->arg[ARG].flag == OR)
    {
      ARG += 2;
      free_double(env->arg[ARG - 1].arg);
      while (env->arg[env->nb_arg].flag != -1 &&
	     env->arg[env->nb_arg].flag != VIRG)
	{
	  ARG++;
	  if (env->arg[env->nb_arg].flag != -1 &&
	      env->arg[env->nb_arg].flag != VIRG)
	    free_double(env->arg[ARG].arg);
	}
    }
  else
    ARG++;
}

int	check_guillemet(char *str, t_env *env)
{
  int	curs;
  int	check;

  1 ? (curs = 0, check = 0) : 0;
  while (str[curs] != '\0')
    {
      if (str[curs] == '"' && check != 2)
	(check == 0) ? (check = 1) : (check = 0);
      if (str[curs] == '\'' && check != 1)
	(check == 0) ? (check = 2) : (check = 0);
      curs++;
    }
  if (check == 1)
    {
      fprintf(stderr, "Unmatched \".\n");
      free(str);
      env->retrn = 1;
    }
  if (check == 2)
    {
      fprintf(stderr, "Unmatched '.\n");
      free(str);
      env->retrn = 1;
    }
  return (check);
}

int		parsing(char *str, t_env *env)
{
  t_argument	*tab;
  int		instruc;

  no_spaces(str, 0);
  if (my_history(env, str) == -1)
    return (1);
  if ((instruc = check_guillemet(str, env)) == 1 || instruc == 2)
    return (0);
  instruc = nbr_instruc(str);
  if ((tab = malloc(sizeof(t_command) * instruc)) == NULL)
    return (1);
  if ((env->arg = str_to_tab(str, tab, 0)) == NULL)
    return (1);
  free(str);
  if (check_validity_arg(env) == 1)
    return (0);
  env->nb_arg = 0;
  while (env->arg[env->nb_arg].flag != -1)
    {
      re_inistialize(env);
      send_redir(env);
      end_command(env);
    }
  1 ? (env->arg[env->nb_arg].flag = 0, free(env->arg)) : 0;
  return (0);
}
