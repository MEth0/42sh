/*
** check_str_to_tab.c for check_str_to_tab in /home/rousse-i/rendu/PSU/PSU_2015_42sh/src/str_manip
**
** Made by mathis rousselot
** Login   <rousse-i@epitech.net>
**
** Started on  Sun May 29 14:43:53 2016 mathis rousselot
** Last update Sun Jun  5 18:47:50 2016 Morgan SIMON
*/

#include "my_sh.h"

void    end_arg(char *str, int *curs, int *flag)
{
  if (str[(*curs)] == ';' || str[(*curs)] == '\0')
    {
      while (str[(*curs)] == ';' || str[(*curs)] == ' ')
	(*curs)++;
      (*flag) = VIRG;
      return;
    }
  if (str[(*curs)] == '&')
    (*flag) = AND;
  if (str[(*curs)] == '|')
    (*flag) = OR;
  (*curs) += 2;
  while (str[(*curs)] == ' ')
    (*curs)++;
}

int     check_end(char *str, int curs)
{
  if (str[curs] == '\0' || str[curs] == ';')
    return (1);
  if (str[curs] == '&' && str[curs + 1] == '&')
    return (1);
  if (str[curs] == '|' && str[curs + 1] == '|')
    return (1);
  return (0);
}

int     check_end_size(char *str, int curs)
{
  if (str[curs] == '\0' || str[curs] == ';' || str[curs] == ' ')
    return (1);
  if (str[curs] == '&' && str[curs + 1] == '&')
    return (1);
  if (str[curs] == '|' && str[curs + 1] == '|')
    return (1);
  return (0);
}

int     check_end_copy(char *str, int curs)
{
  if (str[curs] == '\0' || str[curs] == ';' || str[curs] == ' ' ||
      str[curs] == '|' || str[curs] == '<' || str[curs] == '>')
    return (1);
  if (str[curs] == '&' && str[curs + 1] == '&')
    return (1);
  return (0);
}
