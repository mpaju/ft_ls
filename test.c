#define ASD 0
#include <stdio.h>
void	idk(void)
{
	ASD = 1;
}

int main(int argc, const char *argv[])
{
	idk();
	printf("%d\n", ASD);
	return 0;
}
