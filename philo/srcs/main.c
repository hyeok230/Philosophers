#include "philo.h"

int check_info(t_info *info)
{
    if (info->philo_num < 2 || info->philo_num > 200 || 
        info->time_to_die < 60 || info->time_to_eat < 60 ||
        info->time_to_sleep < 60)
        return (FALSE);
    return (TRUE);
}

int philo_init(t_info *info, int argc, char **argv)
{
    info->philo_num = ft_atoi(argv[1]);
    info->time_to_die = ft_atoi(argv[2]);
    info->time_to_eat = ft_atoi(argv[3]);
    info->time_to_sleep = ft_atoi(argv[4]);
    info->must_eat_num = 0;
    if (check_info(info) == FALSE)
        return (FALSE);
    if (argc == 6)
    {
        info->must_eat_num = ft_atoi(argv[5]);
        if (info->must_eat_num <= 0)
            return (FALSE);
    }
    printf("philo_num = %d\n", info->philo_num);
    printf("time_to_die = %d\n", info->time_to_die);
    printf("time_to_eat = %d\n", info->time_to_eat);
    printf("time_to_sleep = %d\n", info->time_to_sleep);
    printf("must_eat_num = %d\n", info->must_eat_num);
    return (TRUE);
}

int main(int argc, char **argv)
{
    t_info info;

    if (argc != 5 && argc != 6)
    {
        printf("argc ERROR\n");
        return (1);
    }
    if (philo_init(&info, argc, argv) == FALSE)
    {
        printf("argv ERROR\n");
        return (1);
    }
    // if (philo_start())
    // {
    //     printf("start ERROR\n");
    //     return (1);
    // }
    return (0);
}