#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#pragma once



#pragma region data_types

typedef struct Player {
    char* firstName;
    char* secondName;
    int points;
} player_t;

typedef struct node {
    Data val;
    struct node* next;
} Node_t;

typedef struct {
    Node_t *front, *rear;
} Queue_t;

#pragma endregion data_types

///////////////////////////////////////////////////////////////////////////////

#pragma region Liste

void addAtBeginning(Node_t **head, Data v);
void addAtEnd(Node_t** head, Data v);
void display(Node_t *head);

#pragma endregion Liste

///////////////////////////////////////////////////////////////////////////////

#pragma region Stive

Data top(Node_t *top);
void push(Node_t**top, Data v);
Data pop(Node_t**top);
int isEmpty(Node_t*top);
void deleteStack(Node_t**top);

#pragma endregion Stive

///////////////////////////////////////////////////////////////////////////////

#pragma region Cozi

Queue_t* createQueue();

void enQueue(Queue_t*q, Data v);
 
Data deQueue(Queue_t*q);

int isEmptyQ(Queue_t*q);

void deleteQueue(Queue_t*q);

#pragma endregion Cozi

///////////////////////////////////////////////////////////////////////////////