/*
** my_signal.c for signal in /home/simon-z/rendu/PSU/PSU_2015_42sh
**
** Made by Morgan SIMON
** Login   <simon-z@epitech.net>
**
** Started on  Mon Apr 11 14:32:37 2016 Morgan SIMON
** Last update Sun Jun  5 15:35:32 2016 mathis rousselot
*/

#include <unistd.h>
#include <signal.h>

void    my_control_ret()
{
  write(1, "\b\b  \n$> ", 8);
}

void    my_signal_forked()
{
  signal(SIGINT, SIG_DFL);
  signal(SIGQUIT, SIG_DFL);
  signal(SIGTSTP, SIG_DFL);
  signal(SIGTTOU, SIG_DFL);
  signal(SIGTTIN, SIG_DFL);
  signal(SIGTERM, SIG_DFL);
}

void    my_signal()
{
  signal(SIGINT, my_control_ret);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGTTOU, SIG_IGN);
  signal(SIGTTIN, SIG_IGN);
  signal(SIGTERM, SIG_IGN);
}
