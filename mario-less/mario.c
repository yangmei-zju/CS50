#include <cs50.h>
#include <stdio.h>
void space(int);
void la(int);
int main(void)
{
    int Height = 0;
    do
    {
        //printf("Height:");
        //scanf("%d",&Height);
        Height = get_int("Height:");
    }
    while (Height < 1 || Height > 8);

    for (int i = 1; i <= Height; i++)
    {
        space(Height - i);
        la(i);
        printf("\n");

    }


}
void space(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }

}
void la(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}
/*利用do while输入合适的数*/