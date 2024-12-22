/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:01:52 by yelu              #+#    #+#             */
/*   Updated: 2024/12/23 00:01:52 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	unsigned int	digit;
	int len;

	len = 0;
	if (n > 9)
	{
		len += ft_print_unsigned(n / 10);
		len += ft_print_unsigned(n % 10);
	}
	else
	{
	digit = n + '0';
	len += write(1, &digit, 1);
	}
	return (len);
}