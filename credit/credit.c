#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long Number=0;
    do
    {
    Number = get_long("Number:");
    }while(Number<0);
    //计算偶数位的2倍和奇数位的总和
    int sum1 = 0;
    int sum2 = 0;
    int a = 0;
    int sum = 0;
    int i;
    int number;
    number = Number;
    for( i = 1;number>0;i++)
    {

        a = number%10;
        number = number/10;
        if(i%2==0)
        {
            int c;
            c = a*2;
            sum1 =sum1 + c ;
        }
        else
            sum2 = sum2 + a;

    }

    int length = 0;
    length = i;
    sum = sum1 + sum2;
    if(sum%10!=0)
    {
        printf("INVALID");
    }
    else
    {

    int b = Number;
    while( b>10&&b<100)
    {
        b = b%10;
    }

    if((b == 34 || b == 37)&& length == 15)
    {
        printf("AMEX\n");
    }
    else if(b >= 51 && b<=55&&length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if(b >= 40 && b <= 49&&(length == 13 ||length == 16))
    {
     printf("VISA\n");
    }


    }
}