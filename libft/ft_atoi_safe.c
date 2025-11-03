/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:43:56 by abferrer          #+#    #+#             */
/*   Updated: 2025/11/03 16:44:27 by abferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	ft_atoi_safe(const char *str, int *error)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	error = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			*error = 1;
		i++;
	}
	return ((int)(num * sign));
}
