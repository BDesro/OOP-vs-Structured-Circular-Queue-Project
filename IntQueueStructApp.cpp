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
		printf("1. Add an Integer\n");
		printf("2. Retrieve an Integer\n");
		printf("3. Get Size of Queue\n");
		printf("4. Get All Queue Elements\n");
		printf("5. Exit\n");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1: // Add integer to the queue
		{
			int element = 0;
			printf("What Integer Would You Like to Add?\n");
			scanf("%d", &element);

			enqueue(&queue, &size, &capacity, &head, &tail, element);
			printf("The value %d has been added to the queue.\n", element);
			break;
		}
		case 2: // retrieve next integer from queue
		{
			int next = dequeue(queue, &size, capacity, &head);

			if (next != -1)
				printf("Value: %d, retrieved successfully.", next);
			else
				printf("Queue empty, can't retrieve\n");
			break;
		}
		case 3: // Print the size of the queue
			printf("Queue Size is: %d\n", size);
			break;
		case 4: // Display the elements of the queue
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
		case 5: //Exit with a kind farewell.
			printf("Have a Great Day!");
			break;
		default:
			printf("Invalid Input, Enter (1,2,3,4,or 5)");
		}
	}
	free(queue);

	return 1;
}