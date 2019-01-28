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
	long 	i;
	t_bint	a;
	t_bint	b;
	t_bint	c;

	i = 1;
	bi_set(&a, 1919);
	bi_set(&b, 1000);
	return (0);
}

/*
1234 / 45
27

1234 % 45
19
*/
