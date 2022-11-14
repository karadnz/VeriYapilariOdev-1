#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"

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
	while (flag)
	{
		system("clear");
		cout << *yntLst;

		char islem;
		cout << "islem: ";
		cin >> islem;
		cout << endl;

		switch (islem)
		{

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

		case 'd':
		{
			int index;
			string s;
			cout << "index to display";
			cin >> index;

			cout << *yntLst;
			cout << endl;
			cout << endl;
			for (int i = 0; i < index; i++)
			{
				cout << setw(16) << " ";
			}

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