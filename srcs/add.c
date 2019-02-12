/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:38:25 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 16:59:14 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bignum.h"

/*
** Precondition: n1 >= n2
*/

void	add(t_bignum *n1, t_bignum *n2)
{
	int			carry;
	int			bound;
	t_numpart	*p;
	t_numpart	*q;

	carry = 0;
	bound = ft_pow(10, PART_LEN);
	p = n1->tail;
	q = n2->tail;
	while (p || q || carry != 0)
	{
		p->val += (((q) ? q->val : 0) + carry);
		if (p->val >= bound)
		{
			p->val %= bound;
			carry = 1;
		}
		else
			carry = 0;
		if (q)
			q = q->prev;
		if (p)
			p = p->prev;
		else if (carry != 0)
		{
			n1->head = prepend_part(n1->head, create_part(1));
			carry = 0;
		}
	}
}
