#include "philo.h"

int main(int argc, char** argv)
{
    t_info info;

    if (argc != 5 || argc != 6)
    {
        printf("argc ERROR\n");
        return (1);
    }
    if (philo_init(&info, argc, argv))
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