/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:24 by bprado         #+#    #+#                */
/*   Updated: 2019/12/13 00:29:36 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_pf_sect		s;
	func_pointer	arrpointer[128];

	ft_bzero(&s, sizeof(s));
	s.fd = fd;
	s.str = format;
	va_copy(s.ap, ap);
	parse_specifier(arrpointer);
	while (s.str[s.i_str] != 0)
	{
		if (s.str[s.i_str] == '%' && s.str[s.i_str + 1] == 0)
			break ;
		if (s.str[s.i_str] == '%')
		{
			++s.i_str;
			parse_general(&s);
			arrpointer[(int)s.spc](&s);
			clean_struct(&s);
		}
		if (s.str[s.i_str] != 0 && s.str[s.i_str] != '%')
			print_character(s.str[s.i_str], &s);
		s.i_str += s.str[s.i_str] && s.str[s.i_str] != '%' ? 1 : 0;
	}
	va_end(s.ap);
	return (s.ret);
}

int		ft_printf(const char *format, ...)
{
	int				i;
	va_list			ap;

	va_start(ap, format);
	i = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (i);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	int				i;
	va_list			ap;

	va_start(ap, format);
	i = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (i);
}

int		ft_sprintf(char *restrict s_string, const char *restrict format, ...)
{
	t_pf_sect		s;
	func_pointer	arrpointer[128];

	ft_bzero(&s, sizeof(s));
	s.sprintf = s_string;
	s.str = format;
	s.fl |= SPRINTF;
	va_start(s.ap, format);
	parse_specifier(arrpointer);
	while (s.str[s.i_str] != 0)
	{
		if (s.str[s.i_str] == '%' && s.str[s.i_str + 1] == 0)
			break ;
		if (s.str[s.i_str] == '%')
		{
			++s.i_str;
			parse_general(&s);
			arrpointer[(int)s.spc](&s);
			clean_struct(&s);
		}
		if (s.str[s.i_str] != 0 && s.str[s.i_str] != '%')
			print_character(s.str[s.i_str], &s);
		s.i_str += s.str[s.i_str] && s.str[s.i_str] != '%' ? 1 : 0;
	}
	va_end(s.ap);
	*(s.sprintf) = 0;
	return (s.ret);
}

void	clean_struct(t_pf_sect *s)
{
	s->fl = 0;
	s->spc = 0;
	s->i = 0;
	s->v.ll = 0;
	s->width = 0;
	s->prcs = 0;
	++s->i_str;
}

void	print_character(char c, t_pf_sect *s)
{
	if (s->fl ^ SPRINTF)
		ft_putchar_fd(c, s->fd);
	else
	{
		*(s->sprintf) = c;
		++s->sprintf;
	}
	s->ret++;
}

void	print_n(t_pf_sect *s)
{
	int				*n;

	n = va_arg(s->ap, void*);
	*n = s->ret;
}
