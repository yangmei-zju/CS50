#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int count_words(string text);
int count_letters(string text);
int count_sentences(string text);


int main()
{
    string text = get_string("Text:");
    float l = 0;
    float s = 0;
    float index = 0;
    int words = 0;
    int letters = 0;
    int sentences = 0;
    words = count_words(text);
    sentences = count_sentences(text);
    letters = count_letters(text);
    l = letters / words* 100;
    s = sentences / words * 100;
    index = (0.0588 * l) -( 0.296 * s) - 15.8;
    printf("%d %d %d %f\n",words,letters,sentences,l);

    /*if (index < 1.5)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 15.5)
    {
        printf("Grade 16+\n");
    }
    else
    {
        if (index >= (int)index + 0.5)
        {
            printf("Grade %d\n",(int)index + 1);

        }
        else
        {
            printf("Grade %d\n",(int)index);
        }
    }*/
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }

    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

    }
    return letters;
}
