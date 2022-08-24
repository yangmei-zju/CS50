#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
    Number = get_long("Number:");
    }while(Number>0);

    int sum1 = 0;
    int sum2 = 0;
    int a = 0;
    int sum = 0;
    for(int i = 1,number = Number;number>0;i++)
    {
        a = number%10;
        number = number/10;
        if(i%2==0)
        {
            sum1+ = (a*2);
        }
        else
            sum2+ = a;

    }

    int length = 0;
    length = i;
    sum = sum1 + sum2;
    if(sum%10=!0)
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

    if((b == 34 || b == 37)&& length = 15)
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