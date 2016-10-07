#include <stdio.h>

int		sum(int n, int n1)
{
	return (n + n1);
}

int		main(void)
{	
	printf("Normal Pointers\n");

	int		a;
	int		*p;	
	int		**pp;
	int		***ppp;
	
	a = 100;
	p = &a;
	pp = &p;
	ppp = &pp;

	printf("a = %d\n", a);
	printf("address of a = %p\n", (void *)&a);
	printf("\n\n");

	printf("*p = %d\n", *p);
	printf("address pointed to by p = %p\n", p);
	printf("address of p = %p\n", (void *)&p);
	printf("\n\n");

	printf("**pp = %d\n", **pp);
	printf("*pp = %p\n", (void *)*pp);
	printf("address pointed to by pp = %p\n", pp);
	printf("address of pp = %p\n", (void *)&pp);
	printf("\n\n");

	printf("***ppp = %d\n", ***ppp);
	printf("**ppp = %p\n", **ppp);
	printf("*ppp = %p\n", (void *)*ppp);
	printf("address pointed to by ppp = %p\n", ppp);
	printf("address of ppp = %p\n", (void *)&ppp);
	printf("\n\n");

	printf("Function Pointers\n");

	int		(*sum_ptr)(int, int);

	sum_ptr = &sum;
	printf("%d\n", (*sum_ptr)(2, 3));
}
