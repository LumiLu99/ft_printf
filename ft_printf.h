/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:01:31 by yelu              #+#    #+#             */
/*   Updated: 2024/12/23 00:01:31 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int		ft_print_hex(unsigned int num, const char type);

#endif