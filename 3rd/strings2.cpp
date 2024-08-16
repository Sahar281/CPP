
#include <iostream> 
#include <string.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* freeList(Node* list);
Node* reverseList(Node* list);
bool mirror(Node* list1, Node* list2);
Node* createList(Node* head, int data);
Node* noZero(Node** head);
void printList(Node* head);

int main()
{
	Node* list1 = NULL;
	list1 = createList(list1, 5);
	list1 = createList(list1, 3);
	list1 = createList(list1, 2);
	list1 = createList(list1, 1);

	Node* list2 = NULL;
	list2 = createList(list2, 1);
	list2 = createList(list2, 2);
	list2 = createList(list2, 3);
	list2 = createList(list2, 5);

	Node* list3 = NULL;
	list3 = createList(list3, 1);
	list3 = createList(list3, 4);
	list3 = createList(list3, 3);
	list3 = createList(list3, 5);

	Node* list4 = NULL;
	list4 = createList(list4, 1);
	list4 = createList(list4, 7);
	list4 = createList(list4, 0);
	list4 = createList(list4, 3);
	list4 = createList(list4, 6);
	list4 = createList(list4, 4);
	list4 = createList(list4, 0);
	list4 = createList(list4, 3);
	list4 = createList(list4, 2);
	list4 = createList(list4, 1);

	mirror(list1, list2);
	list1 = freeList(list1);
	cout << endl;

	mirror(list2, list3);
	list2 = freeList(list2);
	list3 = freeList(list3);
	cout << endl;

	cout << "This is the original list: ";
	printList(list4);
	noZero(&list4);
	list4 = freeList(list4);

	return 0;
}

bool mirror(Node* list1, Node* list2) 
{
	Node* currentNode1, * currentNode2;
	currentNode1 = list1;
	currentNode2 = list2;

	if ((currentNode1 != NULL) && (currentNode2 != NULL)) // while both list no empty
	{
		currentNode2 = reverseList(list2); // second list now revers

		while (true && (currentNode1 != NULL) && (currentNode2 != NULL))
		{
			if (currentNode1->data != currentNode2->data) // if node->data are not even in both node
			{
				cout << "False! \nThe lists are not mirror image.\n";
				return false;
			}
			else
			{
				currentNode1 = currentNode1->next; // continue to the next node
				currentNode2 = currentNode2->next; // continue to the next node
				true;
			}
		}

		cout << "True!\nThe lists are mirror image.\n";
	}

	else
		cout << "At least one of the lists is empty.";
}


Node* reverseList(Node* list)
{
	Node* prev = NULL, * curr = list, * next = NULL;
	while (curr != NULL) // loop to revers list while node != empty
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	list = prev;
	return list; //head of miror list
}


Node* noZero(Node** head)
{
	Node* currentNode, * prevNode, * tempNode;

	if (*head == NULL) // if list is empty
		cout << "The list is empty!";

	if ((*head)->data != 0 && (*head)->next == NULL) // if there is one node
	{
		cout << "This is the new list: ";
		printList(*head);
	}

	else
	{
		while ((*head)->data == 0) // while there is 0 in the first node remove until there is somthing else
		{
			tempNode = *head;
			*head = (*head)->next;
			delete tempNode;

			if (*head == NULL)
			{
				cout << "The new list is empty!";
			}
		}

		currentNode = prevNode = *head;
		currentNode = currentNode->next;

		while (currentNode != NULL) // loop when there is more node
		{
			while ((currentNode->data != 0) && (currentNode->next != NULL)) // data !=0 and its not the last node
			{
				currentNode->data = prevNode->data + currentNode->data;
				tempNode = prevNode;
				prevNode = prevNode->next;
				delete tempNode;
				*head = currentNode;
				currentNode = currentNode->next;
			}

			if (currentNode->data == 0) // if node data = 0
			{
				tempNode = currentNode;
				currentNode = currentNode->next;
				prevNode->next = currentNode;
				delete tempNode;

				if (currentNode->data == 0) // if again node data = 0
				{
					tempNode = currentNode;
					currentNode = currentNode->next;
					prevNode->next = currentNode;
					delete tempNode;
				}

				if (currentNode == NULL) // if this is the end of the list
					return *head;

				if (currentNode->data != 0) // if node data != 0
					prevNode = prevNode->next;

				if (currentNode != NULL && currentNode->data != 0) 
					currentNode = currentNode->next;
			}

			if (currentNode == NULL)
			{
				cout << "This is the new list: ";
				printList(*head);
				cout << endl;
			}

			while ((currentNode->data != 0) && (currentNode->next != NULL)) // data !=0 and its not the last node
			{
				prevNode->data = prevNode->data + currentNode->data;
				tempNode = currentNode;
				currentNode = currentNode->next;
				prevNode->next = currentNode;
				delete tempNode;

				if (currentNode->data != 0 && currentNode != NULL) // data !=0 and its not the end of the list
				{
					prevNode->data = prevNode->data + currentNode->data;
					tempNode = currentNode;
					currentNode = currentNode->next;
					prevNode->next = currentNode;
					delete tempNode;
				}
			}

			if (currentNode->next == NULL) //id this is the last node
			{
				prevNode->data = prevNode->data + currentNode->data;
				tempNode = currentNode;
				currentNode = currentNode->next;
				prevNode->next = currentNode;
				delete tempNode;
			}
		}

		cout << "This is the new list: ";
		printList(*head); // go to func print
		cout << endl;
	}
	return *head;
}

void printList(Node* head)
{
	if (head == NULL) // if the list is empty
	{
		cout << endl;
		return;
	}

	cout << head->data; // print data
	if (head->next != NULL)
		cout << ","; // if this is no the last node print ','
	printList(head->next); // recurs
}

Node* createList(Node* head, int data) // create new list
{
	Node* newNode = new Node;
	if (newNode == NULL)
		return head;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	return head;
}

Node* freeList(Node* head) // delete lists
{
	Node* tempNode;
	while (head != NULL)
	{
		tempNode = head->next;
		delete head;
		head = tempNode;
	}

	return NULL;
}
