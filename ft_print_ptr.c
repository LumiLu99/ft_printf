/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:07:01 by yelu              #+#    #+#             */
/*   Updated: 2024/12/26 16:30:06 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

static void	ft_print_ptr_recursion(unsigned long long ptr)
{
	char	*hex = "0123456789abcdef";

	if (ptr > 16)
		{
			ft_print_ptr_recursion(ptr / 16);
			ft_print_ptr_recursion(ptr % 16);
		}
	else
		if (ptr < 10)
			ft_print_char(ptr + '0');
		else
			ft_print_char(hex[ptr]);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;
	
	len = 0;
	if (!ptr)
	{
		ft_print_str("(nil)");
		return (5);
	}
	ft_print_str("0x");
	len += 2;
	len += ptr_len(ptr);
	ft_print_ptr_recursion(ptr);
	return (len);
}