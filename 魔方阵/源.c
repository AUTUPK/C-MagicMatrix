#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int array(int n)
{
    int a, b, k, nu, max;
    int* array;
    max = n * n;
    array = (int*)malloc(2* max);                                          /*Ϊħ��������ڴ�*/
    array[n / 2] = 1;                                                    /* ��1��������*/
    a = 0;  
    b = n / 2;                                                           /*��2��ʼȷ��ÿ�����Ĵ��λ��*/
    for (nu = 2; nu <= max; nu++)
    {
        a = a - 1;
        b = b + 1;
        if ((nu - 1) % n == 0)                                                   /*��ǰ����n�ı���*/
        {
            a = a + 2;
            b = b - 1;
        }
        if (a < 0)                                                          /*��ǰ���ڵ�0��*/
        {
            a = n - 1;
        }
        if (b > n - 1)  /*��ǰ�������һ�У���n-1��*/
        {
            b = 0;
        }
        k = a * n + b;  /*�ҵ���ǰ���Ĵ��λ��*/
        array[k] = nu;
    }
    printf("���ɵ�%d-ħ����Ϊ:", n);   /*��ӡħ����*/
    k = 0;
    for (a = 0; a < n; a++)
    {
        printf("\n");
        for (b = 0; b < n; b++)
        {
            printf("%3d", array[k]);
            k++;
        }
    }
    printf("\n");
    free(array);
    return 0;
}
int main()
{
    int n;
    printf("������nֵ:\n");
    scanf("%d", &n);
    array(n);  
    return 0;
}