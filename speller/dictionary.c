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
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int m = hash(word);
    node *trv = table[m];
    while(trv != NULL)
    {
        if (strcopy(trv->word, word) == 0)
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
    return toupper(word[0]) - 'A';
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
            int m = hash(word);
            strcopy(n->word,word);
            if(table[m] == NULL)
            {
                table = n;
            }
            else
            {
                n->next = table[m];
                table[m] = n;
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
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
