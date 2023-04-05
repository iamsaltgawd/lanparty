#include "essentials.h"



#pragma region Liste

void addAtBeginning(Node_t **head, Data v)
{
	Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
	newNode->val = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Node_t** head, Data v)
{
	Node_t *aux=*head;
	Node_t* newNode = (Node_t*)malloc(sizeof(Node_t)); 
	newNode->val = v; 
	if (*head == NULL) addAtBeginning(&*head, v);
	else{  
		while (aux->next!=NULL) aux = aux->next;
		aux->next = newNode;  
		newNode->next = NULL; 
	}
}

void display(Node_t *head)
{
	while (head!=NULL){
		printf ("%d ", head->val);
		head=head->next;
	}
	printf("\n");
}

#pragma endregion Liste

#pragma region Stive
Data top(Node_t *top){
	if (isEmpty(top)) return INT_MIN;
	return top->val;
} 

void push(Node_t**top, Data v) {
	Node_t* newNode=(Node_t*)malloc(sizeof(Node_t));
	newNode->val=v;
	newNode->next=*top;
	*top=newNode;
}

Data pop(Node_t**top) {
	if (isEmpty(*top)) return INT_MIN;
	Node_t *temp=(*top); 		
	Data aux=temp->val;	
	*top=(*top)->next;      		
	free(temp);
	return aux;
}

int isEmpty(Node_t*top){
	return top==NULL;
}
	
void deleteStack(Node_t**top){
	Node_t  *temp;
	while (!isEmpty(*top)) {
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}

#pragma endregion Stive

#pragma region Cozi
Queue_t* createQueue(){
	Queue_t *q;
	q=(Queue_t *)malloc(sizeof(Queue_t));
	if (q==NULL) return NULL;	
	q->front=q->rear=NULL;
	return q;	
}

 void enQueue(Queue_t*q, Data v){
	Node_t* newNode=(Node_t*)malloc(sizeof(Node_t));
	newNode->val=v;
	newNode->next=NULL;

	if (q->rear==NULL) q->rear=newNode; 
	else{
		(q->rear)->next=newNode;
		(q->rear)=newNode;
	}
	if (q->front==NULL) q->front=q->rear; 
}
 
Data deQueue(Queue_t*q) {  
	Node_t* aux; Data d;
	if (isEmptyQ(q)) return INT_MIN;
	
	aux=q->front; 
	d=aux->val;
	q->front=(q->front)->next;
	free(aux);
	return d;  	
} 

int isEmptyQ(Queue_t*q){
	return (q->front==NULL);
}

void deleteQueue(Queue_t*q){
	Node_t* aux;
	while (!isEmptyQ(q)){
		aux=q->front;
		q->front=q->front->next;
		free(aux);
	}
	free(q);
}	

#pragma endregion Cozi
