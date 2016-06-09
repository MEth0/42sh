/*
** set_env.c for set_env in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Thu Jan 21 12:47:33 2016 mathis rousselot
** Last update Sun Jun  5 16:18:10 2016 Morgan SIMON
*/

#include <stdlib.h>
#include "my_sh.h"

char	**add_line(char **av, char **env)
{
  int   curs;
  int   size;
  int   curs_s1;

  curs_s1 = 0;
  curs = 0;
  while (env[curs] != NULL)
    curs++;
  size = my_strlen(av[1]) + my_strlen(av[2]) + 2;
  if ((env[curs] = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  env[curs][0] = '\0';
  env[curs] = str_copy_end(env[curs], av[1], 0);
  curs_s1 = my_strlen(env[curs]);
  env[curs][curs_s1] = '=';
  env[curs][curs_s1 + 1] = '\0';
  if (av[1] != NULL)
    env[curs] = str_copy_end(env[curs], av[2], 0);
  env[curs + 1] = NULL;
  return (env);
}

char	**create(char **av, char **env)
{
  char  **env_tmp;
  int	curs;
  int	curs_2;

  curs = 0;
  if  ((env_tmp = malloc(sizeof(char *) * (my_arraylen(env) + 2))) == NULL)
    return (NULL);
  while (env[curs] != NULL)
    {
      curs_2 = 0;
      if ((env_tmp[curs] = malloc(my_strlen(env[curs]) + 2)) == NULL)
	return (NULL);
      while (env[curs][curs_2] != '\0')
	{
	  env_tmp[curs][curs_2] = env[curs][curs_2];
	  curs_2++;
	}
      free(env[curs]);
      env_tmp[curs][curs_2] = '\0';
      curs++;
    }
  free(env);
  env_tmp[curs] = NULL;
  env_tmp = add_line(av, env_tmp);
  return (env_tmp);
}

int	overwrite(char **av, t_env *env, int check)
{
  int   size;
  int   curs;

  free(env->env[check]);
  size = my_strlen(av[1]) + my_strlen(av[2]) + 2;
  if ((env->env[check] = malloc(sizeof(char) * size)) == NULL)
    return (1);
  curs = 0;
  env->env[check][0] = '\0';
  env->env[check] = str_copy_end(env->env[check], av[1], 0);
  curs = my_strlen(env->env[check]);
  env->env[check][curs] = '=';
  env->env[check][curs + 1] = '\0';
  if (av[1] != NULL)
    env->env[check] = str_copy_end(env->env[check], av[2], 0);
   return (0);
}

int	my_setenv(char **av, t_env *env)
{
  int   check;
  int	error;

  if (av[1] == NULL)
    {
      display_env(env);
      return (0);
    }
  if (set_env_check_name(av[1]) == 1)
    return (1);
  if (my_arraylen(av) > 3)
    {
      my_putstr_err("setenv: Too many arguments.\n");
      return (0);
    }
  error = 0;
  check = get_name(env->env, av[1]);
  (check == -1) ? (env->env = create(av, env->env)) : 0;
  (check != -1) ? (error = overwrite(av, env, check)) : 0;
  (env->env == NULL) ? (error = 1) : 0;
  return (error);
}

int	pre_setenv(t_env *env)
{
  return (my_setenv(env->current, env));
}
