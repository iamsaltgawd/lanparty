#include "essentials.h"



#pragma region functions

void addAtBeginning(team_t **head_ref, FILE *in_ref) {
    team_t *newTeam = (team_t *)malloc(sizeof(team_t));
    char buffer[255];
    int s = 0;
    fscanf(in_ref, "%d", &(newTeam->playerNum));
    fgetc(in_ref);
    fgets(buffer, 255, in_ref);
    buffer[strlen(buffer) - 1] = '\0';
    newTeam->teamName = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(newTeam->teamName, buffer);
    newTeam->players = (player_t *)malloc(newTeam->playerNum * sizeof(player_t));
    for (int i = 0; i < newTeam->playerNum; i++) {
        fscanf(in_ref, "%s", buffer);
        buffer[strlen(buffer) - 1] = '\0';
        newTeam->players[i].firstName = 
			(char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(newTeam->players[i].firstName, buffer);
        fscanf(in_ref, "%s", buffer);
        buffer[strlen(buffer) - 1] = '\0';
        newTeam->players[i].lastName = 
			(char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(newTeam->players[i].lastName, buffer);
        fscanf(in_ref, "%d", &(newTeam->players[i].points));
        s += newTeam->players[i].points;
    }
    newTeam->teamPoints = 1.0 * s / newTeam->playerNum; 
    newTeam->next = *head_ref;
    *head_ref = newTeam;
    return;
}

void removeTeam(team_t **head_ref, team_t **rmnode) {
    
    if (*head_ref == *rmnode) {
        team_t *temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    } else {
        team_t *p = *head_ref;
        while (p->next != *rmnode) {
            p = p->next;
        }
        team_t *temp = p->next;
        p->next = p->next->next;
        free(temp);
        return;
    }
    return;  
}

void displayTeams(team_t *head_ref, FILE *rout_ref) {
    while (head_ref != NULL){
		fprintf (rout_ref, "%s\n", head_ref->teamName);
		head_ref = head_ref->next;
	}
	printf("\n");
    return;
}

queue_t *createQueue() {
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    if (q == NULL) {
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

void enQueue(queue_t *q, team_t *team1, team_t *team2) {
	match_t* newMatch = (match_t*)malloc(sizeof(match_t));
	newMatch->team1 = team1;
    newMatch->team2 = team2;
	newMatch->next = NULL;

	if (q->rear == NULL) {
        q->rear = newMatch; 
	    } else {
            (q->rear)->next = newMatch;
            (q->rear) = newMatch;
        }
	if (q->front == NULL) {
        q->front = q->rear; 
    }
    return;
}
match_t *deQueue(queue_t *q) {  
	match_t *aux = NULL, *match = NULL;

	if (isEmpty(q)) {
        return NULL;
    }

	aux = q->front;
    match->team1 = aux->team1;
    match->team2 = aux->team2;
	q->front = (q->front)->next;
	free(aux);
	return match;
} 

int isEmpty(queue_t *q){
	return (q->front == NULL);
}

#pragma endregion functions
