/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:47:04 by yelu              #+#    #+#             */
/*   Updated: 2024/12/20 17:06:35 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(va_list args, const char type)
{
	int	len;

	len = 0;	
	if (type == 'c')
		len += ft_printchar(va_arg(args, int));
	if (type == 's')
		len += ft_printstr(va_arg(args, char *));
	if (type == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	if (type == 'd')
		return (1);
	if (type == 'i')
		return (1);
	return (len);
}

int ft_printchar(int c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	len;
	va_list args;

	i = 0;
	len = 0;
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX", str[i]))
				len += check_type(args, str[i]);
		}
		else
		{
			len += ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}

int main()
{
	char s = 'a';
	int	len1 = 0;
	int	len2 = 0;
	
	len1 = ft_printf("%c %s %p %i", 'a', NULL, &s, 12);
	printf("Total characters: %d", len1);
	printf("\n");
	len2 = ft_printf("Hello this is not a Creeper");
	printf("\n");
	printf("Total characters: %d", len2);
	printf("\n");
	printf("%s %d %llu %s %i", "This is normal printf", 23, &s, &s, 12);
}