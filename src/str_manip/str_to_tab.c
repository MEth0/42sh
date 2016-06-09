/*
** str_to_tab.c for str_to_tab in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Wed Jan 20 12:34:28 2016 mathis rousselot
** Last update Sun Jun  5 11:24:53 2016 mathis rousselot
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_sh.h"

char	*get_str_name(char *env)
{
  char	*str;
  int	curs;
  int	curs_2;

  curs_2 = 0;
  curs = 0;
  if ((str = malloc(sizeof(char) * my_strlen(env))) == NULL)
    fatal_error_exit("Malloc failed\n");
  while (env[curs] != '=')
    curs++;
  curs++;
  while (env[curs] != '\0')
    {
      str[curs_2] = env[curs];
      curs_2++;
      curs++;
    }
  str[curs_2] = '\0';
  return (str);
}

void	redir_array_nbr(char *str, int *curs, int *cont)
{
  if (str[(*curs)] == '|' || str[(*curs)] == '>' || str[(*curs)] == '<')
    (*cont) += 2;
  if ((str[(*curs)] == '>' && str[(*curs) + 1] == '>') ||
      (str[(*curs)] == '<' && str[(*curs) + 1] == '<'))
    (*curs)++;
}

int	get_array_nbr(char *str, int curs_tmp)
{
  int	curs;
  int	cont;

  (1) ? (curs = curs_tmp, cont = 1) : (0);
  while (check_end(str, curs) != 1)
    {
      if (str[curs] == '"')
        {
	  curs++;
          while (str[curs] != '"' && str[curs] != '\0')
	    curs++;
          if (str[curs] == '\0')
	    return (-1);
	  while (str[curs] != ' ' && str[curs] != '\0')
	    curs++;
	  cont++;
        }
      if (str[curs] == ' ')
	cont++;
      redir_array_nbr(str, &curs, &cont);
      if (str[curs] != '\0')
       	curs++;
    }
  return (cont);
}

char    **str_to_word(char *str, int *curs, int cont, int arg)
{
  char  **prog;

  if ((cont = get_array_nbr(str, (*curs))) == -1)
    return (NULL);
  if ((prog = malloc(sizeof(char *) * (cont + 1))) == NULL)
    fatal_error_exit("Malloc failed\n");
  while (arg != cont)
    {
      if (str[(*curs)] == ' ' || str[(*curs)] == ';')
	(*curs)++;
      if ((str[(*curs)] == '|'  && str[(*curs) + 1] != '|')
	  || str[(*curs)] == '>' || str[(*curs)] == '<')
	special_array(&arg, str, prog, curs);
      else
	if (normal_array(&arg, str, prog, curs) == -1)
	  return (NULL);
      arg++;
      (check_end(str, (*curs)) == 1) ? (prog[arg] = NULL, arg = cont) : 0;
    }
  prog[arg] = NULL;
  return (prog);
}

t_argument	*str_to_tab(char *str, t_argument *tab, int curs)
{
  int		curs_2;

  curs_2 = 0;
  while ((str[curs] == ';' || str[curs] == ' ' || str[curs] == '&')
	 && str[curs] != '\0')
    curs++;
  while (str[curs] != '\0')
    {
      tab[curs_2].flag = VIRG;
      if (check_end(str, curs) == 1 &&
	  (curs_2 == 0 || tab[curs_2 - 1].flag != 0))
	{
	  tab[curs_2].flag = -1;
	  fprintf(stderr, "Invalid null command.\n");
	  return (tab);
	}
      if ((tab[curs_2].arg = str_to_word(str, &curs, 0, 0)) == NULL)
	{
	  tab[curs_2].flag = -1;
	  return (tab);
	}
      1 ? (end_arg(str, &curs, &tab[curs_2].flag), curs_2++) : 0;
    }
  tab[curs_2].flag = -1;
  return (tab);
}
