#ifndef PHILO_H
# define PHILO_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
    int id;
    int left_fork;
    int right_fork;
}   t_philo;

typedef struct s_info
{
    int philo_num;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_num;
}   t_info;

/*
** =============================================================================
** ft_utils.c
** =============================================================================
*/

int	ft_isdigit(char c);
int	ft_isspace(char c);
int	ft_atoi(const char *str);
int ft_error(char *s);

#endif