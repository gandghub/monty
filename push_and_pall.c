#include "monty.h"

/**
 * f_pall - Prints all the values on the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the file (unused).
 * Return: No return value.
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *current;

	(void)counter;

	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * f_push - Pushes an element to the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the file.
 * Return: No return value.
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
