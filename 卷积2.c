#include<stdio.h>
#include<stdlib.h>
conv(int *u, int *v, int m, int n);	//声明conv函数
main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	int b[] = {2, 4, 7};
	int m = sizeof(a) / sizeof(a[0]);	//计算数组a的长度
	int n = sizeof(b) / sizeof(b[0]);	//计算数组b的长度
	conv(a, b, m, n);	//调用conv函数
}
conv(int u[], int v[], int m, int n)	//定义conv函数
{
	int k, i;
	int len = m + n -1;	//计算卷积结果的长度
	int result[100] = {0};
	for(k = 0; k < len; k++)
	{
		for(i = max(0, k+1-n); i <= min(k, m-1); i++)
			result[k] += u[i]*v[k-i];
		printf("%d\n",result[k]);
	}
}