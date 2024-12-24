/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:01:31 by yelu              #+#    #+#             */
/*   Updated: 2024/12/24 17:36:33 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char	*s);
int		ft_print_str(const char *str);
int		ft_print_char(int c);
char	*ft_strchr(const char *s, int c);
int		ft_print_number(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char type);
int		ft_print_ptr(unsigned long long ptr);

#endif