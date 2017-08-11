#include "stdafx.h"
#include "InsertionSortList.h"

// O(n^2)
ListNode* InsertionSortList::solution(ListNode* head)
{
	ListNode* currNode = head;
	ListNode* prevNode = NULL;
	ListNode* tempNode = NULL;
	ListNode* newHead = head;

	while (currNode != NULL)
	{
		tempNode = newHead;
		prevNode = NULL;

		if (currNode->next != NULL && currNode->val > currNode->next->val)

		while (currNode->next != NULL && tempNode != currNode->next)
		{
			if (tempNode->val > currNode->next->val)
			{
				if (prevNode != NULL)
				{
					prevNode->next = currNode->next;
					currNode->next = currNode->next->next;
					prevNode->next->next = tempNode;
				}
				else
				{
					newHead = currNode->next;
					currNode->next = currNode->next->next;
					newHead->next = tempNode;
				}

				break;
			}

			prevNode = tempNode;
			tempNode = tempNode->next;
		}

		currNode = currNode->next;
	}

	return newHead;
}