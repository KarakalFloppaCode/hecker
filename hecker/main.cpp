#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>


/*
void Myswap(int &num1, int &num2)
{
	int ptr = num2;
	num2 = num1;
	num1 = ptr;
}


void FillArr(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 10;
	}
}

void vivodarr(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << *(arr + i) << " ";
	}
}

*/



void pervietri(std::string predloj)
{
	while (true)
	{
		size_t sizep = predloj.size();
		if (sizep == 0)
		{
			std::cout << "Нельзя вписывать пустые строки";
		}
		else
		{
			predloj[0] = std::toupper(predloj[0]);
			for (int i = 1; i < sizep; i++)
			{
				if (predloj[i - 1] == ' ')
				{
					predloj[i] = std::toupper(predloj[i]);
				}
				else
				{
					predloj[i] = std::tolower(predloj[i]);
				}

			}
			if (predloj[sizep - 1] != '.')
			{
				predloj += '.';
			}
			std::cout << predloj;
		}
		std::cout << "\n\n";
		system("pause");
		break;
	}
}

bool chetirepat(std::string predloj, std::string iskat)
{
	int sizep = predloj.size();
	int sizei = iskat.size();
	for (int i = 0; i < sizep; i++)
	{
		predloj[i] = std::toupper(predloj[i]);
	}
	for (int i = 0; i < sizei; i++)
	{
		iskat[i] = std::toupper(iskat[i]);
	}
	auto a = predloj.find(iskat);
	if (a != std::string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8); // 1251 CP_UTF8 65001
	srand(time(NULL));



	std::string predloj;
	std::string iskat;
	int choose = 0;


	system("cls");
	while (true)
	{
		system("cls");
		std::cout << "\n\n\t\tДЗ\n\n";
		std::cout << "1. Первые три задания\n\n";
		std::cout << "2. Четыре и пять\n\n";
		std::cout << "0. Выход\n\n";
		std::cout << "Ввод: ";
		std::cin >> choose;
		if (choose == 1)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			std::cout << "\n\n\t\tДЗ\n\n";
			std::cout << "Введите предложение(только американские буквы): ";
			std::getline(std::cin, predloj);  //(откуда_взять_инфу, куда_положить)

			pervietri(predloj);
		}
		else if (choose == 2)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			std::cout << "\n\n\t\tДЗ\n\n";
			std::cout << "Введите предложение(только американские буквы):\n";
			std::getline(std::cin, predloj);
			std::cout << "\nКакое слово хотите найти?\n";
			std::getline(std::cin, iskat);
			if (chetirepat(predloj, iskat) == true)
			{
				std::cout << "Слово найдено\n\n";
				system("pause");
			}
			else
			{
				std::cout << "Слово не найдено\n\n";
				system("pause");
			}
		}
		else if (choose == 0)
		{
			system("cls");
			std::cout << "\n\n\t\tДосвидания!\n\n";
			break;
		}
		else
		{
			std::cout << "Неккоретный ввод!\n\n";
			Sleep(1500);
		}
	}


	return 0;
}

/*
int ColvoVesYear(int year)
{
	if (year <= 0)
	{
		return 0;
	}
	return (year / 4) - (year / 100) + (year/400);
}

double SredneArifmetic(double arr[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	sum = sum / size;

	return sum;
}

void KolvoZnakov(int arr[], int size)
{
	int nuli = 0;
	int poloj = 0;
	int otric = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0)
		{
			nuli += 1;
		}
		else if (arr[i] > 0)
		{
			poloj += 1;
		}
		else
		{
			otric += 1;
		}
	}
	std::cout << "Всего 0: " << nuli << "\n\n";
	std::cout << "Всего положительных: " << poloj << "\n\n";
	std::cout << "Всего отрицательных: " << otric << "\n\n";

}

int RaznostData(int day1, int month1, int year1, int day2, int month2, int year2)
{
	int raznost_data_day = ((year2 - year1) * 365) + ((month2 - month1) * 30) + (day2 - day1);
	return raznost_data_day + (ColvoVesYear(year2 - 1) - ColvoVesYear(year1));
}
*/



/*
const int size = 10;
	double arr[size];
	int arrznak[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10 + 1;
		arrznak[i] = rand() % 21 - 10;
	}
	int day1 = 0, day2 =0, month1=0, month2= 0, year1=0, year2=0;

	int choose = 0;
	while (true)
	{
		system("cls");
		std::cout << "\n\n\t\t\tДомашка\n\n";
		std::cout << "1. Задание 1 (Даты)\n\n";
		std::cout << "2. Задание 2 (Нахождение среднего арифметического)\n\n";
		std::cout << "3. Задание 3 (Нахождение количества чисел с разными знаками)\n\n";
		std::cout << "0. Выход\n\n";
		std::cout << "Ввод: ";
		std::cin >> choose;
		if (choose == 1)
		{
			while (true)
			{
				system("cls");
				std::cout << "\n\n\t\t\tЗадание 1\n\n";
				std::cout << "Введите день первой даты: ";
				std::cin >> day1;
				if (day1 < 1 || day1>32)
				{
					std::cout << "Нельзя";
					Sleep(1500);
					continue;
				}
				std::cout << "Введите месяц первой даты: ";
				std::cin >> month1;
				if (month1 < 1 || month1>12)
				{
					std::cout << "Нельзя";
					Sleep(1500);
					continue;
				}
				std::cout << "Введите год первой даты: ";
				std::cin >> year1;
				if (year1 < 0)
				{
					std::cout << "Нельзя";
					Sleep(1500);
					continue;
				}
				system("cls");
				std::cout << "\n\n\t\t\tЗадание 1\n\n";
				std::cout << "Введите день второй даты: ";
				std::cin >> day2;
				if (day2 < 1 || day2>32)
				{
					std::cout << "Нельзя";
					Sleep(1500);
					continue;
				}
				std::cout << "Введите месяц второй даты: ";
				std::cin >> month2;
				if (month2 < 1 || month2 >12)
				{
					std::cout << "Нельзя";
					Sleep(1500);
					continue;
				}
				std::cout << "Введите год второй даты: ";
				std::cin >> year2;
				if (year2 < 0)
				{
					std::cout << "Нельзя";
					Sleep(1500);
					continue;
				}

				system("cls");
				std::cout << "\n\n\t\t\tЗадание 1\n\n";
				std::cout << "Первая дата: " << day1 << "." << month1 << "." << year1 << "\n\n";
				std::cout << "Вторая дата: " << day2 << "." << month2 << "." << year2 << "\n\n";
				std::cout << "Разница между датами в днях: " << RaznostData(day1, month1, year1, day2, month2, year2) << "\n\n";


				system("pause");
				break;
			}

		}
		else if (choose == 2)
		{
			system("cls");
			std::cout << "\n\n\t\t\tЗадание 2\n\n";
			std::cout << "Массив: ";
			for (int i = 0; i < size; i++)
			{
				std::cout << arr[i] << " ";
			}

			std::cout << "\n\nСредне арифмитическое: " << SredneArifmetic(arr, size) << "\n\n";
			system("pause");
		}
		else if (choose == 3)
		{
			system("cls");
			std::cout << "\n\n\t\t\tЗадание 3\n\n";
			std::cout << "Массив: ";
			for (int i = 0; i < size; i++)
			{
				std::cout << arrznak[i] << " ";
			}
			std::cout << "\n\n";
			KolvoZnakov(arrznak, size);
			system("pause");
		}
		else if (choose == 0)
		{
			system("cls");
			std::cout << "\n\n\t\t\tДосвидания!\n\n\n";
			break;
		}
		else
		{
			std::cout << "Неверный ввод!";
			Sleep(1500);
		}
	}

*/



/*int number_fly = 0, AB = 0, BC = 0, potreblenie = 0, massa = 0, potreblenie_AB = 0,
		potreblenie_BC = 0, full_bak = 0, dozapravka = 0;

	int arr[2][7] = { {750, 1, 1500, 4, 2000, 7, 2000}, {1000, 2, 2000, 4, 3000, 6, 3000 } };
	int bak[2][2] = { {300, 0}, {1000, 100} };


	while (true)
	{
		system("cls");
		std::cout << "Введите номер самолёта( 1 или 2 ): ";
		std::cin >> number_fly;
		number_fly -= 1;
		if (number_fly != 0 && number_fly != 1)
		{
			std::cout << "Нету такого номера самолёта";
			Sleep(1500);
			continue;
		}
		std::cout << "Введите расстояние от А до В: ";
		std::cin >> AB;
		if (AB < 0)
		{
			std::cout << "Расстояние не может быть отрицательным";
			Sleep(1500);
			continue;
		}
		std::cout << "Введите расстояние от В до С: ";
		std::cin >> BC;
		if (BC < 0)
		{
			std::cout << "Расстояние не может быть отрицательным";
			Sleep(1500);
			continue;
		}
		std::cout << "Введите вес груза: ";
		std::cin >> massa;
		if (massa < 0)
		{
			std::cout << "Вес не может быть отрицательным";
			Sleep(1500);
			continue;
		}
		break;
	}



	if (massa <= arr[number_fly][0])
	{
		potreblenie = arr[number_fly][1];
	}
	else if (massa <= arr[number_fly][2])
	{
		potreblenie = arr[number_fly][3];
	}
	else if (massa <= arr[number_fly][4])
	{
		potreblenie = arr[number_fly][5];
	}
	else if (massa > arr[number_fly][6])
	{
		std::cout << "Полёт невозможен, самолёт не вывозит такой груз\n";
		return 0;
	}
	potreblenie_AB = AB * potreblenie;
	potreblenie_BC = BC * potreblenie;

	full_bak = bak[number_fly][0] + bak[number_fly][1];

	if (full_bak < potreblenie_AB)
	{
		std::cout << "Полёт невозможен, самолёт не долетит до точки B";
		return 0;
	}
	if (bak[number_fly][0] < potreblenie_BC)
	{
		std::cout << "Полёт невозможен, самолёт не долетит до точки C";
		return 0;
	}

	full_bak = full_bak - potreblenie_AB;
	if (full_bak > bak[number_fly][0])
	{
		full_bak = bak[number_fly][0];
	}
	if (full_bak < potreblenie_BC)
	{
		dozapravka = potreblenie_BC - full_bak;
	}

	std::cout << "\n\nТоплива надо AB: " << potreblenie_AB << "\n\n";
	std::cout << "Топлива надо BC: " << potreblenie_BC << "\n\n";
	std::cout << "Топлива надо дозаправки в B: " << dozapravka << "\n\n";*/