/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:27 by bprado         #+#    #+#                */
/*   Updated: 2019/12/13 00:00:34 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF

# define FT_PRINTF

# include <stdio.h> //for testing printf
# include <stdarg.h>
# include <libft.h>

# define HASH 			1 << 0
# define ZERO_F 		1 << 1
# define MINUS_F 		1 << 2
# define SPACE 			1 << 3
# define PLUS 			1 << 4
# define H_F 			1 << 5
# define L_F 			1 << 6
# define HH_F 			1 << 7
# define LL_F 			1 << 8
# define SIGNED_F		1 << 9
# define CAP_L_F		1 << 10
# define PRECISN		1 << 11
# define WIDTH			1 << 12
# define STRNG			1 << 13
# define PRTSIGN		1 << 14
# define SPRINTF		1 << 15
# define NZERO			0x8000
# define INF			0x7FFF
# define NINF			0xFFFF
typedef union	u_union_output
{
	u_int64_t			ll;
	long long			llong;
	long double			lngd;
	u_int16_t			sh[5];
	void*				ptr;
		
}				union_output;

typedef struct	s_pf_sect
{
	const char*			str;
	short				fl;
	char				spc;
	int					i;
	union_output		v;
	int					i_str;
	int					width;
	int					prcs;
	int					length;
	va_list				ap;
	int					ret;
	char				*temp;
	char				*temp2;
	int					fd;
	char				*sprintf;
}				t_pf_sect;

typedef void (*func_pointer)(t_pf_sect *);

int				ft_printf(const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list ap);
int				ft_dprintf(int fd, const char *format, ...);
void			parse_flags(t_pf_sect *s);
void			parse_width_precision(t_pf_sect *s);
void			parse_length(t_pf_sect *s);
void			parse_specifier(func_pointer arrpointer[128]);
void			parse_general(t_pf_sect *s);
char			get_base(char format_specifier);
int				length_of_number(t_pf_sect *s);
void			ft_putnbr_signed(long long n, int base, t_pf_sect *s);
void			print_sign(t_pf_sect *s);
void			print_hash_flag(t_pf_sect *s);
void			print_padding(t_pf_sect *s, int length_of_output, char character, char flip);
void			print_character(char c, t_pf_sect *s);
void			print_string(t_pf_sect *s);
void			print_d(t_pf_sect *s);
void			print_o(t_pf_sect *s);
void			print_str(t_pf_sect *s);
void			print_f(t_pf_sect *s);

int				length_of_float(t_pf_sect *s);
void			putfloat(t_pf_sect *s, int i, int str_i);
int				float_exception(t_pf_sect *s);
void			sign_float(t_pf_sect *s);
int				length_of_unsigned(t_pf_sect *s);
void			ft_putnbr_unsigned(u_int64_t n, int base, t_pf_sect *s);
void			clean_struct(t_pf_sect *s);
long double		ft_pow(float a, float b);
void			no_minus_flag(t_pf_sect *s);
void			print_dioupxxc(t_pf_sect *s);
void			print_n(t_pf_sect *s);

#endif