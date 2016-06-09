/*
** my_pipe.c for my_pipe in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/str_manip/redir
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Mon Apr  4 17:22:00 2016 mathis rousselot
** Last update Thu Jun  2 22:06:54 2016 mathis rousselot
*/

#include <unistd.h>
#include "my_sh.h"

void	close_all_pipe(t_env *env)
{
  close_pipe(&env->fd.pipe, env->fd.pipefd);
  close_pipe(&env->fd.pipe2, env->fd.pipefd2);
  close_pipe(&env->fd.pipe, env->fd.pipefd);
  close_pipe(&env->fd.pipe2, env->fd.pipefd2);
}

int	my_pipe(t_env *env, int curs)
{
  (void)curs;
  if (env->command[COM].out != 0)
    {
      env->command[COM].out = AMBIGOUS_OUT;
      return (-1);
    }
  env->command[COM].out = PIPE_OUT;
  return (0);
}
