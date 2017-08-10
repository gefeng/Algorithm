#include "stdafx.h"
#include "InsertionSortList.h"

// O(n^2)
ListNode* InsertionSortList::solution(ListNode* head)
{
	ListNode* currNode = NULL;
	ListNode* tempNode = NULL;
	int temp = 0;

	if (head == NULL)
		return NULL;

	currNode = head->next;

	if (currNode == NULL)
		return head;

	while (currNode != NULL)
	{
		tempNode = head;

		while (tempNode != currNode)
		{
			if (tempNode->val > currNode->val)
			{
				temp = currNode->val;
				currNode->val = tempNode->val;
				tempNode->val = temp;
			}

			tempNode = tempNode->next;
		}

		currNode = currNode->next;
	}

	return head;
}