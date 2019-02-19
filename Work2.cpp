#include <iostream>

using namespace std;

const int amount = 5;
int choice, number, counter = 0;
enum district { central, pervomaiskiy, lenenskiy, oktaborskiy };
district region;
int rg = region;


int main()
{
	setlocale(LC_ALL, "Rus");
	system("color F0");

	struct room
	{
		int square;
		int neighbors;
		bool free;
		char type[7];
	};

	struct flat
	{
		char region[14];
		int rooms;
		int square;
		int floor;
		char type[7];
	};

	struct house
	{
		char region[14];
		int building_square;
		int living_square;
		int percent_of_ready;
		char type[7];
	};

	union accommodation
	{
		house houses;
		flat flats;
		room rooms;
	};

	accommodation acc[amount];

	while (true)
	{
		cout << "�������� ����� ����:\n" << "1 - �������� ������ � ������.\n" << "2 - �������� ������ �� �������.\n" << "3 - ����� ������ �������.\n" << "4 - �����." << endl;
		cin >> choice;
		if (choice == 1)
		{
			if (counter < 5)
			{
				cout << "�������� ����� ���� 1 - �������� , 2 - ������� , 3 - ���\n" << endl;
				cin >> choice;
				if (choice - 1 == 0)
				{
					strcpy_s(acc[counter].flats.type, "Flat");
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
						strcpy_s(acc[counter].flats.region, "central");
						break;
					case(pervomaiskiy):
						cout << "������ ������������ �����." << endl;
						strcpy_s(acc[counter].flats.region, "pervomaiskiy");
						break;
					case(lenenskiy):
						cout << "������ ��������� �����." << endl;
						strcpy_s(acc[counter].flats.region, "lenenskiy");
						break;
					case(oktaborskiy):
						cout << "������ ����������� �����." << endl;
						strcpy_s(acc[counter].flats.region, "oktaborskiy");
						break;
					default:
						cout << "�� �������� ������� - ��� ���� ����� � �������." << endl;
						strcpy_s(acc[counter].flats.region, "country");
					}
				}
				else if (choice - 1 == 1)
				{
					strcpy_s(acc[counter].rooms.type, "Room");
					cout << "������� ������� �������:" << endl;
					cin >> acc[counter].rooms.square;
					cout << "������� ������� � ���:" << endl;
					cin >> acc[counter].rooms.neighbors;
					cout << "������� �������� (1 - yes/other - no):" << endl;
					cin >> choice;
					if (choice == 1)
					{
						acc[counter].rooms.free = true;
					}
					else
					{
						acc[counter].rooms.free = false;
					}
				}
				else
				{
					strcpy_s(acc[counter].houses.type, "House");
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
				}
				counter++;
			}
			else
			{
				cout << "\n������ ����������. ������� 1 �������.\n" << endl;
			}


		}
		else if (choice == 2)
		{
			if (counter > 0)
			{
				cout << "����� ������ �� ������� �������� ����� �������? ( 1 -  " << counter << " )" << endl;
				cin >> number;

				for (int j = number - 1; j < amount; j++)
				{
					acc[j] = acc[j + 1];
				}

				counter--;
			}
			else
			{
				cout << "\n������ ����, �������� ��������.\n" << endl;
			}
		}
		else if (choice == 3)
		{
			for (int i = 0; i < counter; i++)
			{
				cout << "\n" << i + 1 << ") ";
				if (!strcmp(acc[i].rooms.type, "Room"))
				{
					cout << acc[i].rooms.square << " - ������� �������, " << acc[i].rooms.neighbors << " - ���������� �������. "; acc[i].rooms.free == true ? cout << " ������� ��������. " << endl : cout << "������� ������. " << endl;
				}
				else if (!strcmp(acc[i].flats.type, "Flat"))
				{
					cout << acc[i].flats.square << " - ������� ��������, " << acc[i].flats.rooms << " - ���������� ������, " << acc[i].flats.floor << " - ����, " << acc[i].flats.region << " - �����." << endl;
				}
				else if (!strcmp(acc[i].flats.type, "House"))
				{
					cout << acc[i].houses.building_square << " - ������� ������, " << acc[i].houses.living_square << " - ����� �������, " << acc[i].houses.percent_of_ready << " - ������� ����������, " << acc[i].houses.region << " - �����.\n" << endl;
				}
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
