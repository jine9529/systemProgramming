#include <stdio.h>

int	sum(int n);
void	f(void);

int	main(void)
{
	int s = sum(10);
	printf("Sum is %d, and ave is %f ....\n", s, s/10.0);
	f();

	return (0);
}
