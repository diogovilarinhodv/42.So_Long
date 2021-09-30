/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:34:59 by dpestana          #+#    #+#             */
/*   Updated: 2021/09/29 12:55:20 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/so_long.h"

// [so_long.c] 
int	args_error(void)
{
	write(1, "Error\n", 7);
	write(1, "Quantity of args invalid\n", 26);
	exit(1);
	return (1);
}
