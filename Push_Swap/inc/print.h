/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:59:36 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/09 18:04:15 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PUSH_SWAP_H

# include <stdarg.h>

int	printchar(int c);
int	printstr(char *str);
int	printint(int c);
int	printfloat(double c);
int	print(const char *content, ...);

#endif