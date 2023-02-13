/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 12:06:55 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/13 12:26:26 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool validate_num(char *str)
{
    size_t i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (false);
        i++;
    }
    return (true);
}

bool validate_args(int argc, char **argv)
{
    size_t  i;

    i = 1;
    if (argc != 5 && argc != 6)
    {
        printf("Error: invalid amount of arguments\n"
        "Try: [number_of_philosophers] [time_to_die] [time_to_eat]\
         [time_to_sleep] optionally [number_of_meals]");
        return (false);
    }
    if (ft_atoi(argv[1]) > 200)
    {
        printf("Error: too many philosophers");
        return (false);
    }
    while (argv[i])
    {
        if (ft_atoi(argv[i]) < 1 || !validate_num(argv[i]))
        {
            printf("Error: invalid argument format");
            return (false);
        }
        i++;
    }
    return (true);
}