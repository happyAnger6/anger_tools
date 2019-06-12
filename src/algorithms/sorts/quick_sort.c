#include <stdio.h>
#include <stdlib.h>

int partition(int *pAry, int low, int high)
{
	int base = pAry[high];
	int j = low - 1;
	int i = low;
	int tmp;
	for(i = low; i < high; i++)
	{
		if(pAry[i]<base)
		{
			j++;
			tmp = pAry[i];
			pAry[i]=pAry[j];
			pAry[j]=tmp;
		}	
	}
	j++;
	tmp = pAry[i];
	pAry[i]=pAry[j];
	pAry[j]=tmp;
	return j;
}

void quick_sort(int *pAry, int low, int high)
{
	if(low>=high) return;
	int mid = partition(pAry, low, high);
	quick_sort(pAry, low, mid-1);
	quick_sort(pAry, mid+1, high);
}

int main()
{
	int a[] = {1,2,4,5,3,6,8,9,12,4,4,5,3,1,42};
	int len = sizeof(a)/sizeof(int);
	quick_sort(a, 0, len-1);
	for(int i = 0;i < len; i++)
	{
		printf("[%d]=[%d]\r\n",i,a[i]);	
	}
	return 0;
}
