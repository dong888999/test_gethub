#include <stdio.h>//标准输入输出的头文件
#include <unistd.h>//sleep
#include <stdlib.h>//system
int main()
{
    system("clear");//system:系统调用函数，专门执行脚本命令
    //时分秒  定义三个整形变量
    int hour,min,sec;
    
    printf("请输入初始化时间：");
    scanf("%d%d%d",&hour,&min,&sec);//标准输入

    while(1)
    {
        //延时 sleep(1);
       
        if(++sec > 60)
        {
            sec = 0;
            if(++min > 60)
            {
                min = 0;
                if(++hour > 24)
                {
                    hour = 0;
                }
            }
        }
       
        printf("当前时间为：%d:%d:%d\n",hour,min,sec);//标准输出
        sleep(1);
        system("clear");
    }
    
    return 0;
}