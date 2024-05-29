#pragma once

#include <cstring>
#include "Monster.h"

struct SingleLinkedList
{
	Monster2 *pHead;
	Monster2 *pTail;
	int size;
};

// Time Complexity : O(1)
// Space Complexity : O(1)
void CreateMonster(SingleLinkedList &list, const char *name, int hp, int mp)
{
	Monster2 *m = new Monster2;

	m->hp = hp;
	m->mp = mp;
	//strncpy(m->name, name, NAME_LENGTH);
	strcpy_s(m->name, NAME_LENGTH, name);
	m->pNext = nullptr;
	list.size++;

	if (list.pHead == nullptr && list.pTail == nullptr)
	{
		list.pHead = m;
		list.pTail = m;
	}
	else
	{
		list.pTail->pNext = m;
		list.pTail = m;
	}
}

// Time Complexity : O(1)
// Space Complexity : O(1)
int GetMonsterCount(const SingleLinkedList &list)
{
	return list.size;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
void PrintMonters(const SingleLinkedList &list)
{
	Monster2 *m = list.pHead;

	while (m != nullptr)
	{
		std::cout << m->name << ", " << m->hp << ", " << m->mp << std::endl;
		m = m->pNext;
	}
}

bool FindMonster(const SingleLinkedList &list, const char *name)
{
	Monster2 *m = list.pHead;

	while (m != nullptr)
	{
		if (!strcmp(m->name, name))
		{
			return true;
		}
		m = m->pNext;
	}

	return false;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
void DeleteList(SingleLinkedList &list)
{
	Monster2 *m = list.pHead;
	Monster2 *next;

	while (m!= nullptr)
	{
		next = m->pNext;
		delete m;
		
		m = next;
	}

	list.size = 0;
	list.pHead = nullptr;
	list.pTail = nullptr;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
void DeleteMonster(SingleLinkedList &list, const char *name)
{
	Monster2 *m = list.pHead;
	Monster2 *previous = nullptr;

	list.size--;

	while (m != nullptr)
	{
		if (!strcmp(m->name, name))
		{
			break;
		}

		previous = m;
		m = m->pNext;
	}

	if (m != nullptr)
	{
		if (list.pHead == list.pTail)
		{
			list.pHead = list.pTail = nullptr;
		}
		else if (previous == nullptr)
		{
			list.pHead = m->pNext;
		}
		else if (m == list.pTail)
		{
			previous->pNext = nullptr;
			list.pTail = previous;
		}
		else
		{
			previous->pNext = m->pNext;
		}

		delete m;
	}

	
}

void SingleLinekdListTest()
{
	SingleLinkedList list{};

	CreateMonster(list, "Wolf", 100, 0);
	CreateMonster(list, "Demon", 200, 100);

	std::cout << GetMonsterCount(list) << std::endl;
	PrintMonters(list);

	std::cout << FindMonster(list, "Slime") << std::endl;

	DeleteList(list);

	DeleteMonster(list, "Demon");
}


