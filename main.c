#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "bint/bint.h"

void		pbin(unsigned long v)
{
	if (v > 1)
		pbin(v >> 1);
	printf("%c", (char)((v & 1) + '0'));
}

int			main(void)
{
	t_bint	b;

	bi_set(&b, 0b1101010101010101010101010101010101);
	bi_print_bin_space(&b);
	printf("\n");

	bi_shift_left(&b, 64);

	bi_print_bin_space(&b);
	printf("\n\n");
	return (0);
}
