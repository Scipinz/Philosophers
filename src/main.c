/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 12:47:29 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/13 14:10:02 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_data  data;

    if (!validate_args(argc, argv))
        return (EXIT_FAILURE);
    if (!init_data(&data, argv))
        return (EXIT_FAILURE);
    
    return (EXIT_SUCCESS);
}