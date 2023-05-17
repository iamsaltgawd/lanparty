#include "reqs.h"



void task1(team_t **head_ref, char *arg) {
    FILE *pf = fopen(arg, "rt");
    if (pf == NULL) {
        fprintf(stderr, "nu merge fisieru");
        exit -1;
    }
    int n;
    fscanf(pf, "%d", &n);
    
    for (int i = 0; i < n; i++) {
        addAtBeginning(head_ref, pf);
    }
    fclose(pf);

void task2(team_t **head_ref) {
    
}
    return;
}