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

void removeAllLargerThanPrevious(list<int>& list)
{
	//no need to modify empty or lists of one element
	if (list.empty() || list.size() < 2)
		return;

	auto item = list.begin();
	auto adjacent = list.begin();
	//adjacent will be used for checking for 'larger than previous'
	++adjacent;

	while (adjacent != list.end())
	{

		if (*item < *adjacent)
		{//if the next item is larger, replace it with the next one

			adjacent = list.erase(adjacent);

		}
		else//only if it is not larger, advance both iterators to the next items
		{
			item++;
			adjacent++;
		}
	}

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
	removeAllLargerThanPrevious(list);
	printList(list);
	return 0;
}