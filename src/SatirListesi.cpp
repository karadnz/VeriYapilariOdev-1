/**
* @file SatirListesi.cpp
* @description cpp file for SatirListesi.hpp.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/
#include "SatirListesi.hpp"

SatirListesiNode *SatirListesi::FindPrevByPosition(int pos)
{
	if (pos < 0 || pos > size)
	{
		throw("No Such Element"); // bak
	}

	int index = 0;
	for (SatirListesiNode *itr = head; itr != NULL; itr = itr->next)
	{
		if (pos == index)
		{
			return (itr);
		}
		index++;
	}
	return NULL;
}

SatirListesi::SatirListesi()
{
	this->head = new SatirListesiNode(0);
	this->size = 0;
}

int SatirListesi::Size() const
{
	return (size);
}

bool SatirListesi::isEmpty() const
{
	return (size == 0);
}

void SatirListesi::add(const int &num)
{
	insert(size, num); // size
}

void SatirListesi::insert(int index, const int &num) // niye const ve reference
{
	if (index < 0 || index > size)
		throw "Index out of Range";

	if (index == 0)
	{
		this->head->next = new SatirListesiNode(num, head->next);

		if (this->head->next->next != NULL)
		{
			this->head->next->next->prev = head;
		}
		
	}

	else
	{
		SatirListesiNode *prev = FindPrevByPosition(index);

		prev->next = new SatirListesiNode(num, prev->next, prev);

		if (prev->next->next != NULL)
		{
			prev->next->next->prev = prev->next;
		}
		
	}

	size++;
}

const int& SatirListesi::first() 
{
	if (isEmpty())
	{
		throw("No Such Element");
	}
	return (this->head->data);
}

const int& SatirListesi::last() 
{
	if (isEmpty())
	{
		throw ("No Such Element");
	}
	return (FindPrevByPosition(size)->data);
}

void SatirListesi::remove(const int &num)
{
	int pos = indexOf(num);
	removeAt(pos);
}

void SatirListesi::removeAt(int index)
{
	if (index < 0 || index > size)
	{
		throw "Index out of range";
	}

	SatirListesiNode *del;

	if (index == 0)
	{
		del = head;
		head = head->next; 

		if (head != NULL)
		{
			head->prev = NULL;
		}
		
	}
	else
	{
		SatirListesiNode *prv = FindPrevByPosition(index);
		del = prv->next;
		prv->next = del->next;
		if (del->next != NULL)
		{
			del->next->prev = prv;
		}
	}

	size--;
	delete del;

} // |2|x| , |5|x| , |7|x| , |9|x|  removeAt(2) -> |2|x| , |5|x| , |9|x|  ;

bool SatirListesi::find(const int &item) const
{
	for (SatirListesiNode *itr = head->next; itr != NULL; itr = itr->next)
	{
		if (itr->data == item)
		{
			return (true);
		}
	}
	return (false);
}

void SatirListesi::reverse() 
{
	for (SatirListesiNode *itr = head; itr != NULL;)
	{
		SatirListesiNode *temp = itr->next;
		itr->next = itr->prev;
		itr->prev = temp;
		if (temp == NULL)
		{
			head = itr;
			break;
		}
		itr = temp;
	}
}

int SatirListesi::indexOf(const int &item)
{
	int index = 0;

	for (SatirListesiNode *itr = head->next; itr != NULL; itr = itr->next)
	{
		if (itr->data == item)
		{
			return (index);
		}

		index++;
	}

	throw ("No Such Element");
}

const int& SatirListesi::SatirListesi::elementAt(int index)
{
	if (index < 0 || index >= size)
		throw ("No Such Element");

	if (index == 0)
		return head->next->data;
	return FindPrevByPosition(index)->next->data;
}



void SatirListesi::clear()
{
	while (!isEmpty())
	{
		removeAt(0);
	}
}

SatirListesi::~SatirListesi()
{
	clear();
	delete head;
}


SatirListesiNode* SatirListesi::getHead()
{
	return this->head;
}


ostream &operator<<(ostream &OUT, SatirListesi &LIST)
{
	if (!(LIST.isEmpty()))
	{
		int index = 0;

		
		OUT<< endl;
		cout << "^^^^^^^^^^^^^^^^  ";
		OUT<< endl;
		


		for (SatirListesiNode *itr = LIST.head->next; itr != NULL; itr = itr->next)
		{
			LIST.printLine(1);

			OUT << "|";
			OUT << setw(14) << itr->data;
			OUT << "|  ";

			OUT << endl;

			
			LIST.printLine(1);

			OUT << "|";
			OUT << setw(14) << itr->next;
			OUT << "|  ";

			OUT << endl;
			LIST.printLine(1);

			OUT << endl;
		}

		OUT << endl;



		cout << "List size: " << LIST.size << endl;
		return OUT;
	}

	OUT << "Empty list" << endl;
	return OUT;
}


void SatirListesi::printLine(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "----------------  ";
	}
	cout << endl;
}