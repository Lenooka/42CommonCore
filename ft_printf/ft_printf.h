/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:50:52 by otolmach          #+#    #+#             */
/*   Updated: 2023/10/01 14:51:12 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_print_c(int c);
int	ft_print_number(int n);
int	ft_print_p(unsigned long long ptr);
int	ft_print_percent(void);
int	ft_print_s(char *str);
int	ft_print_u(unsigned int n);
int	ft_print_x(unsigned int num, const char format);

#endif
