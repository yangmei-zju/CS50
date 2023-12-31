#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];
//global variables
int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] ++;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int n = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[n].winner = i;
                pairs[n].loser = j;
                n++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[n].winner = j;
                pairs[n].loser = i;
                n++;
            }
        }
    }
    pair_count = n ;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count- i - 1; j++)
        {
            if ((preferences[pairs[j].winner][pairs[j].loser] / preferences[pairs[j].loser][pairs[j].winner]) < (preferences[pairs[j+1].winner][pairs[j+1].loser] / preferences[pairs[j+1].loser][pairs[j+1].winner]))
            {
                int t, p;
                t = pairs[j].winner;
                p = pairs[j].loser;
                pairs[j].winner = pairs[j+1].winner;
                pairs[j].loser = pairs[j+1].loser;
                pairs[j+1].winner = t;
                pairs[j+1].loser = p;
            }
        }
    }
    return;
}

bool is_line(int loser, int winner)
{
    if (winner == loser)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (is_line(i, winner))
            {
                return true;
            }
        }
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int n = 0; n < pair_count; n++)
    {
        if (is_line(pairs[n].loser, pairs[n].winner) == false)
        {
            locked[pairs[n].winner][pairs[n].loser] = true;
        }

    }
    return;
}

// Print the winner of the election
/*void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        int j = 0;
       while(locked[j][i] == false)
       {
        j++;
        if( j == candidate_count)
        {
            printf("%s",candidates[i]);
        }
       }
    }
    return;
}*/
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        bool isLoser = false;
        for (int j = 0; j < candidate_count; j++)
        {
            // j -> i
            if (locked[j][i])
            {
                isLoser = true;
                break;
            }
        }
        if (!isLoser)
        {
            printf("%s\n", candidates[i]);
            break;
        }
    }
    return;
}