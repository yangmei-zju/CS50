#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int space(string argv);
int alpha(string argv);
int repeat(string argv);

int main(int argc, string argv[])
{
    if( argc != 0)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

   else if(strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if(! alpha(argv[1]))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    else if(! repeat(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

   /*string plaintext = get_string("plaintext:");*/





}

int space(string argv)
{
    int i = 0;
    int n = 0;
    for(i = 0;i < strlen(argv);i ++)
    {
        if(isspace(argv[i]))
        {
            n++;
        }
    }
    return n;
}
int alpha(string argv)
{
    int i = 0;
    int n = 26;
    for(i=0;argv[i] != '\0';i++)
    {
        if(isalpha(argv[i]))
        {
            n--;
        }
    }
    return n;
}
int repeat(string argv)
{
    int n = 0;
    for(int i = 1;argv[i] != '\0';i++)
    {
        for(int j = 0; j < i;j++)
        {
            if(argv[j] == argv[i])
            {
                n++;
            }
        }


    }
    return n;
}