#include <stdio.h>
#include <string.h>
#include "calc.h"
int menu(void)//菜单
{
    enum operation code;
    int status;
    
    printf("%s%s",SKY,SKY);
    printf("\n选择你要进行的操作\n");
    printf("1) 加法           2) 减法\n");
    printf("3) 乘法           4) 除法\n");
    printf("5) 方差           6)结束程序\n");
    printf("输入你的选择：");
    while ((status = scanf("%d",&code)) != 1 || 
    (code < 1 || code > 6))
    {
        if (status != 1)
        clear();
        printf("请输入1-6:");
    }
    
    return code;
}

void getadd(double *x,double *y)
{
    clear();
    double a;
    double b;
    printf("当前进行加法运算\n");
    printf("请输入第一个加数：");
    a = get();
    printf("请输入第二个加数");
    b = get();
    *x = a;
    *y = b;
}

void getsub(double *x,double *y)
{
    clear();
    double a;
    double b;
    printf("当前进行减法运算\n");
    printf("请输入被减数：");
    a = get();
    printf("请输入减数:");
    b = get();
    *x = a;
    *y = b;
}

void getmul(double *x,double *y)
{
    clear();
    double a;
    double b;
    printf("当前进行乘法运算\n");
    printf("请输入第一个乘数：");
    a = get();
    printf("请输入第二个乘数:");
    b = get();
    *x = a;
    *y = b;
}

void getdiv(double *x,double *y)
{
    clear();
    double a;
    double b;
    printf("当前进行除法运算\n");
    printf("请输入被除数：");
    while(1)
    {
        a = get();
        if(a == 0)
        {
            clear();
            printf("被除数不能为0,请重新输入\n");
        }
        else
        break;   
    }   
    printf("\n请输入除数:");
    b = get();
    *x = a;
    *y = b;
}
int getvar(double vardata[])//针对方差的输入
{
    clear();
    printf("当前进行方差运算,按下q结束输入\n");
    int b = 0;
    for(int i = 1;i < 101;i++)
    {
        printf("请输入第%d个值",i);
        double a;
        if(scanf("%Lf",&a)==1)
        {
            vardata[i-1]=a;
            b++;
        }
        else if((a = getchar()) == 'q')
        {
            clear();
            i--;
            break;
        }
        else 
        {
            printf("请进行有效输入\n");
            clear();
            i--;
        }
    }
    printf("有效输入个数为%d\n",b);
    return b;
}

void clear(void)//处理异常输入
{
    int status, code;
    while ((status = getchar()) != '\n' && status != EOF)
    ;
    
}

double get(void)
{
    double i;
    int a;
    while ((a = scanf("%Lf",&i)) != 1)
    {
        printf("输入必须为数字，请重新输入\n");
        clear();
    }
    return i;
}
double add(double a,double b)//加法运算
{
    double result;

    result = a + b;

    return result;
}

double sub(double a, double b)//减法运算
{
    double result;

    result = a-b;

    return result;
}

double mul(double a,double b)//乘法运算
{
    double result;

    result = a * b;

    return result;
}

long double div(double a,double b)//除法运算
{
    long double result;

    result = a / b;

    return result;
}
long double var(const double vardata[],int size,long double *avg,long double *ssd)//方差及平均数
{
    if (avg == NULL||ssd == NULL)
    {
        printf("不能解引用空数组");
        return -1;
    }
     double result;
    long double a = 0;
    for(int i = 0;i < size;i++)//求和
    {   
        a += vardata[i];

    }
    *avg = a/size;//求平均数
    
    for(int i = 0;i < size;i++)//求离差平方和
    {
        long double sq =vardata[i]-*avg;
        long double a =sq * sq;
        *ssd += a;
    }
    result = *ssd/size;
    return result;
}
void put(long double avg,long double ssd)//方差输出补丁
{
    printf("平均数为%.3f,离差平方和为%.4f\n",avg,ssd);
}