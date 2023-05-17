#include "essentials.h"



#pragma region functions

void addAtBeginning(team_t **head_ref, FILE *in_ref) {
    team_t *newTeam = (team_t *)malloc(sizeof(team_t));
    char buffer[255];
    int n, s = 0;
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

void displayTeams(team_t *head_ref, FILE *rout_ref) {
	int i;
    while (head_ref != NULL){
		fprintf (rout_ref, "%s\n", head_ref->teamName);
		head_ref = head_ref->next;
	}
	printf("\n");
    return;
}
#pragma endregion functions
