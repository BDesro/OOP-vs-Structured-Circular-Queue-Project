#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntQueueOOP.h"

int main()
{
	IntQueueOOP* queue = new IntQueueOOP();

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
			printf("What integer would you like to add?\n");
			int element;
			scanf("%d", &element);

			bool success = queue->enqueue(element);
			
			if (success)
				printf("%d added to the queue.\n", element);
			else
			{
				printf("Memory Issue: could not add element. Closing...\n");
				choice = 5;
			}
			break;
		}
		case 2:
		{
			if (queue->getSize() > 0)
			{
				int frontNum = queue->dequeue();
				printf("%d retrieved successfully.\n", frontNum);
			}
			else
				printf("Queue is empty!");
			break;
		}
		case 3:
			printf("Size of Queue is: %d\n", queue->getSize());
			break;
		case 4:
			if (queue->getSize() != 0)
			{
				int* displayQ = queue->getElements();

				printf("[");
				for (int i = 0; i < queue->getSize(); i++)
				{
					printf("%d", displayQ[i]);
					if (i != queue->getSize() - 1)
						printf(", ");
				}
				printf("]\n");

				free(displayQ);
			}
			else
				printf("Queue is Empty");
			break;
		case 5:
			printf("Have a Great Day!");
			break;
		default:
			printf("Invalid Input");
		}
	}

	delete queue;
}