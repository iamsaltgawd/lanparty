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

typedef struct match {
    team_t *team1;
    team_t *team2;
    struct match *next;
} match_t;

typedef struct queue {
    match_t *rear;
    match_t *front;
} queue_t;

#pragma endregion data types

///////////////////////////////////////////////////////////////////////////////

#pragma region functions

void addAtBeginning(team_t **head_ref, FILE *in_ref);
void removeTeam(team_t **head_ref, team_t **rmnode);
void displayTeams(team_t *head_ref, FILE *rout_ref);
queue_t *createQueue();
void enQueue(queue_t *q, team_t *team1, team_t *team2);
match_t *deQueue(queue_t *q);
int isEmpty(queue_t *q);

#pragma endregion functions

///////////////////////////////////////////////////////////////////////////////