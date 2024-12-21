#ifndef FT_PRINTF
# define FT_PRINTF

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char	*s);
int		ft_printstr(const char *str);
void	ft_print_char(int c);
char	*ft_strchr(const char *s, int c);
void	ft_print_number(unsigned int n);
void	ft_print_unsigned(unsigned int n);

#endif