#ifndef FT_PRINTF
# define FT_PRINTF

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
size_t	ft_strlen(const char	*s);
int	ft_printstr(const char *str);
int		ft_printchar(int c);
char	*ft_strchr(const char *s, int c);

#endif