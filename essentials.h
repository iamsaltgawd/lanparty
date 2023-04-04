#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#pragma once



#pragma region data_types

typedef char Data;

typedef struct node {
    Data val;
    struct node* next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

#pragma endregion data_types

///////////////////////////////////////////////////////////////////////////////

#pragma region Liste

void addAtBeginning(Node **head, Data v);
void addAtEnd(Node** head, Data v);
void display(Node *head);

#pragma endregion Liste

///////////////////////////////////////////////////////////////////////////////

#pragma region Stive

Data top(Node *top);
void push(Node**top, Data v);
Data pop(Node**top);
int isEmpty(Node*top);
void deleteStack(Node**top);

#pragma endregion Stive

///////////////////////////////////////////////////////////////////////////////

#pragma region Cozi

Queue* createQueue();

void enQueue(Queue*q, Data v);
 
Data deQueue(Queue*q);

int isEmptyQ(Queue*q);

void deleteQueue(Queue*q);

#pragma endregion Cozi

///////////////////////////////////////////////////////////////////////////////