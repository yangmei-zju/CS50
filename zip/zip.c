#include <stdio.h>
#include <string.h>
#include
#define MAX 10
void zip(char *p);
int main()
{
    char line[MAX];
    line = get_string(line:);
    zip(line);
    puts(line);
    return 0;
}
void zip(char *p)
{
    char *q ;
    q = p;
    int n ;
    while(*p != '\0')
    {
        n = 1;
        while(*p == *(p+n))
        {
            n++;
        }
        if(n >= 10)
        {
            *q++ = (n/10) + '0';
            *q++ = (n%10) + '0';
        }
        else if(n>=2)
        {
            *q++ = n + '0';

        }
        *q++ = *(p+n-1);
        p = p+n;
    }
    *q = '\0';
}