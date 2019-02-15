/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:22:20 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 21:34:44 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int         subconvert(char *s, int start, int len)
{
    int n;
    int i;

    i = start;
    n = 0;
    while (len--)
        n = n * 10 + s[i++] - '0';
    return (n);
}

void        convert(char *s, int len, t_bignum *bn)
{
    int         i;
    t_numpart   *part;

    i = len;
    while (i - PART_LEN >= 0)
    {
        part = create_part(subconvert(s, i - PART_LEN, PART_LEN));
        prepend_part(bn, part);
        i -= PART_LEN;
    }
    if (i != 0)
    {
        part = create_part(subconvert(s, 0, i));
        prepend_part(bn, part);
    }
}