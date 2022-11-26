// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

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
    int glag = 1;
    if(fp = fopen(dictionary,"a") == NULL)
    {
        flag = 0;
        return false;
    }
    while(fscanf(fp,"%s",word)  != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            flag = 0;
            return false;
        }
        else
        {
            int index = hash(word);
            strcopy(n->word,word);
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
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int size = 0;
    if(load(dictionary) == false)
    {
        return 0;
    }
    else
    {
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
    }
    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while(curson != 0)
        {
            cursor = cursor->next;
            free()
        }

    return false;
}
