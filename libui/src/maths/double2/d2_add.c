/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:28:41 by tfernand          #+#    #+#             */
/*   Updated: 2019/08/22 16:28:41 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libui_maths.h>

t_double2	d2_add(t_double2 a, t_double2 b)
{
	return ((t_double2){.x = a.x + b.x, .y = a.y + b.y});
}