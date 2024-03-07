/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:49:23 by otolmach          #+#    #+#             */
/*   Updated: 2023/10/01 14:49:26 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static	int	ft_plen(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static	void	ft_convertp(uintptr_t num)
{
	if (num >= 16)
	{
		ft_convertp(num / 16);
		ft_convertp(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_p(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
	{
		print_length += write(1, "(nil)", 5);
		return (print_length);
	}
	else
	{
		print_length += write(1, "0x", 2);
		ft_convertp(ptr);
		print_length += ft_plen(ptr);
	}
	return (print_length);
}
