/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:35:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/02/22 09:20:44 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

///////////////////////////////////////////////////////////////////////////////
//----------------------------------INCLUDE----------------------------------//
///////////////////////////////////////////////////////////////////////////////
# include <stdarg.h>
# ifdef _WIN32
#  include <io.h>
#  define ACCESS _access
# else
#  include <unistd.h>
# endif

# include "libft.h"

///////////////////////////////////////////////////////////////////////////////
//------------------------------------VAR------------------------------------//
///////////////////////////////////////////////////////////////////////////////

int		ft_printf(const char *str, ...);
int		ft_printf_parse(char current, va_list ptr, size_t *fsize);
void	ft_putnbr_base_ul(unsigned long nbr, char *base, int fd, size_t *fsize);
void	ft_putnbr_int(int n, int fd, size_t *fsize);

#endif