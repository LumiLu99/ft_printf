/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:07:01 by yelu              #+#    #+#             */
/*   Updated: 2024/12/24 21:58:36 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (len != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

static int	ft_print_ptr_recursion(unsigned long long ptr)
{
	int	len;

	len = 0;
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
	return (len);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;
	
	len = 0;
	if (!ptr)
	{
		ft_print_str("(nil)");
		return (len);
	}
	ft_print_str("0x");
	ft_print_ptr_recursion(ptr);
	return (ptr_len);
}