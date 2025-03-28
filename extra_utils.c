/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:15:18 by sel-jari          #+#    #+#             */
/*   Updated: 2025/03/28 08:15:19 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	fractal_help(void)
{
	ft_putstr_fd("Error \n use this ./fractol M ", 1);
	ft_putstr_fd("or  ./fractol J <value_1> <value_2> or ./fractol J\n", 1);
	ft_putstr_fd("Which fractal would you like to view?", 1);
	ft_putstr_fd("\nM - Mandelbrot", 1);
	ft_putstr_fd("\nJ - Julia", 1);
	ft_putstr_fd("\nB - Burning Ship", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putstr_fd("-2.0 and 2.0 and must contain a decimal point.\n", 1);
	ft_putstr_fd("usage example:\n", 1);
	ft_putstr_fd("*********************control*****************\n", 1);
	ft_putstr_fd("for shifting colors use z/x\n", 1);
	ft_putstr_fd("for deep image use f/j\n", 1);
	ft_putstr_fd("for zooming use the mouse wheel or i/o\n", 1);
	ft_putstr_fd("for movement use the arrow keyys\n", 1);
}

double	str_to_double(char *str)
{
	double	result;
	double	factor;
	double	sign;

	result = 0.0;
	factor = 1.0;
	sign = 1.0;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			factor *= 0.1;
			result += (*str++ - '0') * factor;
		}
	}
	return (sign * result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
