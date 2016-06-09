/*
** close_fd.c for close_fd in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/utilities
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Fri Apr  8 13:00:56 2016 mathis rousselot
** Last update Sun Jun  5 18:32:56 2016 mathis rousselot
*/

#include <unistd.h>
#include "my_sh.h"

void    change_fd(t_env *env)
{
  close_pipe(&env->fd.pipe, env->fd.pipefd);
  close_pipe(&env->fd.pipe2, env->fd.pipefd2);
  if (env->fd.fd_in != 0 && env->fd.pipe != 1 && env->fd.pipe2 != 1)
    {
      if (env->fd.fd_in != -1)
	close(env->fd.fd_in);
    }
  if (env->fd.fd_out != 1 && env->fd.pipe != 0 && env->fd.pipe2 != 0)
    {
      if (env->fd.fd_out != -1)
	close(env->fd.fd_out);
    }
}

void    set_right_fd(pid_t pgid)
{
  tcsetpgrp(0, pgid);
  tcsetpgrp(1, pgid);
  tcsetpgrp(2, pgid);
}

void	close_fd(t_env * env)
{
  (env->fd.fd_out != 1) ? (close(env->fd.fd_out)) : 0;
  (env->fd.fd_in != 0) ? (close(env->fd.fd_in)) : 0;
  if (env->fd.fd_in_const != env->fd.fd_in)
    {
      if (env->fd.fd_in_const != -1)
	(env->fd.fd_in_const != 0) ? (close(env->fd.fd_in_const)) : 0;
    }
  if (env->fd.fd_out_const != env->fd.fd_out)
    {
      if (env->fd.fd_in_const != -1)
	(env->fd.fd_out_const != 0) ? (close(env->fd.fd_out_const)) : 0;
    }
}
