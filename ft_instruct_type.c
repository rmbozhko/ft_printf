/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:12:13 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/18 15:55:40 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*char_is_zero(t_instr *instr)
{
	instr->null_c = 0;
	if (instr->width > 0 && instr->type == 'c')
	{
		instr->width -= 1;
		instr->null_c = 1;
	}
	else
	{
		instr->precision = (instr->precision >= 0) ? -1 : instr->precision;
		(!TPCST_INT(instr->type)) ? ft_putchar_mod(0, 0) : 0;
	}
	instr->str = ft_strdup("");
	return (instr->str);
}

static void		ft_type_percent(t_instr *instr, va_list ap)
{
	(instr->type == '%') ? instr->str = ft_strdup("%") : 0;
	(void)ap;
}

// void        ft_sml_n(t_instr *instr, va_list ap)
// {
//   int   *arg;

//   if (instr->type == 'n')
//   {
//     arg = va_arg(ap, int*);
//     *arg = ft_putchar_mod(0, 2, instr);
//   }
// }

// void        ft_sml_n(t_instr *instr, va_list ap)
// {
//   static int   *arg = NULL;

//   if (instr->type == 'n')
//   {
//     arg = va_arg(ap, int*);
//     *arg = ft_putchar_mod(0, 2, instr);
//   }
// }

// void        ft_sml_n(t_instr *instr, va_list ap)
// {
//   if (instr->type == 'n')
//   {
//     instr->n_ptr = va_arg(ap, int*);
//     *instr->n_ptr = ft_putchar_mod(0, 2, instr);
//   }
// }

t_ft_get_arg	*ft_set_types_arr(void)
{
	t_ft_get_arg		*type_funcs;

	type_funcs = (t_ft_get_arg*)malloc(sizeof(t_ft_get_arg) * 16 + 1);
	type_funcs[0] = ft_sml_s;
	type_funcs[1] = ft_d_and_i;
	type_funcs[2] = ft_bg_d;
	type_funcs[3] = ft_type_percent;
	type_funcs[4] = ft_sml_o;
	type_funcs[5] = ft_bg_o;
	type_funcs[6] = ft_sml_u;
	type_funcs[7] = ft_bg_u;
	type_funcs[8] = ft_sml_x;
	type_funcs[9] = ft_bg_x;
	type_funcs[10] = ft_sml_c;
	type_funcs[11] = ft_bg_c;
	type_funcs[12] = ft_other_chars;
	type_funcs[13] = ft_type_ptr;
	type_funcs[14] = ft_bg_s;
	type_funcs[15] = ft_sml_n;
	type_funcs[16] = NULL;
	return (type_funcs);
}

void			ft_set_instruct_type(t_instr *instr, va_list ap)
{
	t_ft_get_arg		*type_funcs;
	int					counter;

	free(instr->str);
	type_funcs = ft_set_types_arr();
	counter = -1;
	while (type_funcs[++counter] != NULL)
	{
		type_funcs[counter](instr, ap);
	}
}
