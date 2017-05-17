/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:01:09 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/14 12:47:21 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <inttypes.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <wchar.h>
# include <locale.h>

# define CAST_FLAGS (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 't')
# define ALTER_FLAGS (c == '-' || c == '+' || c == '#' || c == '.' || c == ' ')
# define MUTL_ZEROS ft_mutiply_str("0", diff), instr->str
# define MULT_CHAR(x) ft_mutiply_str(x, (ft_count_alpha(instr->str, *x)))
# define TPCST_INT_CHAR TPCST_CHAR(instr->type) || TPCST_INT(instr->type)
# define FLAGS_COND (!instr->minus_flag) && instr->width > 0 && instr->padding
# define INT_TYPE(type) (type == 'd' || type == 'i')
# define NOT_HEX_TYPE(type) (type != 'X' && type != 'x')
# define CHAR_TYPE(type) (type == 'c' || type == 's' || type == 'S')
# define HEX_TYPE(type) (type == 'x' || type == 'X')
# define OCT_TYPE(type) (type == 'O' || type == 'o')
# define UNSIG_TYPE(type) (type == 'U' || type == 'u')
# define ADD_ZEROS (diff > 0) ? instr->str = ft_strcat(MUTL_ZEROS) : 0;
# define DEL_CHARS(x) ft_del_chars(instr, MULT_CHAR(x));
# define SYM_FLAGS(c) (ALTER_FLAGS ? (1) : (0))
# define CAST_COND(c) (CAST_FLAGS ? (1) : (0))
# define DEC_BASE(x) ((INT_TYPE(x) || UNSIG_TYPE(x) || x == 'D') ? 1 : 0)
# define DIFF_BASE(type) ((OCT_TYPE(type) || HEX_TYPE(type)) ? 1 : 0)
# define REST_CHR(type) ((type == '%' || type == 'p' || type == 'C') ? 1 : 0)
# define CONVER_FLGS(x) ((REST_CHR(x) || CHAR_TYPE(x) || TPCST_INT(x)) ? 1 : 0)
# define TPCST_INT(type) ((DEC_BASE(type) || DIFF_BASE(type)) ? 1 : 0)
# define TPCST_CHAR(type) ((CHAR_TYPE(type) || !(TPCST_INT(type))) ? 1 : 0)

typedef	struct		s_instr
{
	char			type;
	int				padding: 2;
	long int		width;
	int				minus_flag: 2;
	long int		precision;
	int				alter_form: 4;
	int				space: 2;
	int				plus: 2;
	char			*str;
	size_t			instruct_len;
	enum			e_typecast {
		hh = 1,
		h = 2,
		l = 3,
		ll = 4,
		j = 5,
		z = 6,
		t = 7
	}				types;
	enum			e_less_than_zero {
		false = 0,
		true = 1
	}				ltz;
}					t_instr;

typedef void		*(*t_ft_typecast_arg)(void*, t_instr *instr);
typedef void		(*t_ft_chng_instrc)(t_instr *instr);
typedef void		(*t_ft_get_arg)(t_instr *instr, va_list ap);

void				ft_putnstr(char *str, int end, short int flag);
void				ft_putstring(char const *s, short int flag);
int					ft_putchar_mod(char c, short int flag);
void				zero_padding(t_instr *instr);
void				sign_flag(t_instr *instr);
char				*get_width_perfomer(t_instr *instr, int i);
void				get_width_contoller(t_instr *instr);
int					ft_printf(const char *str, ...);
void				get_alterform(t_instr *instr);
void				get_instruct_type(t_instr *instr);
void				get_spaces_instruction(t_instr *instr);
int					ft_char_numlen(char *str);
void				get_precision_sign(t_instr *instr);
void				ft_del_chars(t_instr *instr, char *ltrs_to_omit);
void				get_typecast_ltrs(t_instr *instr);
void				ft_apply_instruct_flags(t_instr *instr);
void				ft_set_instruct_type(t_instr *instr, va_list ap);
char				*ft_char_to_string(int c);
char				*ft_itoa_base_sig(intmax_t n, int base);
char				*ft_itoa_base_usig(uintmax_t n, int base);
char				*ft_str_capitalize(char *str);
char				*ft_mutiply_str(char *str, uintmax_t times);
char				*ft_strncpy_mod(char *dst, const char *src, size_t len);
char				*rev_wstr(char *str);
void				ft_del_num(t_instr *instr, char *num);
int					ft_omit_zeros(char *str, int counter);
char				*ft_wchar(int wchar);
char				*ft_wstr(int *arr, int precision);
int					ft_count_alpha(char *str, char c);
t_instr				*ft_printf_validing(const char *str, t_instr *instr);
int					ft_printf_allowed_compontents(char c);
char				*char_is_zero(t_instr *instr);
void				ft_type_ptr_zero_arg(t_instr *instr, void *arg);
void				ft_bg_c(t_instr *instr, va_list ap);
void				ft_sml_c(t_instr *instr, va_list ap);
void				ft_bg_s(t_instr *instr, va_list ap);
void				ft_sml_s(t_instr *instr, va_list ap);
void				ft_other_chars(t_instr *instr, va_list ap);
void				ft_type_ptr(t_instr *instr, va_list ap);
void				ft_bg_x(t_instr *instr, va_list ap);
void				ft_sml_x(t_instr *instr, va_list ap);
void				ft_sml_o(t_instr *instr, va_list ap);
void				ft_bg_o(t_instr *instr, va_list ap);
void				ft_d_and_i(t_instr *instr, va_list ap);
void				ft_bg_d(t_instr *instr, va_list ap);
void				ft_sml_u(t_instr *instr, va_list ap);
void				ft_bg_u(t_instr *instr, va_list ap);
void				ft_alter_instruct_alternative_form(t_instr *instr);
void				ft_alter_instruct_space(t_instr *instr);
void				ft_alter_instruct_plus(t_instr *instr);
void				ft_alter_instruct_minus(t_instr *instr);
void				ft_alter_instruct_minus_flag(t_instr *instr);
void				ft_alter_instruct_width(t_instr *instr);
void				ft_alter_instruct_zero_padding(t_instr *instr);
void				ft_alter_instruct_precision(t_instr *instr);
t_ft_chng_instrc	*ft_set_function_arr();
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *str);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *str, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
char				*ft_itoa(intmax_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_atoi(const char *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
void				*ft_memset(void *b, int c, size_t len);
int					ft_int_numlen(int n);
int					ft_isalnum(int c);
int					ft_strcmp(const char *str1, const char *str2);
intmax_t			ft_atoi_base(char *str, int base);
#endif
