#include "essentials.h"



#pragma region functions

void addAtBeginning(team_t **head_ref, FILE *in_ref) {
    team_t newTeam = (team_t *)malloc(sizeof(team_t));
    char buffer[100];
    int n;
    fscanf(in_ref, "%d", &(newTeam->playerNum));
    fgetc(in_ref);
    fgets(buffer, 100, in_ref);
    newTeam->teamName = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(newTeam->teamName, buffer);
    newTeam->players = (player_t *)malloc(newTeam->playerNum * sizeof(player_t));
    for (int i = 0; i < newTeam->playerNum; i++) {
        fscanf(in_ref, "%s", buffer);
        newTeam->players[i].firstName = 
			(char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(newTeam->players[i].firstName, buffer);
        fscanf(in_ref, "%s", buffer);
        newTeam->players[i].lastName = 
			(char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(newTeam->players[i].lastName, buffer);
        fscanf(in_ref, "%d", &(newTeam->players[i].points));
    }
    newTeam->next = *head_ref;
    *head_ref = newTeam;
}

void displayTeams(team_t *head_ref) {
	int i;
    while (head_ref != NULL){
		printf ("%s %d\n", head_ref->teamName, head_ref->playerNum);
		for (i = 0; i < head_ref->playerNum; i++) {
			printf("%s %s %d\n", head_ref->players[i].firstName, 
				head_ref->players[i].lastName, head_ref->players[i].points);
		}
		head_ref = head_ref->next;
	}
	printf("\n");
}
#pragma endregion functions
