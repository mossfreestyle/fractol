/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:09:32 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/28 10:57:46 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	skip_space_sign(const char **str, int *is_neg)
{
	*is_neg = 1;
	while (ft_isspace((int)**str))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*is_neg = -1;
		(*str)++;
	}
}

static bool	check_digit_part(const char **str, bool *has_digit)
{
	while (ft_isdigit(**str))
	{
		*has_digit = true;
		(*str)++;
	}
	return (true);
}

bool	ft_isdouble(const char *str)
{
	bool	has_dig_before;
	bool	has_dig_after;
	int		sign;

	if (!str || !*str)
		return (false);
	has_dig_before = false;
	has_dig_after = false;
	skip_space_sign(&str, &sign);
	if (!check_digit_part(&str, &has_dig_before))
		return (false);
	if (*str == '.')
	{
		str++;
		if (!check_digit_part(&str, &has_dig_after))
			return (false);
	}
	while (*str && ft_isspace(*str))
		str++;
	return (*str == '\0' && (has_dig_before || has_dig_after));
}

static double	parse_integer(const char **str)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(**str))
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	double	divisor;

	result = 0.0;
	fraction = 0.0;
	divisor = 1.0;
	skip_space_sign(&str, &sign);
	result = parse_integer(&str);
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			fraction = fraction * 10 + (*str - '0');
			divisor *= 10;
			str++;
		}
	}
	result += fraction / divisor;
	return (sign * result);
}
