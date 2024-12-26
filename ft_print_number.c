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

int	ft_print_number(int n)
{
	int	digit;
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
		len += ft_print_number(n);
	}
	else
	{
		if (n > 9)
			len += ft_print_number(n / 10);
		digit = (n % 10) + 48;
		len++;
		write(1, &digit, 1);
	}
	return (len);
}
