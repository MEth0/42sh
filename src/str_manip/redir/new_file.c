/*
** my_pipe.c for my_pipe in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/str_manip/redir
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Mon Apr  4 17:22:00 2016 mathis rousselot
** Last update Wed Jun  8 09:23:32 2016 mathis rousselot
*/

#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_sh.h"

int     get_fd_nf(t_env *env, int curs)
{
  if ((env->fd.fd_out_const = open(env->arg[ARG].arg[curs + 1],
				   O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
    {
      if (errno == EACCES)
	fprintf(stderr, "%s: Permission denied.\n",
		env->arg[ARG].arg[curs + 1]);
      if (errno == EISDIR)
	fprintf(stderr, "%s: Is a directory\n",
		env->arg[ARG].arg[curs + 1]);
      if (errno == ENOENT)
	fprintf(stderr, "%s: No such file or directory.\n",
		env->arg[ARG].arg[curs + 1]);
      env->command[COM].out = OPEN_FAIL;
      return (-1);
    }
  return (0);
}

int	new_file(t_env *env, int curs)
{
  if (check_missing_name(env, curs) == -1)
    return (-1);
  if (check_fd_out(env, curs) == -1)
    return (-1);
  if (get_fd_nf(env, curs) == -1)
    return (-1);
  env->command[COM].out = WRITE_FILE;
  return (0);
}
