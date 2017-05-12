#ifndef FT_PRINTF
#define FT_PRINTF

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

#define FLAGS_COND (!instr->minus_flag) && instr->width > 0 && instr->zero_padding
#define INT_CHARS (instr->type == 'd' || instr->type == 'i')
#define HEX_CHARS (instr->type != 'X' && instr->type != 'x')
#define ADD_ZEROS (diff > 0) ? instr->str = ft_strcat(ft_mutiply_str("0", diff), instr->str) : 0;
#define octal_sign (instr->type == 'O' || instr->type == 'o')
#define del_chars(x)	ft_del_chars(instr, ft_mutiply_str(x,(ft_count_alpha(instr->str, *x))));
#define sym_flags(c) ((c == '-' || c == '+' || c == '#' || c == '.' || c == ' ') ? (1) : (0))
#define cast_flags(c) ((c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 't') ? (1) : (0))
#define conversion_flags(x) ((x == '%' || x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D'|| \
							x == 'i' || x == 'o' || x == 'O' || x == 'u' || x == 'U'|| \
							x == 'x' || x == 'X' || x == 'c' || x == 'C') ? 1 : 0)
#define tpcst_int(type) (((type == 'i') || (type == 'd') || (type == 'D') || (type == 'u') || (type == 'o') \
								|| (type == 'O') || (type == 'x') || (type == 'X') || (type == 'U')) ? 1 : 0)
#define tpcst_char(type) (((type == 'c') || (type == 's') || (type == 'S') || !(tpcst_int(type))) ? 1 : 0)

typedef struct 	s_instr
{
    char 			type; //look above(flags array)
	int 			zero_padding: 2; // fullfil with 0's
	long int 			width; //non-zero first digit, which specifies amount of spaces before output, but if '-' flag is presented amount of spaces after output
	int 			minus_flag: 2; // - (minus flag), it overrrides zero_padding property, so no zero will be printed after output
	int 			precision; //. (dot flag), adds zeros at the beginning of the number, which gets printed, or if used with string specifies number of chars, which gets printed
	int 			alter_form: 4; //# (only applicable to o,O and x,X (without bonuses))
	int 			space: 2; //spaces ' ' for sign -> only availiable for i, d, D. If argument < 0, minus sign overrides space for sign, otherwise it remains empty(' ').
	int 			plus: 2; // overrides argument's '+' and space for sign(previous flag) if argument >= 0, otherwise minus gets printed and also overrides space for sign(previous flag).
	char 			*str;
	enum typecast {
		// http://www.cplusplus.com/reference/cstdio/printf/
		hh = 1,
		h = 2, 
		l = 3, 
		ll = 4, 
		j = 5, 
		z = 6, 
		t = 7 
	} types;
	enum less_than_zero {
		false = 0,
		true = 1
	} ltz;
	size_t			instruct_len;
} t_instr;

typedef void *(*ft_typecast_arg)(void*, t_instr *instr);
typedef void (*ft_chng_instrc)(t_instr *instr);
typedef void (*ft_get_arg)(t_instr *instr, va_list ap);
typedef char*(*big_sig_num_funcs)(intmax_t);
typedef char*(*big_usig_num_funcs)(uintmax_t);

void	    ft_putnstr(char *str, int end, short int flag);
void		ft_putstring(char const *s, short int flag);
int 		ft_putchar_mod(char c, short int flag);
void		zero_padding(t_instr *instr);
void		sign_flag(t_instr *instr);
char        *get_width_perfomer(t_instr *instr, int i);
void		get_width_contoller(t_instr *instr);
int			ft_printf(const char *str, ...);
void        get_alterform(t_instr *instr);
void		get_instruct_type(t_instr *instr);
void        get_spaces_instruction(t_instr *instr);
int         ft_char_numlen(char *str);
void        get_precision_sign(t_instr *instr);
void        ft_del_chars(t_instr *instr, char *ltrs_to_omit);
void		get_typecast_ltrs(t_instr *instr);
void		ft_apply_instruct_flags(t_instr *instr);
void		ft_set_instruct_type(t_instr *instr, va_list ap);
char		*ft_char_to_string(int c);
char 		*ft_itoa_base_sig(intmax_t n, int base);
char 		*ft_itoa_base_usig(uintmax_t n, int base); 
char 		*ft_str_capitalize(char *str);
char        *ft_mutiply_str(char *str, unsigned int times);
char		*ft_strncpy_mod(char *dst, const char *src, size_t len);
char		*rev_wstr(char *str);
void		ft_del_num(t_instr *instr, char *num);
int 	 	ft_omit_zeros(char *str, int counter);
char 		*ft_wchar(int wchar);
char 		*ft_wstr(int *arr, int precision);
int         ft_count_alpha(char *str, char c);
t_instr 	*ft_printf_validing(const char *str, t_instr *instr);
int			ft_printf_allowed_compontents(char c);
char 		*char_is_zero(t_instr *instr);


/******** Getting arguments *******/

void				ft_type_ptr_zero_arg(t_instr *instr, void* arg);
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

/******** Alterring function *******/

void						ft_alter_instruct_alternative_form(t_instr *instr);
void						ft_alter_instruct_space(t_instr *instr);
void						ft_alter_instruct_plus(t_instr *instr);
void						ft_alter_instruct_minus(t_instr *instr);
void						ft_alter_instruct_minus_flag(t_instr *instr);
void						ft_alter_instruct_width(t_instr *instr);
void						ft_alter_instruct_zero_padding(t_instr *instr);
void						ft_alter_instruct_precision(t_instr *instr);
ft_chng_instrc 				*ft_set_function_arr();

/******** Library for Libft ******/

char		*ft_strsub(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strchr(const char *str, int c);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *s);
char		*ft_itoa(intmax_t n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
char		*ft_strstr(const char *haystack, const char *needle);
int			ft_atoi(const char *str);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strnew(size_t size);
void		*ft_memset(void *b, int c, size_t len);
int			ft_int_numlen(int n);
int			ft_isalnum(int c);
int			ft_strcmp(const char *str1, const char *str2);

#endif
