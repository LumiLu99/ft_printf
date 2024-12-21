#include "ft_printf.h"

int	ft_print_hex(unsigned int num, const char type)
{
	if (num == 0)
		return (write(1, "0", 1));
	char	hex_lower[] = "0123456789abcdef";
	char	hex_upper[] = "0123456789ABCDEF";
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