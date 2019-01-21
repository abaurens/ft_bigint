#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "bint/bint.h"

void		pbin(unsigned long v)
{
	if (v > 1)
		pbin(v >> 1);
	printf("%c", (v & 1) + '0');
}

int			main(void)
{
	long	ia;
	long	ib;
	t_bint	a;
	t_bint	b;

	ia = 0xFF;
	ib = 0xFF;
	bi_set(&a, ia);
	bi_set(&b, ib);

	printf("a = "); pbin(ia), printf("\nA = "); bi_print_bin(&a); printf("\n");
	printf("b = "); pbin(ib), printf("\nB = "); bi_print_bin(&b); printf("\n");

	ia *= ib;
	bimulintto(&a, ib);
	printf("\n");

	printf("a = "); pbin(ia), printf("\nA = "); bi_print_bin(&a); printf("\n");
	printf("b = "); pbin(ib), printf("\nB = "); bi_print_bin(&b); printf("\n");

	ia *= ib;
	bimulintto(&a, ib);
	printf("\n");

	printf("a = "); pbin(ia), printf("\nA = "); bi_print_bin(&a); printf("\n");
	printf("b = "); pbin(ib), printf("\nB = "); bi_print_bin(&b); printf("\n");

	ia *= ib;
	bimulintto(&a, ib);
	printf("\n");

	printf("a = "); pbin(ia), printf("\nA = "); bi_print_bin(&a); printf("\n");
	printf("b = "); pbin(ib), printf("\nB = "); bi_print_bin(&b); printf("\n");

	ia *= ib;
	bimulintto(&a, ib);
	printf("\n");

	printf("a = "); pbin(ia), printf("\nA = "); bi_print_bin(&a); printf("\n");
	printf("b = "); pbin(ib), printf("\nB = "); bi_print_bin(&b); printf("\n");

	ia *= ib;
	bimulintto(&a, ib);
	printf("\n");

	printf("a = "); pbin(ia), printf("\nA = "); bi_print_bin(&a); printf("\n");
	printf("b = "); pbin(ib), printf("\nB = "); bi_print_bin(&b); printf("\n");

	ia *= ib;
	bimulintto(&a, ib);
	printf("\n");

	printf("a = "); pbin(ia), printf("\nA = "); bi_print_bin(&a); printf("\n");
	printf("b = "); pbin(ib), printf("\nB = "); bi_print_bin(&b); printf("\n");

	ia *= ib;
	bimulintto(&a, ib);
	printf("\n");

	printf("a = "); pbin(ia), printf("\nA = "); bi_print_bin(&a); printf("\n");
	printf("b = "); pbin(ib), printf("\nB = "); bi_print_bin(&b); printf("\n");

	ia *= ib;
	bimulintto(&a, ib);
	printf("\n");

	printf("a = "); pbin(ia), printf("\nA = "); bi_print_bin(&a); printf("\n");
	printf("b = "); pbin(ib), printf("\nB = "); bi_print_bin(&b); printf("\n");
	return (0);
}
