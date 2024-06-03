#include <iostream>

struct node
{
	int value;

	node *pNext;
};

struct Queue
{
	int size{};

	node *pHead{ nullptr };
	node *pTail{ nullptr };
};

void EnQueue(Queue &queue, int value)
{
	node *n = new node;

	n->value = value;
	n->pNext = nullptr;
	queue.size++;

	if (queue.pHead == nullptr && queue.pTail == nullptr)
	{
		queue.pHead = n;
		queue.pTail = n;
	}
	else
	{
		queue.pTail->pNext = n;
		queue.pTail = n;
	}
}

void DeQueue(Queue &queue)
{
	if (queue.pHead == nullptr)
	{
		std::cout << "Queue is empty" << std::endl;
		return;
	}

	node *n = queue.pHead;

	if (queue.pTail == n)
	{
		queue.pTail = n->pNext;
	}
	queue.pHead = n->pNext;

	queue.size--;
	delete n;
}

int GetQueueSize(const Queue &queue)
{
	return queue.size;
}

bool FindValue(const Queue &queue, int value)
{
	node *n = queue.pHead;

	while (n != nullptr)
	{
		if (n->value == value)
		{
			std::cout << value << " Exist" << std::endl;
			return true;
		}
		n = n->pNext;
	}

	std::cout << value << " not Exist" << std::endl;
	return false;
}

void DeleteAll(Queue &queue)
{
	node *n = queue.pHead;
	node *next = nullptr;

	while (n != nullptr)
	{
		next = n->pNext;
		delete n;

		n = next;
	}

	queue.pHead = queue.pTail = nullptr;
	queue.size = 0;
}

void PrintQueue(const Queue &queue)
{
	node *n = queue.pHead;

	while (n != nullptr)
	{
		std::cout << n->value << " ";
		n = n->pNext;
	}
	std::cout << std::endl;
}

int main()
{
	Queue queue{};

	int choice;
	int value;
	while (true)
	{
		std::cout << "1 : Enqueue 2 : Dequeue 3 : Queue Size 4 : Find value" <<
			" 5 : Delete All 6 : End Simul > ";
		std::cin >> choice;

		if (choice == 1)
		{
			std::cout << "Value? ";
			std::cin >> value;
			EnQueue(queue, value);
		}
		else if (choice == 2)
		{
			DeQueue(queue);
		}
		else if (choice == 3)
		{
			std::cout << "Size : " << GetQueueSize(queue) << std::endl;
		}
		else if (choice == 4)
		{
			std::cout << "Value? ";
			std::cin >> value;
			FindValue(queue, value);
		}
		else if (choice == 5)
		{
			DeleteAll(queue);
		}
		else if (choice == 6)
		{
			break;
		}

		std::cout << "----Queue----" << std::endl;
		PrintQueue(queue);
	}
}