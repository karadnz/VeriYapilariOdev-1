#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "utils.cpp"

#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	string line;
	ifstream dataFile("./veri.txt");
	

	YoneticiListesi *yntLst = new YoneticiListesi;

	while (getline(dataFile, line))
	{
		cout << line << endl;

		
		SatirListesi *strLst = new SatirListesi;

		char dl = ' ';
		line += dl;
		string word;

		for (int i = 0; i < line.length(); i++)
		{

			if (line[i] != dl)
			{
				word += line[i];
			}

			

			else
			{
				cout<<word<<"$"<<endl;
				strLst->add(stoi(word));
				word ="";
			}

		}
		yntLst->add(strLst);
	}

	dataFile.close();


	bool flag = true;
	int end = 8;
	while (flag)
	{
		system("clear");

		printYoneticiNodes(yntLst, end);

		char islem;
		cout << "islem: ";
		cin >> islem;
		cout << endl;

		switch (islem)
		{
		
		case 'd':
		{
			if (end < yntLst->Size())
			{
				end += 8;
			}
			break;
		}

		case 'a':
		{
			if (end != 8)
			{
				end -= 8;
			}
			break;
		}

		case 'q':
			flag = false;
			break;

		case 'r':
		{
			int index;
			cout << "index to remove";
			cin >> index;
			yntLst->removeAt(index);
			break;
		}

		case 'z':
		{
			int index;
			string s;
			cout << "index to display";
			cin >> index;

			cout << *yntLst;
			
			

			yntLst->tempDisplay(index);
			cout << "devam";
			cin >> s;
			break;
		}

		default:
			break;
		}
	}
	return (0);
}