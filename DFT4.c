#include <stdio.h>//��׼�������ͷ��
#include<math.h>//�����˳��õ�һЩ��ѧ����
#define pi 3.1415
#define N 32//32����

typedef struct
{
    double real,imag;
} complex;//���� �ṹ
complex dft_out[100];//���������k
complex dft_one[100];//���������n
double amp[N];//DFT��Ľ��
int main()
{
    int n,k;
    double xn;
    for(k=0; k<N; k++)//kѭ��
    {
        for(n=0; n<N; n++)//nѭ��
        {
            xn=cos(n*pi/6);//ҪDFT���ź�
            dft_one[n].real=xn*cos(2*pi/N*n*k);//ʵ���ź�
            dft_one[n].imag=xn*sin(2*pi/N*n*k);//�鲿�ź�
            dft_out[k].real+=dft_one[n].real;
            dft_out[k].imag+=dft_one[n].imag;//DFT���ʵ�����鲿���
        }
        amp[k]=sqrt(dft_out[k].real*dft_out[k].real+dft_out[k].imag*dft_out[k].imag);//ŷ����ʽ
        printf("%d  %f\n",k,amp[k]);
    }
}
