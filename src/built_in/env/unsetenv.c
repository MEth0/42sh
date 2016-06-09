/*
** unsetenv.c for unsetenv in /home/rousse_i/rendu/PSU_2015_minishell1_f/src/built_in
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Thu Jan 28 15:30:05 2016 mathis rousselot
** Last update Sun Jun  5 16:08:47 2016 mathis rousselot
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_sh.h"

char	**less_line(char **env, int pos, int mallus, int curs)
{
  char  **env_tmp;
  int   curs_2;

  if  ((env_tmp = malloc(sizeof(char *) * (my_arraylen(env)))) == NULL)
    return (NULL);
  while (env[curs] != NULL)
    {
      curs_2 = 0;
      mallus += (curs == pos ? 1 : 0);
      if (curs != pos)
        if ((env_tmp[curs - mallus] = malloc(my_strlen(env[curs]) + 2)) == NULL)
          return (NULL);
      while (env[curs][curs_2] != '\0' && curs != pos)
        {
          env_tmp[curs - mallus][curs_2] = env[curs][curs_2];
          curs_2++;
          env_tmp[curs - mallus][curs_2] = '\0';
        }
      free(env[curs]);
      curs++;
    }
  free(env);
  env_tmp[curs - mallus] = NULL;
  return (env_tmp);
}

int     my_unsetenv(t_env *env)
{
  int   error;
  int	pos;

  error = 0;
  if (my_arraylen(env->current) == 2)
    {
      pos = get_name(env->env, env->current[1]);
      if (pos != -1)
	env->env = less_line(env->env, pos, 0, 0);
      if (env->env == NULL)
        error = 1;
    }
  else
    fprintf(stderr, "unsetenv: Too few arguments.\n");
  return (error);
}
