/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:22:21 by ccamargo          #+#    #+#             */
/*   Updated: 2023/06/05 01:34:58 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	free_philos(t_philo **philos, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		free(philos[i]);
		i++;
	}
	free(philos);
}

void	free_common_data(t_common_data *common)
{
	free(common);
}
