/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:01:43 by yelu              #+#    #+#             */
/*   Updated: 2024/12/24 16:56:39 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (len != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	hex_print(unsigned int num, const char type)
{
	char	*hex_lower;
	char	*hex_upper;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	if (num > 16)
	{
		ft_print_hex((num / 16), type);
		ft_print_hex((num % 16), type);
	}
	else
	{
		if (num < 10)
			ft_print_char((num + '0'));
		else
		{
			if (type == 'x')
				ft_print_char(hex_lower[num]);
			else if (type == 'X')
				ft_print_char(hex_upper[num]);
		}
	}
}

int	ft_print_hex(unsigned int num, const char type)
{
	int	len;

	len = 0;
	if (num == 0)
		return (write(1, "0", 1));
	else
		hex_print(num, type);
	return (hex_len(num));
}
