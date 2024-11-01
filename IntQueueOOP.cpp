// Object class for the Integer Queue

#include <stdlib.h>
#include "IntQueueOOP.h"

IntQueueOOP::IntQueueOOP()
{
	size = 0;
	capacity = initCapacity;
	head = 0;
	tail = -1;

	queue = (int*)malloc(capacity * sizeof(int));
}

IntQueueOOP::~IntQueueOOP()
{
	free(queue);
}

int IntQueueOOP::getSize()
{
	return size;
}

/*
	Initially, I simply returned the queue's array
	all by itself, but learned that that ties it to
	the array that receives it in main(). So now it
	carefully creates a new, separate array that copies
	the values over and then returns the copy.
*/
int* IntQueueOOP::getElements()
{
	int* dispQ = (int*)malloc(size * sizeof(int));
	if (dispQ != NULL)
	{
		for (int i = 0; i < size; i++)
			dispQ[i] = queue[(head + i) % capacity];
	}
	else
		return NULL;

	return dispQ;
}

bool IntQueueOOP::enqueue(int value)
{
	if (size == capacity)
	{
		int newCap = capacity * 2;
		int* newQ = (int*)malloc(newCap * sizeof(int));
		if (newQ == NULL)
			return false;

		for (int i = 0; i < size; i++)
			newQ[i] = queue[(head + i) % capacity];

		free(queue);
		queue = newQ;

		head = 0;
		tail = size - 1;
		capacity = newCap;
	}

	tail = (tail + 1) % capacity;
	queue[tail] = value;
	size++;
	return true;
}

int IntQueueOOP::dequeue()
{
	if (size <= 0)
		return 0;

	int element = queue[head];
	head = (head + 1) % capacity;
	size--;
	return element;
}