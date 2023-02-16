#include <iostream>
#include <list>
using namespace std;
/*******************************************

Igor Alyeksyeyenko, ia22016

G7. Create function to delete from list all elements with bigger value than previous element (before any element is deleted).

STL::list version

Program created: 2023/02/07

*******************************************/

void printList(list<int>& list)
{
	if (list.empty())
		return;
	//print out the first value outside of loop(for proper formatting)
	cout << list.front();
	//iterate over each remaining item in the list
	for (auto i = (++list.begin()); i != list.end(); i++)
	{
		cout << "->";
		cout << *i;
	}
	//print new line after all of the elements to prevent further input/output on same line
	cout << endl;
}

list<int> removeAllLargerThanPrevious(list<int>& itemList)
{
	//no need to modify empty or lists of one element
	if (itemList.empty() || itemList.size() < 2)
		return itemList;

	auto item = itemList.begin();
	auto adjacent = itemList.begin();
	list<int> newList{ *item };//start a new list which will contain only the remaining elements
	//adjacent will be used for checking for 'larger than previous'
	++adjacent;

	while (adjacent != itemList.end())
	{

		if (*item < *adjacent)
		{//if the next item is smaller, do nothing

		}
		else {//if the previous item is larger, add to new list
			newList.push_back(*adjacent);
		}

		adjacent++;
		item++;
	}

	return newList;
}

int main()
{
	int inputCount = -1;

	while (inputCount < 1)
	{
		cout << "Enter input count(greater than 0): ";
		cin >> inputCount;
	}

	int input;

	cout << "Enter input #1: ";
	cin >> input;

	list<int> list{ input };

	for (int i = 2; i <= inputCount; i++)
	{
		cout << "Enter input #" << i << ": ";
		cin >> input;
		list.push_back(input);
	}

	printList(list);
	list = removeAllLargerThanPrevious(list);
	printList(list);
	return 0;
}