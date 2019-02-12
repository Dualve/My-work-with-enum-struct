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
		cout << "Выберите пункт меню:\n" << "1 - добавить запись в массив.\n" << "2 - удаление записи из массива.\n" << "3 - вывод данных массива.\n" <<"4 - выход." << endl;
		cin >> choice;
		if(choice == 1)
		{
			if(counter < 5)
			{
				cout << "Введите количество комнат в квартире:" << endl;
				cin >> acc[counter].flats.rooms;
				cout << "Введите площадь квартиры:" << endl;
				cin >> acc[counter].flats.square;
				cout << "На каком этаже находится квартира:" << endl;
				cin >> acc[counter].flats.floor;
				cout << "Выберите район:\n" << "0 - central, 1 - pervomaiskiy, 2 - lenenskiy, 3 - oktaborskiy" << endl;
				cin >> rg;
				switch (rg)
				{
				case(central):
					cout << "Выбран Центральный район." << endl;
					strcpy_s(acc[counter].flats.region,"central");
					break;
				case(pervomaiskiy):
					cout << "Выбран Первомайский район." << endl;
					strcpy_s(acc[counter].flats.region,"pervomaiskiy");
					break;
				case(lenenskiy):
					cout << "Выбран Лененский район." << endl;
					strcpy_s(acc[counter].flats.region,"lenenskiy");
					break;
				case(oktaborskiy):
					cout << "Выбран Октябрьский район." << endl;
					strcpy_s(acc[counter].flats.region,"oktaborskiy");
					break;
				default:
					cout << "Вы ошиблись районом - вам дали жильё в Деревне." << endl;
					strcpy_s(acc[counter].flats.region, "country");
				
				}
				cout << "Введите площадь комнаты:" << endl;
				cin >> acc[counter].rooms.square;
				cout << "Сколько соседей у вас:" << endl;
				cin >> acc[counter].rooms.neighbors;
				cout << "Комната свободна (y - yes/n - no):" << endl;
				cin >> acc[counter].rooms.free;
				cout << "Какова площадь дома:" << endl;
				cin >> acc[counter].houses.building_square;
				cout << "Какова жилая площадь дома:" << endl;
				cin >> acc[counter].houses.living_square;
				cout << "На сколько % готов дом:" << endl;
				cin >> acc[counter].houses.percent_of_ready;
				cout << "Выберите район:\n" << "0 - central, 1 - pervomaiskiy, 2 - lenenskiy, 3 - oktaborskiy" << endl;
				cin >> rg;
				switch (rg)
				{
				case(central):
					cout << "Выбран Центральный район." << endl;
					strcpy_s(acc[counter].houses.region, "central");
					break;
				case(pervomaiskiy):
					cout << "Выбран Первомайский район." << endl;
					strcpy_s(acc[counter].houses.region, "pervomaiskiy");
					break;
				case(lenenskiy):
					cout << "Выбран Лененский район." << endl;
					strcpy_s(acc[counter].houses.region, "lenenskiy");
					break;
				case(oktaborskiy):
					cout << "Выбран Октябрьский район." << endl;
					strcpy_s(acc[counter].houses.region, "oktaborskiy");
					break;
				default:
					cout << "Вы ошиблись районом - вам выдали жильё в Деревне." << endl;
					strcpy_s(acc[counter].houses.region, "country");
					break;
				}
				counter++;
			}
			else
			{
				cout << "Массив переполнен. Удалите 1 элемент." << endl;
			}
			

		}
		else if(choice == 2)
		{
			
			cout << "Какую запись из массива структур будем удалять?(0/1/2/3/4) " << endl;
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
				cout << acc[i].rooms.square << " - площадь комнаты, " << acc[i].rooms.neighbors << " - количество соседей, " << acc[i].rooms.free << " - свободна ли(n - нет/y - да)." << endl;
				cout << acc[i].flats.square << " - площадь квартиры, " << acc[i].flats.rooms << " - количество комнат, " << acc[i].flats.floor << " - этаж, " << acc[i].flats.region << " - район." << endl;
				cout << acc[i].houses.building_square << " - площадь здания, " << acc[i].houses.living_square << " - жилая площадь, " << acc[i].houses.percent_of_ready << " - процент готовности, " << acc[i].houses.region << " - район.\n" <<  endl;
			}

		}
		else if (choice == 4)
		{

			cout << "Удачи." << endl;
			break;
			
		}
		else
		{
			cout << "Данный пункт отсутствует." << endl;
		}
	}

	system("Pause");
	return 0;

}
