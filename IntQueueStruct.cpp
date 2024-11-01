//Small Structured library for basic circular queue functions

#include <stdlib.h>

/*
	Takes all necessary parameters from calling function, then adds value to the queue

	If the queue is completely full, even wrapping around, it is doubled in capacity 
	and reset so that the head is 0 and the tail is the index of size - 1.
*/
int enqueue(int** queue, int* size, int* capacity, int* head, int* tail, int value)
{
	//Check for full queue, update if necessary
	if (*size == *capacity)
	{
		int newCap = *capacity * 2;
		int* newQ = (int*)malloc(newCap * sizeof(int));
		if (newQ == NULL)
			return -1;

		for (int i = 0; i < *size; i++)
			newQ[i] = *queue[(*head + i) % *capacity];

		free(*queue);
		(*queue) = newQ;

		*head = 0;
		*tail = *size - 1;
		*capacity = newCap;
	}

	*tail = (*tail + 1) % *capacity;
	(*queue)[*tail] = value;
	(*size)++;
	return *size;
}

/*
	Takes necessary parameters to retrieve queue's front element

	Since it's circular, the head is simply increased by one. The 
	element isn't technically deleted, but it will be overwritten 
	eventually and exists outside the scope of the queue either
	way.
*/
int dequeue(int queue[], int* size, int cap, int* head)
{
	if (*size <= 0)
		return 0;

	int element = queue[*head];

	*head = (*head + 1) % cap;
	(*size)--;
	return element;
}