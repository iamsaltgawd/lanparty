#include "essentials.h"



#pragma region Liste

void addAtBeginning(Node **head, Data v)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->val = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Node** head, Data v)
{
	Node *aux=*head;
	Node* newNode = (Node*)malloc(sizeof(Node)); 
	newNode->val = v; 
	if (*head == NULL) addAtBeginning(&*head, v);
	else{  
		while (aux->next!=NULL) aux = aux->next;
		aux->next = newNode;  
		newNode->next = NULL; 
	}
}

void display(Node *head)
{
	while (head!=NULL){
		printf ("%d ", head->val);
		head=head->next;
	}
	printf("\n");
}

#pragma endregion Liste

#pragma region Stive
Data top(Node *top){
	if (isEmpty(top)) return INT_MIN;
	return top->val;
} 

void push(Node**top, Data v) {
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->val=v;
	newNode->next=*top;
	*top=newNode;
}

Data pop(Node**top) {
	if (isEmpty(*top)) return INT_MIN;
	Node *temp=(*top); 		
	Data aux=temp->val;	
	*top=(*top)->next;      		
	free(temp);
	return aux;
}

int isEmpty(Node*top){
	return top==NULL;
}
	
void deleteStack(Node**top){
	Node  *temp;
	while (!isEmpty(*top)) {
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}

#pragma endregion Stive

#pragma region Cozi
Queue* createQueue(){
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q==NULL) return NULL;	
	q->front=q->rear=NULL;
	return q;	
}

 void enQueue(Queue*q, Data v){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->val=v;
	newNode->next=NULL;

	if (q->rear==NULL) q->rear=newNode; 
	else{
		(q->rear)->next=newNode;
		(q->rear)=newNode;
	}
	if (q->front==NULL) q->front=q->rear; 
}
 
Data deQueue(Queue*q) {  
	Node* aux; Data d;
	if (isEmptyQ(q)) return INT_MIN;
	
	aux=q->front; 
	d=aux->val;
	q->front=(q->front)->next;
	free(aux);
	return d;  	
} 

int isEmptyQ(Queue*q){
	return (q->front==NULL);
}

void deleteQueue(Queue*q){
	Node* aux;
	while (!isEmptyQ(q)){
		aux=q->front;
		q->front=q->front->next;
		free(aux);
	}
	free(q);
}	

#pragma endregion Cozi
