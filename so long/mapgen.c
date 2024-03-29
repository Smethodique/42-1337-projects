/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAPGEN.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 05:15:39 by stakhtou          #+#    #+#             */
/*   Updated: 2024/03/29 05:18:43 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 36

char	*generate_big_map(void)
{
	char	*map;
	double	r;
	int		player_row;
	int		player_col;

	int i, j;
	map = (char *)malloc((ROWS * (COLS + 1) + 1) * sizeof(char));
	srand(time(NULL));
	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
			{
				map[i * (COLS + 1) + j] = '1';
			}
			else
			{
				r = (double)rand() / RAND_MAX;
				if (r < 0.5)
				{
					map[i * (COLS + 1) + j] = '1';
				}
				else if (r < 0.2)
				{
					map[i * (COLS + 1) + j] = 'C';
				}
				else
				{
					map[i * (COLS + 1) + j] = '0';
				}
			}
			j++;
		}
		map[i * (COLS + 1) + COLS] = '\n';
		i++;
	}
	map[ROWS * (COLS + 1)] = '\0';
	player_row = rand() % (ROWS - 2) + 1;
	player_col = rand() % (COLS - 2) + 1;
	map[player_row * (COLS + 1) + player_col] = 'P';
	int exit_row, exit_col;
	do
	{
		exit_row = rand() % (ROWS - 2) + 1;
		exit_col = rand() % (COLS - 2) + 1;
	} while (exit_row == player_row && exit_col == player_col);
	map[exit_row * (COLS + 1) + exit_col] = 'E';
	return (map);
}

int	main(void)
{
	char *big_map;

	big_map = generate_big_map();
	printf("%s\n", big_map);
	free(big_map);
	return (0);
}