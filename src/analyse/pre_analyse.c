/*
** pre_analyse.c for pre_analyse in /home/rousse-i/rendu/PSU/PSU_2015_42sh/src
**
** Made by mathis rousselot
** Login   <rousse-i@epitech.net>
**
** Started on  Sat May  7 18:22:26 2016 mathis rousselot
** Last update Sun Jun  5 18:46:50 2016 Morgan SIMON
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my_sh.h"

void	prepare_fd(t_env *env, int curs)
{
  env->fd.fd_out = 1;
  env->fd.fd_in = 0;
  if (env->command[curs].out != 0 && env->command[curs].out != PIPE_OUT)
    env->fd.fd_out = env->fd.fd_out_const;
  if (env->command[curs].in != 0 && env->command[curs].in != PIPE_IN)
    env->fd.fd_in = env->fd.fd_in_const;
  if (env->command[curs].in == PIPE_IN && env->fd.pipe == -1)
    {
      env->fd.pipe = 1;
      if (pipe(env->fd.pipefd) == 1)
	fatal_error_exit("Pipe failed\n");
    }
  else if (env->command[curs].in == PIPE_IN && env->fd.pipe != -1)
    {
      env->fd.pipe2 = 1;
      if (pipe(env->fd.pipefd2) == 1)
	fatal_error_exit("Pipe failed\n");
    }
}

void	get_forked(t_env *env, int curs)
{
  change_fd(env);
  if (env->command[curs + 1].in == END)
    {
      setpgid(getpid(), getpid());
      env->group = getpid();
    }
  curs--;
  send_it(env, curs);
  if (env->command[curs].type == NOT_FOUND)
    no_command(env->command[curs].current[0]);
  forked_exit(env);
}

void	wait_the_pid(t_env *env, int pid, int curs)
{
  int	error;

  waitpid(pid, &error, 0);
  if (WEXITSTATUS(error) > env->retrn)
    env->retrn = WEXITSTATUS(error);
  if (env->command[curs + 1].in == END)
    set_right_fd(getpgid(getpid()));
}

void	send_it(t_env *env, int curs)
{
  int	pid;

  pid = -1;
  prepare_fd(env, curs);
  if (curs != 0)
    if ((pid = fork()) == -1)
      fatal_error_exit("Pipe failed\n");
  if (pid == 0)
    get_forked(env, curs);
  if (env->command[curs + 1].in == END && pid != -1)
    {
      env->group = pid;
      set_right_fd(env->group);
    }
  env->current = env->command[curs].current;
  if (env->command[curs].out != PIPE_OUT && env->command[curs + 1].in == END)
    final_command(env, curs);
  else
    keep_going(env, curs);
  change_fd(env);
  if (pid != -1)
    wait_the_pid(env, pid, curs);
}

void	pre_analyse(t_env *env)
{
  int	curs;

  if (prepare_command(env, &curs) == -1)
    {
      while (env->command[curs].in >= 0)
	{
	  env->command[curs].type = -1;
	  curs++;
	}
      free_command(env->command);
      return;
    }
  send_it(env, curs);
  if (env->command[curs].type == NOT_FOUND)
    no_command(env->command[curs].current[0]);
  free_command(env->command);
}
