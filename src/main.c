/*
** main.c for main in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Mon Jan 18 09:40:29 2016 mathis rousselot
** Last update Sun Jun  5 21:00:47 2016 mathis rousselot
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "my_sh.h"

int	my_get_exit(char *str, char **env, t_env my_env)
{
  int	i;

  i = 0;
  while (env[i])
    free(env[i++]);
  free_alias(&my_env);
  free(env);
  free(str);
  printf("exit\n");
  return (my_env.retrn);
}

int	my_get_exit_env(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    free(env[i++]);
  free(env);
  printf("exit\n");
  return (0);
}

int	main(int ac, char **av, char **env)
{
  char	*str;
  t_env	my_env;
  int	check;

  (void)ac;
  (void)av;
  check = my_env.retrn = 0;
  my_env.exit = NO_EXIT;
  if ((my_env.env = get_env_start(env, &my_env)) == NULL)
    return (my_get_exit_env(my_env.env));
  while (check == 0)
    {
      my_putstr("$> ");
      my_signal();
      if ((str = get_next_line(0)) == NULL)
	return (my_get_exit(str, my_env.env, my_env));
      if (str[0] != '\0')
	check = parsing(str, &my_env);
      else
	free(str);
      close_final(&my_env);
    }
  if (my_env.fd.fd_hist != -1)
    close(my_env.fd.fd_hist);
  return (check);
}
