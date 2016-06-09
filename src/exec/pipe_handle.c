/*
** pipe_handle.c for pipe_handle in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/exec
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Fri Apr  8 13:10:39 2016 mathis rousselot
** Last update Thu Jun  2 22:03:36 2016 mathis rousselot
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_sh.h"

void    check_pipe(t_env *env)
{
  close_pipe(&env->fd.pipe, env->fd.pipefd);
  close_pipe(&env->fd.pipe2, env->fd.pipefd2);
  close_pipe(&env->fd.pipe, env->fd.pipefd);
  close_pipe(&env->fd.pipe2, env->fd.pipefd2);
}

void    good_pipe(t_env *env, int pipefd[2], int pipe_check)
{
  if (pipe_check == 1)
    {
      close(pipefd[1]);
      if (env->fd.fd_in != 0)
        {
          close(pipefd[0]);
          close(env->fd.fd_in);
          (env->fd.fd_out != 0) ? (close(env->fd.fd_out)) : 0;
          my_putstr_err("Ambiguous input redirect.\n");
          exit(0);
        }
      env->fd.fd_in = pipefd[0];
    }
  if (pipe_check == 0)
    {
      if (env->fd.fd_out != 1)
        {
          close(env->fd.fd_out);
          (env->fd.fd_in != 0) ? (close(env->fd.fd_in)) : 0;
          my_putstr_err("Ambiguous output redirect.\n");
          exit(0);
        }
      env->fd.fd_out = pipefd[1];
    }
}

int     close_pipe(int *pipe_check, int pipefd[2])
{
  if ((*pipe_check) == -1)
    return (0);
  if ((*pipe_check) == 0)
    {
      close(pipefd[1]);
      (*pipe_check)--;
    }
  else if ((*pipe_check) == 1)
    {
      close(pipefd[0]);
      (*pipe_check)--;
    }
  return (1);
}
