#include <iostream>

// stack
struct node
{
	int value;

	node *pNext;
	node *pPrev;
};

struct Stack
{
	int size{};

	node *top{ nullptr };
};

void Push(Stack &stack, int value)
{
	node *n = new node;

	n->value = value;
	n->pNext = n->pPrev = nullptr;
	stack.size++;

	if (stack.top == nullptr)
	{
		stack.top = n;
	}
	else
	{
		n->pPrev = stack.top;
		stack.top->pNext = n;
		stack.top = n;
	}
}

void Pop(Stack &stack)
{
	if (stack.top == nullptr)
	{
		std::cout << "Stack is empty" << std::endl;
		return;
	}

	node *n = stack.top;
	if (stack.top->pPrev == nullptr)
	{
		stack.top = nullptr;
	}
	else
	{
		stack.top = stack.top->pPrev;
		n->pPrev->pNext = nullptr;
	}

	delete n;
	stack.size--;
}

int GetStackSize(const Stack &stack)
{
	return stack.size;
}

bool FindValue(const Stack &stack, int value)
{
	node *n = stack.top;

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

void DeleteAll(Stack &stack)
{
	node *n = stack.top;

	while (n != nullptr)
	{
		stack.top = stack.top->pPrev;
		delete n;
		n = stack.top;
	}

	stack.top = nullptr;
	stack.size = 0;
}

void PrintStack(const Stack &stack)
{
	node *n = stack.top;

	while (n != nullptr)
	{
		std::cout << n->value << std::endl;
		n = n->pPrev;
	}
}

int main()
{
	Stack stack{};

	int choice;
	int value;
	while (true)
	{
		std::cout << "1 : Push 2 : Pop 3 : Stack Size 4 : Find value" <<
			" 5 : Delete All 6 : End Simul > ";
		std::cin >> choice;

		if (choice == 1)
		{
			std::cout << "Value? ";
			std::cin >> value;
			Push(stack, value);
		}
		else if (choice == 2)
		{
			Pop(stack);
		}
		else if (choice == 3)
		{
			std::cout << "Size : " << GetStackSize(stack) << std::endl;
		}
		else if (choice == 4)
		{
			std::cout << "Value? ";
			std::cin >> value;
			FindValue(stack, value);
		}
		else if (choice == 5)
		{
			DeleteAll(stack);
		}
		else if (choice == 6)
		{
			break;
		}

		std::cout << "----Stack----" << std::endl;
		PrintStack(stack);
	}
}