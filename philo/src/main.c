/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:34:14 by ccamargo          #+#    #+#             */
/*   Updated: 2023/06/06 15:46:32 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	verify_end(t_philo *philo)
{
	pthread_mutex_lock(philo->common_data->last_meal_mutex);
	if (get_current_timestamp(philo) - philo->last_meal >= philo->common_data->time_to_die)
	{
		pthread_mutex_unlock(philo->common_data->last_meal_mutex);
		philo->common_data->someone_died = 1;
	}
	pthread_mutex_unlock(philo->common_data->last_meal_mutex);
	pthread_mutex_lock(philo->common_data->dead_or_alive_mutex);
	if (philo->common_data->someone_died == 1)
	{
		pthread_mutex_unlock(philo->common_data->dead_or_alive_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->common_data->dead_or_alive_mutex);
	/* pthread_mutex_lock(philo->common_data->meals_had_mutex);
	if (philo->common_data->opt_num_of_meals != -1 \
	&& philo->meals_had > philo->common_data->opt_num_of_meals)
	{
		pthread_mutex_unlock(philo->common_data->meals_had_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->common_data->meals_had_mutex); */
	return (0);
}

void	*philo_life(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *) philo_data;
	pthread_mutex_lock(philo->common_data->get_time);
	set_timestamps(philo);
	pthread_mutex_unlock(philo->common_data->get_time);
	while (verify_end(philo) == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->common_data->print);
		printf("%lld Philosopher %d has taken a fork.\n", get_current_timestamp(philo), (philo)->id + 1);
		pthread_mutex_unlock(philo->common_data->print);

		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->common_data->print);
		printf("%lld Philosopher %d has taken a fork.\n", get_current_timestamp(philo), (philo)->id + 1);
		pthread_mutex_unlock(philo->common_data->print);

		pthread_mutex_lock(philo->common_data->print);
		printf("%lld Philosopher %d is eating.\n", get_current_timestamp(philo), (philo)->id + 1);
		pthread_mutex_unlock(philo->common_data->print);

		usleep((philo)->common_data->time_to_eat * 1000);
		pthread_mutex_lock(philo->common_data->last_meal_mutex);
		philo->last_meal = get_current_timestamp(philo);
		pthread_mutex_unlock(philo->common_data->last_meal_mutex);

		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);

		if (verify_end(philo))
		{
			printf("someone died\n");
			break ;
		}
		pthread_mutex_lock(philo->common_data->print);
		printf("%lld Philosopher %d is sleeping.\n", get_current_timestamp(philo), (philo)->id + 1);
		pthread_mutex_unlock(philo->common_data->print);
		usleep((philo)->common_data->time_to_sleep * 1000);

		if (verify_end(philo))
		{
			printf("someone died\n");
			break ;
		}
		pthread_mutex_lock(philo->common_data->print);
		printf("%lld Philosopher %d is thinking.\n", get_current_timestamp(philo), (philo)->id + 1);
		pthread_mutex_unlock(philo->common_data->print);
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
