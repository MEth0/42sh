/*
** builtin.h for 42sh in /home/desria-m/rendu/PSU/PSU_2015_42sh
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sun May  1 19:27:46 2016 Desriac
** Last update Sun Jun  5 18:35:25 2016 Desriac
*/

#ifndef BUILTIN_H_
# define BUILTIN_H_

# define	SIZE_BTAB

typedef         void(*t_funct)(int, char**);

typedef struct  s_bslash
{
  char          bs;
  char          c;
}               t_bslash;

typedef struct	s_echo
{
  char		*type;
  t_funct	func;
}		t_echo;

#endif /* !BUILTIN_H_ */
