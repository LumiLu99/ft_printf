/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:47:04 by yelu              #+#    #+#             */
/*   Updated: 2024/12/24 21:09:08 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(va_list args, const char type)
{
	int	len;

	len = 0;	
	if (type == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (type == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (type == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		len += ft_print_number(va_arg(args, int));
	else if (type == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (type == 'x')
		len += ft_print_hex(va_arg(args, unsigned int), 'x');
	else if (type == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), 'X');
	return (len);
}

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
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
			ft_print_char(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

int main()
{
	int	len1 = 0;
	int	len2 = 0;
	char *str = "aaa";
	
	len1 = ft_printf("%c %s %d %i %u %x %p", 'a', str, 12, 12, 4545, 677656, str);
	printf("\n");
	printf("Total characters: %d", len1);
	printf("\n");
	len2 = ft_printf("Hello this is not a Creeper");
	printf("\n");
	printf("Total characters: %d", len2);
	printf("\n");
	printf("%c %s %d %i %u %x %p", 'a', str, 12, 12, 4545, 677656, str);
}

/**
Why Do We Need va_arg?
Imagine you're making a custom printf function, and someone writes:

ft_printf("Hello %d %s", 42, "world");
You know there are extra arguments after the first one (42 and "world"), but you don’t know:

- How many there are.
- What types they are (e.g., int, char *).

The format string ("Hello %d %s") tells you:

%d means the first extra argument is an int.
%s means the next extra argument is a string (char *).
How do you get those arguments?

You use a special tool called va_list to look at the extra arguments.
va_arg grabs the next argument from that list, and you tell it what type to expect (e.g., int for %d, or char * for %s).

Think of it like flipping through a deck of cards (the arguments):

va_list is like holding the deck in your hand.
va_arg is like pulling the next card from the deck.
You tell va_arg what kind of card you’re expecting (e.g., a number or a string).

**/