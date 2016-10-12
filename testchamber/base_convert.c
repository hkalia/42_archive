#include <stdio.h>
int		convert(int number,int base)
{
	if(number == 0 || base==10)
		return number;
	return (number % base) + 10*convert(number / base, base);
}

int		main(void) 
{
	printf("%d\n",convert(123, 8));
	return 0;
}
