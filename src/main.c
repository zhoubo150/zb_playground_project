#include <stdio.h>
#include "calc.h"
int main(void)
{
    double data[100];//储存方差运算原始数据
    long double avg;//储存平均数
    long double ssd;//储存平方和
    enum operation code;//用户功能选择
    long double result;//运算结果
    double x , y;//二元运算输入

    while ((code = menu()) != QUIT)
    {
        switch (code)
        {
        case ADD:
            getadd(&x,&y);
            result = add(x,y);
            break;

        case SUB:
            getsub(&x,&y);
            result = sub(x,y);
            break;

        case MUL:
            getmul(&x,&y);
            result = mul(x,y);
            break;

        case DIV:
            getdiv(&x,&y);
            result = div(x,y);
            break;
        
        case VAR:
            avg = 0;
            ssd = 0;
            int size = getvar(data);
            result = var(data,size,&avg,&ssd);
            put(avg,ssd);
            break;

        default:
            printf("Oops!\n");
            break;
        }
        printf("计算结果为%.10g\n回车以继续使用\n",result);
        getchar();
        getchar();
    }
    printf("感谢您的使用，欢迎下次使用");
    
    return 0;
}