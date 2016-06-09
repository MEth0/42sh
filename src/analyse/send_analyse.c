/*
** send_analyse.c for send_analyse in /home/rousse-i/rendu/PSU/PSU_2015_42sh/src/analyse
**
** Made by mathis rousselot
** Login   <rousse-i@epitech.net>
**
** Started on  Tue May 24 19:19:39 2016 mathis rousselot
** Last update Fri Jun  3 17:43:02 2016 mathis rousselot
*/

#include <unistd.h>
#include "my_sh.h"

void    dup_fd(t_env *env)
{
  if (env->fd.pipe != -1)
    good_pipe(env, env->fd.pipefd, env->fd.pipe);
  if (env->fd.pipe2 != -1)
    good_pipe(env, env->fd.pipefd2, env->fd.pipe2);
  if (env->fd.fd_out != 1)
    if (dup2(env->fd.fd_out, 1) == -1)
      fatal_error_exit("Dup2 error\n");
  if (env->fd.fd_in != 0)
    if (dup2(env->fd.fd_in, 0) == -1)
      fatal_error_exit("Dup2 error\n");
  (env->fd.fd_out != 1) ? (close(env->fd.fd_out)) : 0;
  (env->fd.fd_in != 0) ? (close(env->fd.fd_in)) : 0;
}

void    keep_going(t_env *env, int curs)
{
  dup_fd(env);
  analyse(env, curs);
}

void    get_in_out(int *in, int *out, t_env *env)
{
  (*in) = -1;
  (*out) = -1;
  (env->fd.pipe == 1) ? (env->fd.fd_in = env->fd.pipefd[0]) : 0;
  (env->fd.pipe == 1) ? (close(env->fd.pipefd[1])) : 0;
  (env->fd.pipe2 == 1) ? (env->fd.fd_in = env->fd.pipefd2[0]) : 0;
  (env->fd.pipe2 == 1) ? (close(env->fd.pipefd2[1])) : 0;
  if (env->fd.fd_out != 1)
    {
      (*out) = dup(1);
      if (dup2(env->fd.fd_out, 1) == -1)
	fatal_error_exit("Dup2 errors\n");
    }
  if (env->fd.fd_in != 0)
    {
      (*in) = dup(0);
      if (dup2(env->fd.fd_in, 0) == -1)
	fatal_error_exit("Dup2 error\n");
    }
  (env->fd.fd_out != 1) ? (close(env->fd.fd_out)) : 0;
  (env->fd.fd_in != 0) ? (close(env->fd.fd_in)) : 0;
}

void    final_command(t_env *env, int curs)
{
  int   in;
  int   out;

  get_in_out(&in, &out, env);
  env->retrn = analyse(env, curs);
  if (out != -1)
    {
      close(1);
      if (dup2(out, 1) == -1)
	fatal_error_exit("Dup2 error\n");
      close(out);
    }
  if (in != -1)
    {
      close(0);
      if (dup2(in, 0) == -1)
	fatal_error_exit("Dup2 error\n");
      close(in);
    }
  close_prog(env);
}
