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
		printf("What would you like to do with the integer queue?\n");
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
			printf("What Integer Would You Like to Add?\n");
			int element;
			scanf("%d", &element);

			bool success = queue->enqueue(element);
			
			if (success)
				printf("The value %d has been added to the queue.\n", element);
			else
			{
				printf("Memory Issue: could not add element. Closing...\n");
				choice = 5;
			}
			break;
		}
		case 2: // retrieve next integer from queue
		{
			if (queue->getSize() > 0)
			{
				int frontNum = queue->dequeue();
				printf("Value: %d, retrieved successfully.\n", frontNum);
			}
			else
				printf("Queue is empty!");
			break;
		}
		case 3: // Print the size of the queue
			printf("Queue Size is: %d\n", queue->getSize());
			break;
		case 4: // Display the elements of the queue
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
				printf("The Queue is Empty");
			break;
		case 5: //Exit with a kind farewell.
			printf("Have a Great Day!");
			break;
		default:
			printf("Invalid Input, enter (1,2,3,4,or 5)");
		}
	}

	delete queue;

	return 1;
}