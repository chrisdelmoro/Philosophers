/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:34:14 by ccamargo          #+#    #+#             */
/*   Updated: 2023/05/25 19:17:31 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char **argv)
{
	if (is_input_valid(argc, argv))
	{
		while (*argv)
		{
			printf("%s\n", *argv);
			argv++;
		}
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
