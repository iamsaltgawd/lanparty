#include "reqs.h"



void task1(team_t **head_ref, char *arg, int *n) {
    FILE *pf = fopen(arg, "rt");
    if (pf == NULL) {
        fprintf(stderr, "nu merge fisieru");
        exit -1;
    }

    fscanf(pf, "%d", n);
    
    for (int i = 0; i < *n; i++) {
        addAtBeginning(head_ref, pf);
    }
    fclose(pf);
    return;
}

void task2(team_t **head_ref, int *n) {
    int newNum;
    float minPoints;
    for (newNum = 1; newNum < (*n) / 2; newNum *= 2);
    team_t *p = NULL;
    team_t *delTeam = NULL;
    while (newNum < *n) {
        minPoints = (*head_ref)->teamPoints;
        delTeam = *head_ref;
        p = (*head_ref)->next;
        while (p != NULL) {
            if (p->teamPoints < minPoints) {
                minPoints = p->teamPoints;
                delTeam = p;
            }
            p = p->next;
        }
        removeTeam(head_ref, &delTeam);
        (*n)--;
    }

    return;
}