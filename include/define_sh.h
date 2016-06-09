/*
** define_sh.h for define_sh in /home/rousse-i/rendu/PSU/PSU_2015_42sh/include
**
** Made by mathis rousselot
** Login   <rousse-i@epitech.net>
**
** Started on  Thu Jun  2 11:35:21 2016 mathis rousselot
** Last update Sat Jun  4 15:39:14 2016 Morgan SIMON
*/

#ifndef DEFINE_SH_H_
# define DEFINE_SH_H_

# define ARG_POS        env->stop_curr
# define COM            env->current_com
# define CURRENT        env->command[COM].current
# define ARG            env->nb_arg
# define READ_SIZE      1

/*
** Define action
*/

# define BUILT_IN       0
# define EXEC           1
# define NOT_FOUND      2

/*
** Define && and ||
*/

# define VIRG           0
# define AND            1
# define OR             2

/*
** Define FD
*/

# define NONE           0
# define READ_FILE      1
# define READ_STD       2
# define WRITE_FILE     3
# define WRITE_EOF      4
# define PIPE_OUT       5
# define PIPE_IN        6

# define END            -1
# define MISSING        -2
# define AMBIGOUS_IN	-3
# define NO_FILE        -4
# define NOTHING        -5
# define OPEN_FAIL      -6
# define AMBIGOUS_OUT	-7

# define MY_HIST_FD	my_env->fd.fd_hist
# define HIST_FD	env->fd.fd_hist

/*
** Define redir
*/

# define NONE           0
# define PIPE           1
# define R_END          2

# define ERROR          -1

/*
** Exit value
*/

# define NO_EXIT        -1
# define SIMPLE_EXIT    0
# define ARG_EXIT       1

#endif /* !DEFINE_SH_H_ */
