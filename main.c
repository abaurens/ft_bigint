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
	t_bint	b;

	i = 4096;
	bi_set(&b, 1);

	while (i-- > 0)
	{
		bimul10(&b, &b);
	}
	/*bi_print_dec(&b); printf("\n");*/
	/*bi_print_bin_space(&b); printf("\n");*/
	printf("{%lu, {", b.len);
	i = 0;
	while (i++ < b.len)
		printf("%s%#x", i > 1 ? ", " : "", b.blks[i - 1]);
	printf("}}\n");

	bipow10(&b, 8191);
	bi_print_dec(&b); printf("\n");
	return (0);
}
