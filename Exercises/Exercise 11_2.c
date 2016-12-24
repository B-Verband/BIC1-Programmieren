/* Exercise 11_2 */

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

/* Programmcode hier einfügen */
#include <stdio.h>

typedef struct Stack {
	int count;		/* number of items currently stored in stack */
	int	capacity;	/* size of data array */
	int	*data;		/* data array */
}
Stack;

Stack create_stack(int initialcapacity);
void push(int value, Stack *stack);
int pop(Stack *stack);
int delete_stack(Stack *stack);

int main(int argc, char* argv[])
{
	int i;
	
	/* create empty stack */
	Stack stack = create_stack(20);

	/* push elements onto stack */
	for (i = 0; i < 28; i++) push(i, &stack);

	/* pop all elements from stack */
	while (stack.count > 0) printf("%d\n", pop(&stack));

	delete_stack(&stack);

	return 0;
}

Stack create_stack(int initialcapacity)
{
	Stack result;
	result.count = 0;	/* emptystack */
	result.capacity = initialcapacity;
	result.data = malloc(initialcapacity * sizeof(int));
	if (!result.data) { /* exception handling */ }
	return result;
}

void push(int value, Stack *stack)
{
	if (stack->count == stack->capacity) {
		int i;
		int *helper = malloc(2 * stack->capacity * sizeof(int));
		if (helper == NULL) { /* exception handling */ }

		for (i = 0; i < stack->count; i++) {
			helper[i] = stack->data[i];
		}

		stack->capacity *= 2;
		free(stack->data);
		stack->data = helper;
	}
	stack->data[stack->count++] = value;
}

int pop(Stack *stack)
{
	return stack->data[--stack->count];
}

int delete_stack(Stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	return 0;
}
