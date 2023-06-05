/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:24:59 by ccamargo          #+#    #+#             */
/*   Updated: 2023/06/05 03:26:24 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	init_common_data_2(t_common_data *common)
{
	int	i;

	i = 0;
	common->fork = malloc(sizeof(pthread_mutex_t *) * common->num_of_philos);
	while (common->num_of_philos > i)
	{
		common->fork[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(common->fork[i], NULL);
		i++;
	}
	common->get_time = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(common->get_time, NULL);
	common->print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(common->print, NULL);
}

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
	init_common_data_2(common);
	return (common);
}

void	initialize_philo(t_philo *philo, t_common_data *common, int i)
{
	philo->common_data = common;
	philo->id = i;
	philo->left_fork = common->fork[i];
	philo->right_fork = common->fork[(i + 1) % common->num_of_philos];
	if ((i + 1) % common->num_of_philos == 0)
	{
		philo->right_fork = common->fork[i];
		philo->left_fork = common->fork[(i + 1) % common->num_of_philos];
	}
}
