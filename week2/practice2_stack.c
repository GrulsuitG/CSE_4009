//Template
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int nData;
	struct Node *next;
}Node;

typedef struct Stack{
	Node *top;
}Stack;

void InitializeStack(Stack *stack);
void Push(Stack *stack, int nData);
int Pop(Stack *stack);


int main(void){
	Stack *stack;
	InitializeStack(stack);
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);
	Push(stack, 5);

	printf("Pop : %d\n", Pop(stack));
	printf("Pop : %d\n", Pop(stack));
	printf("Pop : %d\n", Pop(stack));
	return 0;
}

void InitializeStack(Stack *stack){
	
	stack ->top = NULL;

}

void Push(Stack *stack, int nData){
	Node *new = (Node*)malloc(sizeof(Node));
	new->nData = nData;
	new->next = stack->top;
	stack ->top= new;
}

int Pop(Stack *stack){
	if(stack->top ==NULL){
		fprintf(stderr,"stack is empty\n");
		exit(1);
	}
	Node *temp = stack->top;
	int result = temp->nData;
	stack->top = temp->next;
	free(temp);
	return result;
}
