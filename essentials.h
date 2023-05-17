#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



#pragma region data types

typedef struct Player {
    char *firstName;
    char *lastName;
    int points;
} player_t;

typedef struct team {
    char *teamName;
    int playerNum;
    player_t *players;
    float teamPoints;
    struct team *next;
} team_t;

#pragma endregion data types

///////////////////////////////////////////////////////////////////////////////

#pragma region functions

void addAtBeginning(team_t **head_ref, FILE *in_ref);

void displayTeams(team_t *head_ref, FILE *rout_ref);

#pragma endregion functions

///////////////////////////////////////////////////////////////////////////////