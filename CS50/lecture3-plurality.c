#include <stdio.h>
#include <cs50.h>
#include <string.h>

// initialize global variables for functions outside main
#define MAX_CANDIDATES 9

typedef struct{
    string person;
    int count;
} candidates;

int n;
candidates voting[MAX_CANDIDATES];

bool vote(string name); // Bool because i want return dicision
void print_winner(void);

/////////////////////////////////////////////////////////////////////////

int main(int argc, string argv[])
{   
    n = argc;

    for (int j = 0; j < n; j++) //Fill candidates structure
    {
        voting[j].person = argv[j+1];
        voting[j].count = 0;
    }

    int number = get_int("Number of voters: ");

    for (int i = 0; i < number; i++)
    {
        string candidate = get_string("Vote: ");

        vote(candidate);
    }

    print_winner();

    return 0;
}

////////////////////////////////////////////////////////////////////////

bool vote(string name) // If candide gets a vote, add one vote to that candidate
{
    for (int i = 0; i < n-1; i++)
    {
        if (strcmp(name, voting[i].person) == 0)
        {
            voting[i].count += 1;
            return true;
        }
    }
    printf("Invalid vote.\n"); // If not same name return
    return false;
}

void print_winner(void)
{
    int votes = 0;
    votes = voting[0].count; // initialize first vote count

    for (int i = 1; i < n; i++) // Find candidate with the highest score
    {
        if (votes < voting[i].count)
        {
            votes = voting[i].count;
        }
    }

    for (int j = 0; j < n; j++) // Print everyove with the highest score (even tie)
    {
        if (votes == voting[j].count)
        {
            printf("Winner is: %s\n", voting[j].person);
        }
    }
}