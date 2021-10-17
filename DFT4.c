#include <stdio.h>//标准输入输出头文
#include<math.h>//声明了常用的一些数学运算
#define pi 3.1415
#define N 32//32个点

typedef struct
{
    double real,imag;
} complex;//复数 结构
complex dft_out[100];//单个点计算k
complex dft_one[100];//单个点计算n
double amp[N];//DFT后的结果
int main()
{
    int n,k;
    double xn;
    for(k=0; k<N; k++)//k循环
    {
        for(n=0; n<N; n++)//n循环
        {
            xn=cos(n*pi/6);//要DFT的信号
            dft_one[n].real=xn*cos(2*pi/N*n*k);//实部信号
            dft_one[n].imag=xn*sin(2*pi/N*n*k);//虚部信号
            dft_out[k].real+=dft_one[n].real;
            dft_out[k].imag+=dft_one[n].imag;//DFT后的实部，虚部相加
        }
        amp[k]=sqrt(dft_out[k].real*dft_out[k].real+dft_out[k].imag*dft_out[k].imag);//欧拉公式
        printf("%d  %f\n",k,amp[k]);
    }
}
