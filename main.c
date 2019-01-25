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

	i = 4096;
	bi_set(&a, 1234);
	bi_set(&b, 45);
	bi_set(&c, 0);

	printf("A = "); bi_print_dec(&a); printf("\n");
	printf("B = "); bi_print_dec(&b); printf("\n");

	bidiv_knuth(&c, &a, &b);

	printf("C = "); bi_print_dec(&c); printf("\n");
	return (0);
}

/*
1234 / 45
27

1234 % 45
19
*/
