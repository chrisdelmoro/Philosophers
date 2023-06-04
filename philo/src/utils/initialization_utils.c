/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:24:59 by ccamargo          #+#    #+#             */
/*   Updated: 2023/06/05 01:38:09 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_common_data	*init_common_data(char **argv)
{
	t_common_data	*common;

	common = malloc(sizeof(t_common_data));
	common->num_of_philos = ft_atoi(argv[1]);
	common->time_to_die = ft_atoi(argv[2]);
	common->time_to_eat = ft_atoi(argv[3]);
	common->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		common->opt_num_of_meals = ft_atoi(argv[5]);
	else
		common->opt_num_of_meals = -1;
	common->timestamp_init = -1;
	common->timestamp_current = -1;
	return (common);
}

void	initialize_philo(t_philo *philo, t_common_data *common, int i)
{
	philo->common_data = common;
	philo->id = i;
}
