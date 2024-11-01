#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntQueueStruct.h"

int main1()
{
	int capacity = 10;
	int size = 0;
	int head = 0;
	int tail = -1;

	int* queue = (int*)malloc(capacity * sizeof(int));
	if (queue == NULL)
		printf("Not enough memory available");

	int choice = 0;
	while (choice != 5)
	{
		printf("What would you like to do with the queue?\n");
		printf("1. Add element\n");
		printf("2. Retrieve element\n");
		printf("3. Get Size\n");
		printf("4. Get Elements\n");
		printf("5. Exit\n");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			int element = 0;
			printf("Enter Element: ");
			scanf("%d", &element);

			enqueue(&queue, &size, &capacity, &head, &tail, element);
			printf("%d added.\n", element);
			break;
		}
		case 2:
		{
			int next = dequeue(queue, &size, capacity, &head);

			if (next != -1)
				printf("%d retrieved.\n", next);
			else
				printf("Queue empty, can't retrieve\n");
			break;
		}
		case 3:
			printf("Size of Queue: %d\n", size);
			break;
		case 4:
			if (size > 0)
			{
				printf("[");
				for (int i = 0; i < size; i++)
				{
					printf("%d", queue[(head + i) % capacity]);
					if (i != size - 1)
						printf(",");
				}
				printf("]\n");
			}
			else
				printf("Queue empty");
			break;
		default:
			printf("Invalid Input, try again");
		}
	}
	free(queue);

	return 1;
}