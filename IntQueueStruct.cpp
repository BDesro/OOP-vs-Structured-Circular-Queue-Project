#include <stdlib.h>

int enqueue(int** queue, int* size, int* capacity, int* head, int* tail, int value)
{
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

int dequeue(int queue[], int* size, int cap, int* head)
{
	if (*size <= 0)
		return 0;

	int element = queue[*head];

	*head = (*head + 1) % cap;
	(*size)--;
	return element;
}