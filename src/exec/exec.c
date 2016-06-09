/*
** exec.c for exec in /home/rousse_i/rendu/pre_minishell2/PSU_2015_minishell1_f/src/exec
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sun Jan 31 15:49:12 2016 mathis rousselot
** Last update Sun Jun  5 15:50:31 2016 mathis rousselot
*/

#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_sh.h"

void	exec_the_command(char *dir, t_env *env)
{
  if (execve(dir, env->current, env->env) == -1)
    {
      if (errno == ENOEXEC)
	{
	  fprintf(stderr, "%s: ", dir);
	  fprintf(stderr, "Exec format error. Binary file not executable.\n");
	}
      if (errno == EACCES)
	fprintf(stderr, "%s: Permission denied.\n", dir);
    }
  exit(1);
}

void    print_error(t_env *env)
{
  if (WIFSIGNALED(env->retrn) == true)
    {
      if (WTERMSIG(env->retrn) == SIGSEGV)
	fprintf(stderr, "Segmentation fault");
      if (WTERMSIG(env->retrn) == SIGFPE)
	fprintf(stderr, "Floating exception");
      if (WCOREDUMP(env->retrn))
	fprintf(stderr, " (core dumped)");
      fprintf(stderr, "\n");
    }
  else
    env->retrn = WEXITSTATUS(env->retrn);
}

void    command(char *dir, t_env *env)
{
  int   pid;

  if ((pid = fork()) == -1)
    fatal_error_exit("Fork fails\n");
  if (pid == 0)
    {
      my_signal_forked();
      if (env->group == -1)
	setpgid(getpid(), getpid());
      else
	setpgid(getpid(), env->group);
      exec_the_command(dir, env);
    }
  if (env->group == -1)
    set_right_fd(pid);
  waitpid(pid, &env->retrn, 0);
  if (env->group == -1)
    set_right_fd(getpgid(getpid()));
  print_error(env);
}
