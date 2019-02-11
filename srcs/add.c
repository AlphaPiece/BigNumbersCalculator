/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:33:07 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/11 00:29:50 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_num_calc.h"

char	*add(char *n1, char *n2)
{
	char	*result;
	int		i;
	int		j;
	int		k;
	int		num1;
	int		num2;
	int		carry;
	int		remainder;
	int		sum;

	j = ft_strlen(n1);
	k = ft_strlen(n2);
	i = ft_max(2, j--, k--) + 1;
	if (!(result = (char *)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	result[0] = '0';
	carry = 0;
	while (j >= 0 || k >= 0 || carry > 0)
	{
		num1 = (j >= 0) ? n1[j] - '0' : 0;
		num2 = (k >= 0) ? n2[k] - '0' : 0;
		remainder = (num1 + num2) % 10;
		sum = remainder + carry;
		carry = (num1 + num2) / 10;
		if (sum >= 10)
		{
			carry += sum / 10;
			sum %= 10;
		}
		result[i--] = sum + '0';
		j--;
		k--;
	}
	return (result);
}