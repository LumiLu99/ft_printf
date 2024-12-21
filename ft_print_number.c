/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:38:36 by yelu              #+#    #+#             */
/*   Updated: 2024/12/21 21:38:36 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_number(unsigned int n)
{
	unsigned int	digit;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_print_unsigned(n);
	}
	else
	{
		if (n > 9)
			ft_print_unsigned(n / 10);
		digit = (n % 10) + 48;
		write(1, &digit, 1);
	}
}