/**
* @file utils.cpp
* @description cpp file for utils.hpp.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/
#include "utils.hpp"


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
		cout << setw(14) << itr;
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
		cout << "|";
		cout << " ";
		cout << " ";
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


void printSelectedSatirListesi(YoneticiListesi *LIST, int selected, int end, bool delFlag, int delIndex)
{
	printSelectedLine(selected);
	cout << endl;

	int index = (end - (7 - selected)) - 1;

	int counter = 0;
	

	if (!(LIST->isEmpty()))
	{
		

		//head e ulasmanin baska yolunu bul
		for (SatirListesiNode *itr = LIST->FindPrevByPosition(index)->next->data->getHead()->next; itr != NULL; itr = itr->next) 
		{
			
			printSpace(selected);
			
			cout << " ";
			cout << setw(14) << itr;
			cout << " ";
			cout << " ";
			cout << " ";
			cout << endl;

			printSpace(selected);
			LIST->printLine(1);
			printSpace(selected);

			
			cout << "|";
			cout << setw(14) << itr->data;
			cout << "|  ";
			if (delFlag && counter++ == delIndex) cout << "   <-- silinecek secili";

			cout << endl;
			printSpace(selected);

			
			LIST->printLine(1);
			printSpace(selected);

			
			cout << "|";
			cout << setw(14) << itr->next;
			cout << "|  ";

			cout << endl;
			printSpace(selected);

			
			LIST->printLine(1);

			cout << endl;

		}

		cout << endl;
		printSpace(selected);
		cout << LIST->FindPrevByPosition(index)->next->data->Size();
		cout<<endl;

	}
	
}

void printSelectedLine(int selected)
{
	printSpace(selected);

	cout << "^^^^^^^^^^^^^^^^  ";
	cout << endl;

}

void printSpace(int selected)
{
	for (int i = 0; i < selected; i++)
	{
		cout << "                  ";
	}

}


void	yoneticiInit(YoneticiListesi *yntLst)
{
	string line;
	ifstream dataFile("./veriler.txt");


	while (getline(dataFile, line))
	{
		cout << line << endl;

		
		SatirListesi *strLst = new SatirListesi;

		char dl = ' ';
		line += dl;
		string word;

		for (int i = 0; i < line.length(); i++)
		{

			if (isdigit(line[i]))
			{
				word += line[i];
			}

			

			else if (!word.empty())
			{
				cout <<endl << "index: " << i <<"isdigit: " << isdigit(line[i]) << endl;
				cout<<word<<"$"<<endl;
				strLst->add(stoi(word));
				word.clear();
			}
			

		}
		if (!strLst->isEmpty())
		{
			yntLst->add(strLst);

		}
		
	}

	dataFile.close();
}

