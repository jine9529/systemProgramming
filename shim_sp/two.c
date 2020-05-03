#include <stdio.h>

int	sum(int n)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i <= n)
	{
		res += i;
		i++;
	}

	return (res);
}
