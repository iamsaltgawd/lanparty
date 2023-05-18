#include "reqs.h"



int main(int argc, char *argv[]) /// argv[1] = c.in; argv[2] = d.in; argv[3] = r.out
{   
    int *tasks = (int *)malloc(5 * sizeof(int));
    FILE *f = fopen(argv[1], "rt");

    for (int i = 0; i < 5; i++) {
        fscanf(f, "%d", &tasks[i]);
    }
    fclose(f);
    FILE *rout = fopen(argv[3], "wt");
    
    team_t *head = NULL;
    int teamNum;
    task1(&head, argv[2], &teamNum);
    if (tasks[0] == 1 && tasks[1] == 0) {
        displayTeams(head, rout);
    }
    
    task2(&head, &teamNum);

    if (tasks[1] == 1 && tasks[0] == 1) {

        displayTeams(head, rout);
    }


    fclose(rout);
    return 0;
}