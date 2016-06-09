/*
** echo.c for 42sh in /home/desria-m/rendu/PSU/PSU_2015_42sh
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sun May  1 19:34:05 2016 Desriac
** Last update Sun Jun  5 11:07:33 2016 mathis rousselot
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_sh.h"
#include "builtin.h"

static t_bslash	g_bslash[] =
  {
    {'0', '\0'},
    {'a', '\a'},
    {'b', '\b'},
    {'t', '\t'},
    {'n', '\n'},
    {'v', '\v'},
    {'f', '\f'},
    {'r', '\r'},
    {'\\', '\\'},
    {'\0', '\0'},
  };

int	handle(char *str)
{
  int	i;
  int	j;

  i = 0;
  while (str[i])
    {
      if (str[i] != '\\')
        write(1, &str[i], 1);
      else if (str[i + 1])
	{
	  i++;
	  j = 0;
	  while (g_bslash[j].bs != str[i] && g_bslash[j].bs)
	    j++;
	  if (g_bslash[j].bs)
	    write(1, &g_bslash[j].c, 1);
	}
      i++;
    }
  return (0);
}

int     e_echo(int ac, char **av)
{
  int   i;

  i = 2;
  while (i != ac)
    {
      if (i != 2)
	write(1, " ", 1);
      handle(av[i++]);
    }
  write(1, "\n", 1);
  return (0);
}

int	n_echo(int ac, char **av)
{
  int   i;

  i = 2;
  while (i != ac)
    {
      if (i != 2)
	write(1, " ", 1);
      my_putstr(av[i++]);
    }
  return (0);
}

int	m_echo(int ac, char **av)
{
  int	i;

  i = 1;
  while (i != ac)
    {
      if (i != 1)
        write(1, " ", 1);
      my_putstr(av[i++]);
    }
  write(1, "\n", 1);
  return (0);
}

static t_echo g_echo[]=
  {
    {"-n", (t_funct)&n_echo},
    {"-e", (t_funct)&e_echo},
    {NULL, NULL}
  };

int	my_echo(t_env *env)
{
  int	ac;
  int	i;

  i = 0;
  ac = my_arraylen(env->current);
  if (ac == 1)
    {
      write(1, "\n", 1);
      return (0);
    }
  while (g_echo[i].type)
    {
      if (!strcmp(env->current[1], g_echo[i].type))
  	{
  	  g_echo[i].func(ac, env->current);
  	  return (0);
  	}
      i++;
    }
  m_echo(ac, env->current);
  return (0);
}
