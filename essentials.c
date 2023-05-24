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
    if (buffer[strlen(buffer) - 1] == ' ') {
        buffer[strlen(buffer) - 1] = '\0';
    }
    if (buffer[strlen(buffer) - 2] == ' ') {
        buffer[strlen(buffer) - 2] = '\0';
    }
    if (buffer[strlen(buffer) - 1] == '\r') {
        buffer[strlen(buffer) - 1] = '\0';
    }
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

void displayMatch(queue_t *queue, FILE *rout, int *n, team_t **wTeams_ref) {
    int n1, n2, i;
    team_t *lTeams = NULL, *aux = NULL;
    fprintf(rout, "\n--- ROUND NO:%d\n", *n);
    while (!isEmpty(queue)){
        n1 = 33 - strlen(queue->front->team1->teamName);
        n2 = 33 - strlen(queue->front->team2->teamName);
        fprintf(rout, "%s", queue->front->team1->teamName);
        for(i = 0; i < n1; i++) {
            fprintf(rout, " ");
        }
        fprintf(rout, "-");
        for (i = 0; i < n2; i++) {
            fprintf(rout, " ");
        }
        fprintf(rout, "%s\n", queue->front->team2->teamName);

        whoWins(queue->front->team1, queue->front->team2, wTeams_ref, &lTeams);
        (*wTeams_ref)->teamPoints += 1;
        for (i = 0; i < (*wTeams_ref)->playerNum; i++) {
            (*wTeams_ref)->players[i].points += 1;
        }

        queue->front = queue->front->next;
    }
    
    while (lTeams != NULL) {
        aux = lTeams;
        lTeams = lTeams->next;
        free(aux);
    }
    
    return;
}

void whoWins(team_t *t1, team_t *t2, team_t **wTs, team_t **lTeams) {
    if (t1->teamPoints > t2->teamPoints) {
        t1->next = *wTs;
        *wTs = t1;
        t2->next = *lTeams;
        *lTeams = t2;
        return;
    }
    t2->next = *wTs;
    *wTs = t2;
    t1->next = *lTeams;
    *lTeams = t1;
    return;
}

void displayWinners(team_t *winners, int *n, FILE *rout) {
    fprintf(rout, "\nWINNERS OF ROUND NO:%d\n", *n);
    team_t *p = winners;
    while (p != NULL){
        int n1 = 34 - strlen(p->teamName);
        fprintf(rout, "%s", p->teamName);
        for(int i = 0; i < n1; i++) {
            fprintf(rout, " ");
        }
        fprintf(rout, "-  %.2f\n", p->teamPoints);

        p = p->next;
    }
    return;
}

#pragma endregion functions
