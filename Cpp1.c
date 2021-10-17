#include<stdio.h>
#include<stdlib.h>


void convolution(int* input1, int* input2, int* output, int mm, int nn)
{
	//存储地址
	int *xx;
	*xx = (int*)malloc(sizeof(int) * (mm + nn - 1));
	//开始卷积
    int i;
	int j;
	for (i = 0; i < mm + nn - 1; i++)
	{
		xx[i] = 0;
		//以位数最少的卷积作为卷积次数
		for (j = 0; j < min(mm,nn) ; j++) {
			//第一个卷积比第二个卷数积少执行
			if (mm <= nn) {
				if (i - j >= 0 && i - j < max(mm, nn)) {
					printf("%d ", input1[j]);
					printf("%d ", input2[i-j]);
					xx[i] += input1[j] * input2[i - j];
				}
			}
			//第一个卷积比第二个卷积数多执行
			else {
				if (i - j >= 0 && i - j < max(mm, nn)) {
					printf("%d ", input1[i-j]);
					printf("%d ", input2[j]);
					xx[i] += input2[j] * input1[i - j];
				}
			}
			printf("\n");
		}
	}
	printf("\n");
	for (i = 0; i < mm+nn-1; i++) {
		output[i] = xx[i];
	}
	delet [] xx;
}

int main() {
	int mm, nn;
	int i,j;
	printf("请输入第一个卷积数目\n");
	scanf_s("%d", &mm);

	//malloc分配空间
	int* input1 = (int*)malloc(sizeof(int) * mm);
	printf("请输入第一个卷积数值\n");
	for (i = 0; i < mm; i++) {
		scanf_s("%d", &input1[i]);
	}
	printf("请输入第二个卷积数目\n");
	scanf_s("%d", &nn);
	int* input2 = (int*)malloc(sizeof(int) * nn);
	printf("请输入第二个卷积数值\n");
	for (j = 0; j < nn; j++) {
		scanf_s("%d", &input2[j]);
	}

	//卷积最大空间
	int* output = (int*)malloc(sizeof(int) * (mm+nn-1));
	convolution(input1, input2, output, mm, nn);

	printf("卷积结果\n");
	for (i = 0; i < mm + nn - 1; i++)
	{
		printf("%d ", output[i]);
	}
	printf("\n");

	return 0;
}	
int min(int x, int y) {
	return x < y ? x : y;
}

int max(int x, int y) {
	return x > y ? x : y;
}