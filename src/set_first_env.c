/*
** set_env.c for set_env in /home/rousse-i/rendu/PSU/PSU_2015_42sh/src
**
** Made by mathis rousselot
** Login   <rousse-i@epitech.net>
**
** Started on  Tue May 10 16:13:37 2016 mathis rousselot
** Last update Sun Jun  5 20:59:36 2016 mathis rousselot
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my_sh.h"

static int	set_alias(t_env	*my_env)
{
  my_env->nb_alias = 0;
  my_env->alias = NULL;
  return (0);
}

void	open_tmp(t_env *my_env)
{
  if ((MY_HIST_FD = open("/tmp/.42sh_history",
			 O_RDWR | O_CREAT, 0600)) == -1)
    MY_HIST_FD = -1;
}

static int	set_history(t_env *my_env)
{
  char		*buff;
  int		curs;
  char		*str;

  if ((curs = get_name(my_env->env, "HOME")) == -1)
    open_tmp(my_env);
  else if (my_env->env[curs][5] != '\0')
    {
      str = get_directory(".42sh_history", my_env->env[curs]);
      if ((MY_HIST_FD = open(str, O_RDWR | O_CREAT, 0600)) == -1)
	open_tmp(my_env);
      free(str);
    }
  else
    open_tmp(my_env);
  if (MY_HIST_FD == -1)
    return (0);
  while ((buff = get_next_line(MY_HIST_FD)) != NULL)
    free(buff);
  return (0);
}

char    **get_env_start(char **env, t_env *my_env)
{
  char  **av;

  if (*env == NULL)
    {
      if ((my_env->env = malloc(sizeof(char *) * 3)) == NULL)
	return (NULL);
      my_env->env[0] = NULL;
    }
  else if ((my_env->env = copy_double_array(env)) == NULL)
    return (NULL);
  if ((get_name(my_env->env, "PATH")) == -1)
    {
      if ((av = malloc(sizeof(char *) * 3)) == NULL)
	return (NULL);
      av[0] = NULL;
      av[1] = "PATH";
      av[2] = "/usr/bin:/bin:/usr/local/bin";
      my_setenv(av, my_env);
    }
  set_alias(my_env);
  if (set_history(my_env) == -1)
    return (NULL);
  shrc(my_env);
  return (my_env->env);
}
