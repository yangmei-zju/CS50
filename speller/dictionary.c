// Implements a dictionary's functionality
#include <stdio.h>//fopen,fclose,fscanf
#include <ctype.h>
#include <stdbool.h>//boll
#include <string.h>//strcopy
#include <stdlib.h>//malloc,free,FILE
#include <strings.h>//strcasecmp

#include "dictionary.h"
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *trv = table[index];
    while (trv != NULL)
    {
        if (strcasecmp(trv->word, word) == 0)
        {
            return true;
        }
        trv = trv->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    FILE *fp;
    if ((fp = fopen(dictionary, "r")) == NULL)
    {
        return false;
    }
    while (fscanf(fp, "%s", word)  != EOF)
    {
        node *n ;
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        int index = hash(word);
        strcpy(n->word, word);
        n->next = table[index];
        table[index] = n;
    }
    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int wsize = 0;
    node *trv;
    for (int i = 0; i < N; i++)
    {
        trv = table[i];
        while (trv != NULL)
        {
            wsize ++;
            trv = trv->next;
        }
    }
    return wsize ;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        if (cursor == NULL)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
