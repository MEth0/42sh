/*
** directory.c for directory in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Jan 23 13:36:14 2016 mathis rousselot
** Last update Sun Jun  5 11:39:25 2016 mathis rousselot
*/

#include <stdlib.h>
#include "my_sh.h"

char    *get_directory(char *arg, char *env_line)
{
  char  *str;
  char  *env;

  if ((str = malloc(my_strlen(arg) +  my_strlen(env_line))) == NULL)
    return (NULL);
  env = get_str_name(env_line);
  str[0] = '\0';
  str = str_copy_end(str, env, 1);
  if (arg[0] != '/')
    {
      str[my_strlen(str) + 1] = '\0';
      str[my_strlen(str)] = '/';
    }
  str = str_copy_end(str, arg, 0);
  if (arg[0] == '~')
    str = no_ascii(str, "~", 0, 1);
  if (str[my_strlen(str) - 1] == '/')
    str[my_strlen(str) - 1] = '\0';
  return (str);
}
