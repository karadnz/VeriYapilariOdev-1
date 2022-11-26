/**
* @file YoneticiListesi.cpp
* @description cpp file for YoneticiListesi.cpp.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"

YoneticiListesiNode *YoneticiListesi::FindPrevByPosition(int pos)
{
	if (pos < 0 || pos > size)
		throw("No Such Element");

	int index = 0;
	for (YoneticiListesiNode *itr = head; itr != NULL; itr = itr->next)
	{
		if (pos == index)
		{
			return (itr);
		}
		index++;
	}
	return NULL;
}

YoneticiListesi::YoneticiListesi()
{

	this->head = new YoneticiListesiNode(new SatirListesi); 
	this->size = 0;
}

int YoneticiListesi::Size() const
{
	return (size);
}

bool YoneticiListesi::isEmpty() const
{
	return (size == 0);
};

void YoneticiListesi::add(SatirListesi *&item)
{
	insert(size, item); 
}

void YoneticiListesi::insert(int index, SatirListesi *&item)
{
	if (index < 0 || index > size)
		throw "Index out of Range";

	if (index == 0)
	{
		this->head->next = new YoneticiListesiNode(item, head->next);

		if (this->head->next->next != NULL)
		{
			this->head->next->next->prev = head;
		}
	}

	else
	{
		YoneticiListesiNode *prev = FindPrevByPosition(index);

		prev->next = new YoneticiListesiNode(item, prev->next, prev);

		if (prev->next->next != NULL)
		{
			prev->next->next->prev = prev->next;
		}
	}

	size++;
}

SatirListesi *&YoneticiListesi::first()
{
	if (isEmpty())
	{
		throw("No Such Element");
	}
	return (this->head->data);
}

SatirListesi *&YoneticiListesi::last()
{
	if (isEmpty())
	{
		throw("No Such Element");
	}
	return (FindPrevByPosition(size)->data);
}

void YoneticiListesi::remove(SatirListesi *&item)
{
	int pos = indexOf(item); 
	removeAt(pos);
}

void YoneticiListesi::removeAt(int index)
{
	if (index < 0 || index > size)
	{
		throw "Index out of range";
	}

	YoneticiListesiNode *del;

	if (index == 0)
	{
		del = head->next;
		head->next = head->next->next; 

		if (head->next != NULL)
		{
			head->next->prev = NULL;
		}
		
	}
	else
	{
		YoneticiListesiNode *prv = FindPrevByPosition(index);
		del = prv->next;
		prv->next = del->next;
		if (del->next != NULL)
		{
			del->next->prev = prv;
		}
	}

	size--;
	delete del->data;
	delete del;

} // |2|x| , |5|x| , |7|x| , |9|x|  removeAt(2) -> |2|x| , |5|x| , |9|x|  ;

bool YoneticiListesi::find(SatirListesi *&item) const
{
	for (YoneticiListesiNode *itr = head->next; itr != NULL; itr = itr->next)
	{
		if (itr->data == item)
		{
			return (true);
		}
	}
	return (false);
}

void YoneticiListesi::reverse()
{
	for (YoneticiListesiNode *itr = head; itr != NULL;)
	{
		YoneticiListesiNode *temp = itr->next;
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

int YoneticiListesi::indexOf(SatirListesi *&item)
{
	int index = 0;

	for (YoneticiListesiNode *itr = head->next; itr != NULL; itr = itr->next)
	{
		if (itr->data == item)
		{
			return (index);
		}

		index++;
	}

	throw("No Such Element");
}

SatirListesi *&YoneticiListesi::elementAt(int index)
{
	if (index < 0 || index >= size)
		throw("No Such Element");

	if (index == 0)
		return head->next->data;
	return FindPrevByPosition(index)->next->data;
}

ostream &operator<<(ostream &OUT, YoneticiListesi &LIST)
{
	if (!(LIST.isEmpty()))
	{
		int index = 0;

		OUT << endl;
		OUT << endl;

		for (YoneticiListesiNode *itr = LIST.head->next; itr != NULL; itr = itr->next)
		{
			OUT << " ";
			OUT << itr;
			OUT << " ";
			OUT << " ";
			OUT << " ";
		}

		OUT << endl;
		LIST.printLine(LIST.Size());

		for (YoneticiListesiNode *itr = LIST.head->next; itr != NULL; itr = itr->next)
		{
			OUT << "|";
			OUT << setw(14) << itr->prev;
			OUT << "|  ";
		}

		OUT << endl;
		LIST.printLine(LIST.Size());

		for (YoneticiListesiNode *itr = LIST.head->next; itr != NULL; itr = itr->next)
		{
			OUT << "|";
			OUT << setw(14) << itr->average;
			OUT << "|  ";
		}

		OUT << endl;
		LIST.printLine(LIST.Size());

		for (YoneticiListesiNode *itr = LIST.head->next; itr != NULL; itr = itr->next)
		{
			OUT << "|";
			OUT << setw(14) << itr->next;
			OUT << "|  ";
		}

		OUT << endl;
		LIST.printLine(LIST.Size());

		cout << endl
			 << "List size: " << LIST.size << endl;

		return OUT;
	}

	OUT << "Empty list" << endl;
	return OUT;
}

void YoneticiListesi::printLine(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "----------------  ";
	}
	cout << endl;
}

void YoneticiListesi::tempDisplay(int index)
{
	cout << *(elementAt(index));
}

void YoneticiListesi::clear()
{
	while (!isEmpty())
	{
		removeAt(0);
	}
}



void YoneticiListesi::sort()
{
	if (isEmpty())
		throw("empty list");

	for (int i = 0; i < size; i++)
	{
		YoneticiListesiNode *itr = this->head->next;

		for (int j = 0; j < size - 1 - i; j++) 
		{
			
			YoneticiListesiNode *node1 = itr;
			YoneticiListesiNode *node2 = itr->next;
			

			if (node1->average > node2->average)
			{

				YoneticiListesiNode *node1Prev = node1->prev;


				node1->next = node2->next;
				node1->prev = node2;
				

				node2->next = node1;
				node2->prev = node1Prev;

				

				if (node1->next != NULL)
				{
					node1->next->prev = node1;
				}
				

				if (node2->prev != NULL)
				{
					node2->prev->next = node2;
					
				}
				
				else
				{
					this->head->next = node2;
				}
			}
			else
			{
			
				itr = itr->next;
			}
			
			
		}
	}
}

void YoneticiListesi::sortNode(int index)
{
	if (isEmpty())
		throw("empty list");

	YoneticiListesiNode *toSort = FindPrevByPosition(index)->next;
	YoneticiListesiNode *itr = this->head->next;

	for(int i = 0; i < size - 1; i++)
	{
		if (itr->average > toSort->average)
		{
			//toSort u kopar
			//itr nin bi arkasina koy

			
			if (toSort->prev != NULL) 
			{
				toSort->prev->next = toSort->next;
			}
			else
			{
				this->head->next = toSort->next;
			}


			if (toSort->next != NULL)
			{
				toSort->next->prev = toSort->prev;
			}

			//-------------------------------------------

			if(itr->prev != NULL)
			{
				itr->prev->next =toSort; 

			}
			else
			{
				this->head->next = toSort;
			}

			toSort->prev = itr->prev;
			itr->prev = toSort; 
			toSort->next = itr;

			
			break;
		}
		itr = itr->next;
	}
			
		
	
}


YoneticiListesi::~YoneticiListesi()
{
	clear();
	delete head;
}