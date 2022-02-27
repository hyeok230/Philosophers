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

typedef struct s_philo
{
    int id;
    int left_fork;
    int right_fork;
    


}   t_philo

typedef struct s_info
{
    int philo_num;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_num;
}   t_info

#endif