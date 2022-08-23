#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
    number = get_long();
    }while(number>0);

    int sum1 = 0;
    int sum2 = 0;
    int a = 0;
    int sum = 0;
    for(i = 1;number>0;i++){
        a = number%10;
        number = number/10;
        if(i%2==0)
        {
            sum1+ = (a*2);
        }else
            sum2+ = a;

    }




}