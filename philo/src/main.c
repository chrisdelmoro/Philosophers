/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:34:14 by ccamargo          #+#    #+#             */
/*   Updated: 2023/06/15 19:59:56 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	prints(t_philo *philo, int action)
{
	pthread_mutex_lock(philo->common_data->print);
	if (action == 0)
	{
		printf("%lld Philosopher %d has taken a fork.\n", get_current_timestamp(philo), (philo)->id + 1);
	}
	else if (action == 1)
	{
		printf("%lld Philosopher %d is eating.\n", get_current_timestamp(philo), (philo)->id + 1);
	}
	else if (action == 2)
	{
		printf("%lld Philosopher %d is sleeping.\n", get_current_timestamp(philo), (philo)->id + 1);
	}
	else if (action == 3)
	{
		printf("%lld Philosopher %d is thinking.\n", get_current_timestamp(philo), (philo)->id + 1);
	}
	else
	{
		printf("%lld Philosopher %d died.\n", get_current_timestamp(philo), (philo)->id + 1);
	}
	pthread_mutex_unlock(philo->common_data->print);
}

static int	verify_end(t_philo *philo)
{
	pthread_mutex_lock(philo->common_data->dead_or_alive_mutex);
	if (philo->common_data->someone_died == 1 || philo->meals_had == philo->common_data->opt_num_of_meals)
	{
		pthread_mutex_unlock(philo->common_data->dead_or_alive_mutex);
		return (1);
	}
	if (get_current_timestamp(philo) - philo->last_meal >= philo->common_data->time_to_die)
	{
		philo->common_data->someone_died = 1;
		prints(philo, 4);
		pthread_mutex_unlock(philo->common_data->dead_or_alive_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->common_data->dead_or_alive_mutex);
	return (0);
}

void	*philo_life(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *) philo_data;
	set_timestamps(philo);
	while (verify_end(philo) == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		if (verify_end(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			break ;
		}
		prints(philo, 0); //got fork

		pthread_mutex_lock(philo->right_fork);
		if (verify_end(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			break ;
		}
		prints(philo, 0); //got fork
		prints(philo, 1); //Eating
		usleep((philo)->common_data->time_to_eat * 1000);

		pthread_mutex_lock(philo->common_data->dead_or_alive_mutex);
		philo->last_meal = get_current_timestamp(philo);
		philo->meals_had++;
		pthread_mutex_unlock(philo->common_data->dead_or_alive_mutex);

		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);

		if (verify_end(philo))
		{
			break ;
		}
		prints(philo, 2); //Sleeping
		usleep((philo)->common_data->time_to_sleep * 1000);

		if (verify_end(philo))
		{
			break ;
		}
		prints(philo, 3); //Thinking
		usleep(1000);
	}
	return (NULL);
}

void	run_threads(t_common_data *common, pthread_t *philo_threads, \
t_philo **philos)
{
	int	i;

	i = 0;
	while (i < common->num_of_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		initialize_philo(philos[i], common, i);
		if (pthread_create(&philo_threads[i], NULL, &philo_life, \
		(void *) philos[i]))
		{
			printf("Error creating thread!\n");
			free(philo_threads);
			free_philos(philos, common->num_of_philos);
			return ;
		}	
		i++;
	}
}

void	join_threads(t_common_data *common, pthread_t *philo_threads)
{
	int	i;

	i = 0;
	while (i < common->num_of_philos)
	{
		pthread_join(philo_threads[i], NULL);
		i++;
	}
}

void	run_life_cycle(t_common_data *common)
{
	pthread_t	*philo_threads;
	t_philo		**philos;

	philo_threads = (pthread_t *) malloc(sizeof(pthread_t) * common->num_of_philos);
	philos = (t_philo **) malloc(sizeof(t_philo *) * common->num_of_philos);
	run_threads(common, philo_threads, philos);
	join_threads(common, philo_threads);
	free(philo_threads);
	free_philos(philos, common->num_of_philos);
	free_common_data(common);
}

int	main(int argc, char **argv)
{	
	if (is_input_valid(argc, argv))
		run_life_cycle(init_common_data(argv));
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
