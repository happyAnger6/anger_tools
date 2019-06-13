#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[3][4]={{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12}};

	printf("a[2][3]=[%d]\r\n",*(*(a+1)+3));
	return 0;
}
