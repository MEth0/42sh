/*
** my_pipe.c for my_pipe in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/str_manip/redir
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Mon Apr  4 17:22:00 2016 mathis rousselot
** Last update Wed Jun  8 09:24:04 2016 mathis rousselot
*/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_sh.h"

int	get_fd_eof(t_env *env, int curs)
{
  if ((env->fd.fd_out_const = open(env->arg[ARG].arg[curs + 1],
				   O_CREAT | O_RDWR, 0644)) == -1)
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

int	end_of_file(t_env *env, int curs)
{
  int	check;
  char	c;

  if (check_missing_name(env, curs) == -1)
    return (-1);
  if (check_fd_out(env, curs) == -1)
    return (-1);
  if (get_fd_eof(env, curs) == -1)
    return (-1);
  check = 1;
  while (check == 1)
    check = read(env->fd.fd_out_const, &c, 1);
  env->command[COM].out = WRITE_EOF;
  return (0);
}
