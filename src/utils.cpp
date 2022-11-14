#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"

#include <fstream>
#include <sstream>

using namespace std;

void printLine(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "----------------  ";
	}
	cout << endl;
}

void printYoneticiNodes(YoneticiListesi *LIST, int end)
{
	

	YoneticiListesiNode *itr = LIST->FindPrevByPosition(end - 8)->next;
	int index = 0;

	cout << endl;
	cout << endl;

	int count = 0;
	for (YoneticiListesiNode *itr = LIST->FindPrevByPosition(end - 8)->next; itr != NULL && count < 8; itr = itr->next, count++)
	{
		cout << " ";
		cout << itr;
		cout << " ";
		cout << " ";
		cout << " ";
	}

	cout << endl;
	LIST->printLine(count);

	count = 0;
	for (YoneticiListesiNode *itr = LIST->FindPrevByPosition(end - 8)->next; itr != NULL && count < 8; itr = itr->next, count++)
	{
		cout << "|";
		cout << setw(14) << itr->prev;
		cout << "|  ";
	}

	cout << endl;
	LIST->printLine(count);

	count = 0;
	for (YoneticiListesiNode *itr = LIST->FindPrevByPosition(end - 8)->next; itr != NULL && count < 8; itr = itr->next, count++)
	{
		cout << "|";
		cout << setw(14) << itr->average;
		cout << "|  ";
	}

	cout << endl;
	LIST->printLine(count);

	count = 0;
	for (YoneticiListesiNode *itr = LIST->FindPrevByPosition(end - 8)->next; itr != NULL && count < 8; itr = itr->next, count++)
	{
		cout << "|";
		cout << setw(14) << itr->next;
		cout << "|  ";
	}

	cout << endl;
	LIST->printLine(count);

	cout << endl
		 << "List size: " << LIST->size << endl;
}