#include <cs50.h>
#include <stdio.h>
void space(int);
void la(int);
int main(void)
{   int Height=0;
    printf("Height:");
    scanf("%d",&Height);

        for(int i = 1;i<=Height;i++)
        {
            space(Height-i);
            la(i);
            printf("\n");

        }


}
void space(int n)
{
    for(int i = 0;i<n;i++)
    {
        printf(" ");
    }

}
void la(int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("#");
    }
}