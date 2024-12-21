#include "ft_printf.h"

void	ft_print_unsigned(unsigned int n)
{
	unsigned int	digit;

		if (n > 9)
			ft_print_unsigned(n / 10);
		digit = (n % 10) + 48;
		write(1, &digit, 1);
}