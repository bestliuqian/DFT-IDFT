#include<stdio.h>
#include<stdlib.h>
conv(int *u, int *v, int m, int n);	//����conv����
main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	int b[] = {2, 4, 7};
	int m = sizeof(a) / sizeof(a[0]);	//��������a�ĳ���
	int n = sizeof(b) / sizeof(b[0]);	//��������b�ĳ���
	conv(a, b, m, n);	//����conv����
}
conv(int u[], int v[], int m, int n)	//����conv����
{
	int k, i;
	int len = m + n -1;	//����������ĳ���
	int result[100] = {0};
	for(k = 0; k < len; k++)
	{
		for(i = max(0, k+1-n); i <= min(k, m-1); i++)
			result[k] += u[i]*v[k-i];
		printf("%d\n",result[k]);
	}
}