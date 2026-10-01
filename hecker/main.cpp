#include <iostream>
#include <Windows.h>
#include <iomanip>


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	srand(time(NULL));

	
	int number_fly = 0, AB= 0, BC = 0, potreblenie = 0, massa = 0, potreblenie_AB = 0, 
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
	std::cout << "Топлива надо дозаправки в B: " << dozapravka << "\n\n";

	

	return 0;
}

 
