/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:49:23 by ametta            #+#    #+#             */
/*   Updated: 2021/06/09 09:49:23 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_unsign_int(va_list arg, t_specs *specs, int *print)
{
	char			*s;
	unsigned int	nbr;
	int				len;

	nbr = va_arg(arg, int);
	s = ft_itoa_base(nbr, "0123456789");
	if (nbr == 0 && specs->precis == 0)
		len = 0;
	else
		len = ft_strlen(s);
	(*print) += len;
	if (!specs->minus && (specs->zero && specs->precis == -1))
		(*print) += fill('0', specs->width - len);
	if (!specs->minus && !(specs->zero && specs->precis == -1))
		(*print) += fill(' ', specs->width - max(specs->precis, len));
	if (specs->precis != -1)
		(*print) += fill('0', specs->precis - len);
	if (!(nbr == 0 && specs->precis == 0))
		write(1, s, len);
	if (specs->minus && specs->precis != -1)
		(*print) += fill(' ', specs->width - max(specs->precis, len));
	else if (specs->minus)
		(*print) += fill(' ', specs->width - len);
	free(s);
}
