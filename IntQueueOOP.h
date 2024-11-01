class IntQueueOOP
{
private:
	int size;
	int capacity;
	const int initCapacity = 20;
	int head;
	int tail;
	int* queue;
public:
	IntQueueOOP();
	~IntQueueOOP();
	int getSize();
	int* getElements();
	bool enqueue(int value);
	int dequeue();
};