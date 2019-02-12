#include <iostream>

using namespace std;

const int amount = 5;
int choice,number,counter = 0,choicer = 0;
enum district { central, pervomaiskiy, lenenskiy, oktaborskiy };
district region;
int rg = region;

int main()
{
	setlocale(LC_ALL, "Rus");

	struct room
	{
		int square;
		int neighbors;
		char free;
	};

	struct flat
	{
		char region[20];
		int rooms;
		int square;
		int floor;
	};

	struct house
	{
		char region[20];
		int building_square;
		int living_square;
		int percent_of_ready;

	};

	struct accommodation
	{
		house houses;
		flat flats;
		room rooms;
	};

	accommodation acc[amount];

	while(true)
	{
		cout << "�������� ����� ����:\n" << "1 - �������� ������ � ������.\n" << "2 - �������� ������ �� �������.\n" << "3 - ����� ������ �������.\n" <<"4 - �����." << endl;
		cin >> choice;
		if(choice == 1)
		{
			if(counter < 5)
			{
				cout << "������� ���������� ������ � ��������:" << endl;
				cin >> acc[counter].flats.rooms;
				cout << "������� ������� ��������:" << endl;
				cin >> acc[counter].flats.square;
				cout << "�� ����� ����� ��������� ��������:" << endl;
				cin >> acc[counter].flats.floor;
				cout << "�������� �����:\n" << "0 - central, 1 - pervomaiskiy, 2 - lenenskiy, 3 - oktaborskiy" << endl;
				cin >> rg;
				switch (rg)
				{
				case(central):
					cout << "������ ����������� �����." << endl;
					strcpy_s(acc[counter].flats.region,"central");
					break;
				case(pervomaiskiy):
					cout << "������ ������������ �����." << endl;
					strcpy_s(acc[counter].flats.region,"pervomaiskiy");
					break;
				case(lenenskiy):
					cout << "������ ��������� �����." << endl;
					strcpy_s(acc[counter].flats.region,"lenenskiy");
					break;
				case(oktaborskiy):
					cout << "������ ����������� �����." << endl;
					strcpy_s(acc[counter].flats.region,"oktaborskiy");
					break;
				default:
					cout << "�� �������� ������� - ��� ���� ����� � �������." << endl;
					strcpy_s(acc[counter].flats.region, "country");
				
				}
				cout << "������� ������� �������:" << endl;
				cin >> acc[counter].rooms.square;
				cout << "������� ������� � ���:" << endl;
				cin >> acc[counter].rooms.neighbors;
				cout << "������� �������� (y - yes/n - no):" << endl;
				cin >> acc[counter].rooms.free;
				cout << "������ ������� ����:" << endl;
				cin >> acc[counter].houses.building_square;
				cout << "������ ����� ������� ����:" << endl;
				cin >> acc[counter].houses.living_square;
				cout << "�� ������� % ����� ���:" << endl;
				cin >> acc[counter].houses.percent_of_ready;
				cout << "�������� �����:\n" << "0 - central, 1 - pervomaiskiy, 2 - lenenskiy, 3 - oktaborskiy" << endl;
				cin >> rg;
				switch (rg)
				{
				case(central):
					cout << "������ ����������� �����." << endl;
					strcpy_s(acc[counter].houses.region, "central");
					break;
				case(pervomaiskiy):
					cout << "������ ������������ �����." << endl;
					strcpy_s(acc[counter].houses.region, "pervomaiskiy");
					break;
				case(lenenskiy):
					cout << "������ ��������� �����." << endl;
					strcpy_s(acc[counter].houses.region, "lenenskiy");
					break;
				case(oktaborskiy):
					cout << "������ ����������� �����." << endl;
					strcpy_s(acc[counter].houses.region, "oktaborskiy");
					break;
				default:
					cout << "�� �������� ������� - ��� ������ ����� � �������." << endl;
					strcpy_s(acc[counter].houses.region, "country");
					break;
				}
				counter++;
			}
			else
			{
				cout << "������ ����������. ������� 1 �������." << endl;
			}
			

		}
		else if(choice == 2)
		{
			
			cout << "����� ������ �� ������� �������� ����� �������?(0/1/2/3/4) " << endl;
			cin >> number;


			for(int j=number; j < amount ;j++)
			{

				acc[j] = acc[j + 1];
	
			}

			counter--;
		
		}
		else if(choice == 3)
		{
			
			for(int i=0; i < counter; i++)
			{
				cout << "\n" << i+1 << ")" << endl;
				cout << acc[i].rooms.square << " - ������� �������, " << acc[i].rooms.neighbors << " - ���������� �������, " << acc[i].rooms.free << " - �������� ��(n - ���/y - ��)." << endl;
				cout << acc[i].flats.square << " - ������� ��������, " << acc[i].flats.rooms << " - ���������� ������, " << acc[i].flats.floor << " - ����, " << acc[i].flats.region << " - �����." << endl;
				cout << acc[i].houses.building_square << " - ������� ������, " << acc[i].houses.living_square << " - ����� �������, " << acc[i].houses.percent_of_ready << " - ������� ����������, " << acc[i].houses.region << " - �����.\n" <<  endl;
			}

		}
		else if (choice == 4)
		{

			cout << "�����." << endl;
			break;
			
		}
		else
		{
			cout << "������ ����� �����������." << endl;
		}
	}

	system("Pause");
	return 0;

}
