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
	unsigned long i;
	t_bint	b;
	t_bint	c;

	i = ULONG_MAX - (2 * UINT_MAX);
	bi_set(&b, i);
	bi_set(&c, UINT_MAX);
	printf("b = "); bi_print_bin(&b);
	printf("\n");
	printf("c = "); bi_print_bin(&c);
	printf("\n");

	printf("b = "); bi_print_dec(&b);
	printf("\n");
	printf("c = "); bi_print_dec(&c);
	printf("\n\n");

	i -= UINT_MAX;
	bisub(&b, &b, &c);

	printf("i = "); pbin(i); printf("\n");
	printf("b = "); bi_print_bin(&b);
	printf("\n\n");
	return (0);
}
/*

123
  4



11111111111111111111111111111110 00000000000000000000000000000001
                                 11111111111111111111111111111111

11111111111111111111111111111110
								 00000000000000000000000000000001
                                 11111111111111111111111111111111


100000000000000000000000000000000
 11111111111111111111111111111111


*/
