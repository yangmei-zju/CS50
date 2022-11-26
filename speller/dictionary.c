// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"
int strcasecomp(char *nword,char *word)
{
    char *nt = toupper(*nword);
    char *t = toupper(*word);
    return(strcpy(nt,t);
}
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26*4;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *trv = table[index];
    while(trv != NULL)
    {
        if (strcasecmp(trv->word, word) == 0)
        {
            return true;
        }
        else
        {
            trv = trv->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int m = toupper(word[0]) - 'A';
    int n = toupper(word[1]) - 'A';
    int index = 4 * m + n * 26 / 4;
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    FILE *fp;
    int flag = 1;
    if((fp = fopen(dictionary,"a")) == NULL)
    {
        flag = 0;
        return false;
    }
    while(fscanf(fp,"%s",word)  != EOF)
    {
        node *n ;
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            flag = 0;
            return false;
        }
        else
        {
            int index = hash(word);
            strcpy(n->word,word);
            if(table[index] == NULL)
            {
                table[index] = n;
            }
            else
            {
                n->next = table[index];
                table[index] = n;
            }
        }
    }
    if (flag == 1)
    {
        return true;
    }
    return false;
    fclose(fp);
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int size = 0;
    node *trv;
    for(int i = 0; i < N; i++)
    {
        trv = table[i];
        while(trv != NULL)
        {
             size ++;
             trv = trv->next;
        }
     }

    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while(cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        if(table[i] == NULL)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    if(flag == 0)
    {
        return false;
    }

}
