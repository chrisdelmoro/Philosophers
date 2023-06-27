/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:17:46 by ccamargo          #+#    #+#             */
/*   Updated: 2023/06/27 19:44:40 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	is_number_of_args_valid(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error! Wrong number of arguments!\n");
		printf("Usage: ./philosophers number_of_philosophers time_to_die \
		time_to_eat time_to_sleep \
		[number_of_times_each_philosopher_must_eat]\n");
		return (0);
	}
	return (1);
}

static int	are_params_numbers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Error! All parameters must be positive numbers!\n");
				return (0);
			}
			if (ft_atoi(argv[i]) == 0)
			{
				printf("Error! All parameters must be number greater than \
zero!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_input_valid(int argc, char **argv)
{
	if (!is_number_of_args_valid(argc))
		return (0);
	if (!are_params_numbers(argv))
		return (0);
	return (1);
}
