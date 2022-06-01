#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int array(int n)
{
    int a, b, k, nu, max;
    int* array;
    max = n * n;
    array = (int*)malloc(2* max);                                          /*为魔方阵分配内存*/
    array[n / 2] = 1;                                                    /* 将1存入数组*/
    a = 0;  
    b = n / 2;                                                           /*从2开始确定每个数的存放位置*/
    for (nu = 2; nu <= max; nu++)
    {
        a = a - 1;
        b = b + 1;
        if ((nu - 1) % n == 0)                                                   /*当前数是n的倍数*/
        {
            a = a + 2;
            b = b - 1;
        }
        if (a < 0)                                                          /*当前数在第0行*/
        {
            a = n - 1;
        }
        if (b > n - 1)  /*当前数在最后一列，即n-1列*/
        {
            b = 0;
        }
        k = a * n + b;  /*找到当前数的存放位置*/
        array[k] = nu;
    }
    printf("生成的%d-魔方阵为:", n);   /*打印魔方阵*/
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
    printf("请输入n值:\n");
    scanf("%d", &n);
    array(n);  
    return 0;
}