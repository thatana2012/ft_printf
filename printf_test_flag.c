#include <stdio.h>

int	main(void)
{
	int num = 1995;
	printf("[%+10d]\n", num);
    printf("[%-10d]\n", num);
    printf("[%010d]\n", num);
    printf("[% 10d]\n", num);
    printf("[%#x]\n", num);
    printf("[%x]\n", num);
}