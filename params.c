#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @para: the parameters struct
 * @lv: the argument pointer
 *
 * Return: void
 */
void init_params(paras *para, va_list lv)
{
para->unsign = 0;

para->plus_flag = 0;
para->space_flag = 0;
para->hashtag_flag = 0;
para->zero_flag = 0;
para->minus_flag = 0;

para->width = 0;
para->precision = UINT_MAX;

para->h_modifier = 0;
para->l_modifier = 0;
(void)lv;
}
