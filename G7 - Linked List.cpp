#include <iostream>
using namespace std;
/*******************************************

Igor Alyeksyeyenko, ia22016

G7. Create function to delete from list all elements with bigger value than previous element (before any element is deleted).

Linked List version

Program created: 2023/02/07

*******************************************/

struct Node
{
public:
	int value;
	Node* next;
	void push_back(int value);
	Node(int value) {
		this->value = value;
		this->next = NULL;
	}
	Node(int values[])
	{
		//safe to assume array has at least one element, otherwise other constructor would fire
		this->value = values[0];
		this->next = NULL;
		//insert every passed array value as a new node
		for (int i = 1; i <= sizeof(values) / sizeof(int); i++)
		{
			this->push_back(values[i]);
		}
	}
};


void printList(Node* head)
{
	Node* current = head;
	//if the passed list is empty, print nothing
	if (current != NULL) {
		//print out the first value outside of loop(for proper formatting)
		cout << head->value;
		//go over each remaining node in the list
		while (current->next != NULL)
		{
			//print them out
			current = current->next;
			cout << "->";
			cout << current->value;
		}
		//print new line after all of the elements to prevent further input/output on same line
		cout << endl;
	}
}

//insert a value at the end of the linked list
void Node::push_back(int value)
{
	Node* current = this;
	//find the last item in the list
	while (current->next != NULL)
		current = current->next;
	//add a new node to the end
	Node* new_node = new Node(value);
	current->next = new_node;
}

void removeAllLargerThanPrevious(Node* list)
{
	if (!list)//empty/null list passed
		return;

	Node* current = list;
	Node* extractedNode;
	//go over each node
	while (current->next != NULL)
	{
		//if the next node is larger, delete it
		if (current->value < current->next->value) {
			extractedNode = current->next;
			//switch references to the node following the one we're about to delete
			current->next = current->next->next;
			//remove references from the deleted node
			extractedNode->next = NULL;
			//actually delete it
			delete extractedNode;
			extractedNode = NULL;
		}//only if it is not larger, advance to the next node
		else {
			current = current->next;
		}
	}
}

int main()
{
	int inputCount = -1;

	while (inputCount<1)
	{
		cout << "Enter input count(greater than 0): ";
		cin >> inputCount;
	}

	int input;

	cout << "Enter input #1: ";
	cin >> input;
	Node* list = new Node(input);

	for (int i = 2; i <= inputCount; i++)
	{
		cout << "Enter input #" << i << ": ";
		cin >> input;
		list->push_back(input);
	}

	printList(list);
	removeAllLargerThanPrevious(list);
	printList(list);
	return 0;
}