#include <iostream>
#include <Windows.h>
#include <iomanip>
double arr[1000000]{};

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	srand(time(NULL));

	int choose = 0;



	while (true)
	{
		system("cls");
		std::cout << "\n\n\t\tПрограммная демонстрация погрешностей вычислений\n\n";
		std::cout << "1 - Эксперимент А. «Накопление ошибки в цикле»\n\n";
		std::cout << "2 - Эксперимент Б. «Порядок сложения имеет значение»\n\n";
		std::cout << "0 - Выход\n\n";
		std::cout << "Ввод: ";
		std::cin >> choose;
		if (choose == 1)
		{
			system("cls");
			double chislo = 0, absol = 0, otnos = 0;
			double math = 100.0;

			std::cout << std::fixed << std::setprecision(17);

			for (int i = 0; i <= 1000; i++)
			{
				chislo += 0.1;
			}
			std::cout << "\n\n\t\tЭксперимент А\n\n";
			std::cout << "\n\t\tЧисло 0.1\n\n";
			std::cout << "Сложение числа 1000 раз:\t" << chislo << "\n\n";
			std::cout << "Математический результат:\t" << math << "\n\n";
			absol = chislo - math;
			std::cout << "Абсолютная погрешность:\t\t" << absol << "\n\n";
			otnos = absol / math;
			std::cout << "Относительная погрешность:\t" << otnos << "\n\n\n";

			chislo = 0;
			absol = 0;
			otnos = 0;
			math = 500.0;

			for (int i = 0; i < 1000; i++)
			{
				chislo += 0.5;
			}
			std::cout << "\t\tЧисло 0.5\n\n";
			std::cout << "Сложение числа 1000 раз:\t" << chislo << "\n\n";
			std::cout << "Математический результат:\t" << math << "\n\n";
			absol = math - chislo;
			std::cout << "Абсолютная погрешность:\t\t" << absol << "\n\n";
			otnos = absol / math;
			std::cout << "Относительная погрешность:\t" << otnos << "\n\n";

			/*
			Компьютеры хранят дробные числа в двоичной системе счисления,
			представляя их в виде суммы степеней двойки (1/2, 1/4, 1/8) и так далее).
			Число 0.5 записывается в двоичной системе идеально точно (как 2^-1),
			поэтому при его сложении погрешность равна нулю.
			Число 0.1 в двоичной системе превращается в бесконечную периодическую дробь (как 1/3), из-за чего компьютер вынужден его округлять.
			При 1000-кратном сложении эта микроскопическая ошибка округления накапливается и становится заметной
			*/
			system("pause");
		}
		else if (choose ==2)
		{
			system("cls");
			std::cout << std::fixed << std::setprecision(7);
			double sum1 = 0;
			double sum2 = 0;
			double chislo = 0;
			long double math = 10099999.9;
			double sum = 0;
			double chislo_mal = 0.1;
			arr[0] = 10000000;
			for (int i = 1; i < 1000000; i++)
			{
				arr[i] = chislo_mal;
			}
			sum1 = arr[0];
			for (int i = 1; i < 1000000; i++)
			{
				sum1 += arr[i];
			}
			std::cout << "\n\n\t\tЭксперимент Б\n\n";
			std::cout << "Способ 1(Сначало большое число, потом маленькие): " << sum1 << "\n";
			
			for (int i = 1; i < 1000000; i++)
			{
				sum2 += arr[i];
			}
			sum2 = arr[0] + sum2;
			std::cout << "Способ 2(Сначало все маленькие, потом большое): " << sum2 << "\n";
			sum = sum2 - sum1;
			std::cout << "Разница между ними: " << sum << "\n\n";
			chislo = math - sum1;
			std::cout << "Математическое число: " << math << "\n\n";
			std::cout << "Разница математического числа и способа 1: " << chislo << "\n\n";
			chislo = 0;
			chislo = sum2 - math;
			std::cout << "Разница математического числа и способа 2: " << chislo << "\n\n";
			std::cout << "Лучше использовать второй способ\n\n";

			/*
			Компьютер хранит числа аналогично научной нотации (например, 1.23 * 10^5). 
			Количество цифр в «главной части» (мантиссе) жестко ограничено. 
			Чтобы сложить два числа, компьютер должен привести их к одному порядку (одинаковой степени). 

			Если сначала сложить большое и маленькое:
			Компьютер берет большое число, пытается прибавить к нему крошечное, 
			но из-за нехватки разрядной сетки маленькое число просто «не помещается» в хвост большого и округляется до нуля. 
			Повторив это тысячу раз, вы тысячу раз прибавите ноль. Маленькие числа бесследно исчезнут.
			 
			Если сначала сложить много маленьких:
			Маленькие числа сопоставимы друг с другом по размеру. 
			Складываясь вместе, они постепенно образуют среднее, а затем и достаточно крупное число. 
			Когда эта накопившаяся сумма наконец прибавляется к большому числу, 
			она уже обладает достаточным весом, чтобы преодолеть порог округления и изменить старшие разряды. 
			*/

			system("pause");
		}
		else if (choose == 0)
		{
			system("cls");
			std::cout << "\n\n\t\tДосвидания!!!\n\n";
			break;
		}
		else
		{
			std::cout << "Неправильный ввод";
			Sleep(1500);
		}
	}
	

	return 0;
}


/*
while (true)
	{
		int choose = 0, start_arr = 0, end_arr = 0, summ_user = 0, summ_one_arr = 0, summ_two_arr = 0;
		system("cls");
		std::cout << "\n\n\t\tВыберите задание:\n\n";
		std::cout << "1 - первое задание\n\n";
		std::cout << "2 - второе задание\n\n";
		std::cout << "3 - третье задание\n\n";
		std::cout << "0 - выход\n\n";
		std::cout << "Ввод: ";
		std::cin >> choose;
		if (choose == 1)
		{
			system("cls");
			const int size = 10;
			int min_num = 9;
			int max_num = 0;

			int arr[size]{};
			for (int i = 0; i < size; i++)
			{
				arr[i] = rand() % 10 + 1;
			}
			std::cout << "Диапозон: ";
			for (int i = 0; i < size; i++)
			{
				std::cout << arr[i] << " ";
			}

			for (int i = 0; i < size; i++)
			{
				if (arr[i] > max_num)
				{
					max_num = arr[i];
				}
			}

			for (int i = 0; i < size; i++)
			{
				if (arr[i] < min_num)
				{
					min_num = arr[i];
				}
			}
			std::cout << "\n\nМинимальное значение: " << min_num;
			std::cout << "\n\nМаксимальное значение: " << max_num << "\n\n";
			system("pause");
		}
		else if (choose == 2)
		{

			const int size = 10;
			int number = 0;

			while (true)
			{
				system("cls");
				int arr[size]{};
				for (int i = 0; i < size; i++)
				{
					arr[i] = rand() % 10 + 1;
				}
				std::cout << "Введите начало диапозона от одного до десяти: ";
				std::cin >> start_arr;
				if (start_arr < 1 || start_arr > 10)
				{
					std::cout << "Вы ввели недопустимое значение";
					Sleep(1500);
					continue;
				}
				std::cout << "Введите конец диапозона от одного до десяти: ";
				std::cin >> end_arr;
				if (end_arr < 1 || end_arr > 10 || end_arr < start_arr)
				{
					std::cout << "Вы ввели недопустимое значение";
					Sleep(1500);
					continue;
				}

				std::cout << "Весь диапозон: ";
				for (int i = 0; i < size; i++)
				{
					std::cout << arr[i] << " ";
				}
				std::cout << "\n";
				std::cout << "\n";
				std::cout << "Диапозон пользователя: ";
				for (int i = start_arr - 1; i <= end_arr - 1; i++)
				{
					summ_user += arr[i];
					std::cout << arr[i] << " ";
				}
				std::cout << "\n";
				std::cout << "\n";
				if (start_arr != 1)
				{
					std::cout << "Диапозон до пользователя: ";
					for (int i = 0; i < start_arr - 1; i++)
					{
						summ_one_arr += arr[i];
						std::cout << arr[i] << " ";
					}
				}
				std::cout << "\n";
				std::cout << "\n";
				if (end_arr != 10)
				{
					std::cout << "Диапозон после: ";
					for (int i = end_arr; i < size; i++)
					{
						summ_two_arr += arr[i];
						std::cout << arr[i] << " ";
					}
				}
				std::cout << "\n";
				std::cout << "\n";


				std::cout << "\nСумма пользователя в диапозоне: " << summ_user << "\nСумма диапозона до пользователя: " << summ_one_arr << "\nСумма диапозона после пользователя: " << summ_two_arr;

				std::cout << "\n";


				if (summ_user < summ_one_arr)
				{
					std::cout << "\nСумма диапозона пользователя меньше первого диапозона";
				}
				else if (summ_user < summ_two_arr)
				{
					std::cout << "\nСумма диапозона пользователя меньше второго диапозона";
				}
				else
				{
					std::cout << "\nНи одна сумма диапозон не больше суммы диапозона пользователя";
				}
				std::cout << "\n";
				std::cout << "\n";


				system("pause");
				break;
			}


		}
		else if (choose == 3)
		{
			const int size = 12;
			int summ_max = 0, summ_min = 0, min_month = 0, max_month = 0;
			int arr[size]{};
			while (true)
			{
				system("cls");
				for (int i = 0; i < size; i++)
				{
					std::cout << "Введите прибыль за " << i + 1 << " Месяц: ";
					std::cin >> arr[i];
				}
				std::cout << "Введите начало диапозона от одного до двенадцати: ";
				std::cin >> start_arr;
				if (start_arr < 1 || start_arr > 12)
				{
					std::cout << "Вы ввели недопустимое значение";
					Sleep(1500);
					continue;
				}
				std::cout << "Введите конец диапозона от одного до двенадцати: ";
				std::cin >> end_arr;
				if (end_arr < 1 || end_arr > 12 || end_arr < start_arr)
				{
					std::cout << "Вы ввели недопустимое значение";
					Sleep(1500);
					continue;
				}
				std::cout << "Диапозон: ";
				for (int i = 0; i < size; i++)
				{
					std::cout << arr[i] << " ";
				}
				std::cout << "\n\n";
				std::cout << "Выбранный диапозон: ";
				for (int i = start_arr -1 ; i <= end_arr - 1; i++)
				{
					std::cout << arr[i] << " ";
				}
				summ_min = arr[start_arr - 1];
				for (int i = start_arr - 1; i <= end_arr - 1; i++)
				{
					if (summ_min >= arr[i])
					{
						summ_min = arr[i];
						min_month = i + 1;
					}
					if (summ_max <= arr[i])
					{
						summ_max = arr[i];
						max_month = i + 1;
					}
				}

				std::cout << "\n\nМинимальная прибыль " << summ_min<< " была в " << min_month << " месяце" << "\n\n";
				std::cout << "Максимальная прибыль " << summ_max << " была в " << max_month << " месяце" << "\n\n\n";

				system("pause");
				break;
			}


		}
		else if (choose == 0)
		{
			system("cls");
			std::cout << "\n\n\t\tДосвидания\n\n";
			break;
		}
		else
		{
			std::cout << "\nНеправильный ввод";
			Sleep(1500);
		}
	}
*/

/*
long long factorial(int chislo)						// Функция для нахождения факториала
{
	long long result = 1;
	for (int i = 1; i <= chislo; ++i) {
		result *= i;
	}
	return result;
}
*/

/*
int choose = 0, povtor = 0, n = 0, k = 0, A = 0, C = 0, P = 0, n1 = 0, P_znamenatel = 1, proverka_na_null = 1;		// переменные

	int chislo = 0;








	while (true)
	{
		system("cls");
		std::cout << "\n\n\t\tКалькулятор комбинаторики\n\n";					// Меню, выбираем тип задачи
		std::cout << "Выберите тип задачи\n\n";
		std::cout << "1 - А (размещение)\n\n";
		std::cout << "2 - С (Сочетания)\n\n";
		std::cout << "3 - Р (перестановка)\n\n";
		std::cout << "Ввод: ";
		std::cin >> choose;
		if (choose == 1 )
		{
			while (true)
			{
				system("cls");
				std::cout << "\n\n\n\nТип задачи A (размещение)\n\n";					// Меню, выбираем повторения
				std::cout << "1 - Без повторений\n\n";
				std::cout << "2 - С повторениями\n\n";
				std::cout << "0 - Обратно к типу задачи\n\n";
				std::cout << "Ввод: ";
				std::cin >> povtor;
				if (povtor == 1)
				{
					while (true)
					{
						system("cls");
						std::cout << "\n\n\n\nЗадача A (размещение без повторений)\n\n";
						std::cout << "Введите значения n: ";										// Вводим значения для n и k
						std::cin >> n;
						std::cout << "\nВведите значения k: ";
						std::cin >> k;
						if (n < 0 || k < 0 || k > n)							// Проверили что пользователь ввёл допустимые числа
						{
							std::cout << "\nБыть такого не может!";
							Sleep(1500);
							continue;
						}
						A = factorial(n) / factorial((n-k));					// Формула размещения без повторения
						std::cout << "\nОтвет: " << A << "\n\n";
						return 0;
					}

				}
				else if (povtor == 2)
				{
					while (true)
					{
						system("cls");
						std::cout << "\n\n\n\nЗадача A (размещение с повторениями)\n\n"; // Вводим значения для n и k
						std::cout << "Введите значения n: ";
						std::cin >> n;
						std::cout << "\nВведите значения k: ";
						std::cin >> k;
						if (n < 0 || k < 0 || k > n)							//проверяем на допустимые
						{
							std::cout << "\nБыть такого не может!\n";
							Sleep(1500);
							continue;
						}
						A = pow(n, k);											// Формула размещения с повторениями
						std::cout << "\nОтвет: " << A << "\n\n";
						return 0;
					}
				}
				else if (povtor == 0)												// Вернуться в главное меню
				{
					break;
				}
				else
				{																			// Проверяем выбор
					std::cout << "Неверный ввод\n";
					Sleep(1500);
				}
			}

		}
		else if (choose == 2)
		{
			while (true)
			{
				system("cls");
				std::cout << "\n\n\n\nТип задачи C (сочетания)\n\n";				//меню выбираем повторения.
				std::cout << "1 - Без повторений\n\n";
				std::cout << "2 - С повторениями\n\n";
				std::cout << "0 - Обратно к типу задачи\n\n";
				std::cout << "Ввод: ";
				std::cin >> povtor;
				if (povtor == 1)
				{
					while (true)
					{
						system("cls");
						std::cout << "\n\n\n\nЗадача С (сочетания без повторений)\n\n";   //Вводим значения для n и k
						std::cout << "Введите значения n: ";
						std::cin >> n;
						std::cout << "\nВведите значения k: ";
						std::cin >> k;
						if (n < 0 || k < 0 || k > n)								//Проверяем допустимы ли эти значения
						{
							std::cout << "\nБыть такого не может!";
							Sleep(1500);
							continue;
						}

						C = factorial(n) / (factorial(k) * factorial(n - k));				// Формула сочетания без повторения
						std::cout << "\nОтвет: " << C << "\n\n";
						return 0;
					}

				}
				else if (povtor == 2)
				{
					while (true)
					{
						system("cls");
						std::cout << "\n\n\n\nЗадача С (сочитания с повторениями)\n\n";         //Вводим значения для n и k
						std::cout << "Введите значения n: ";
						std::cin >> n;
						std::cout << "\nВведите значения k: ";
						std::cin >> k;
						if (n < 0 || k < 0 || k > n)										//проверяем
						{
							std::cout << "\nБыть такого не может!\n";
							Sleep(1500);
							continue;
						}
						C = factorial(n+k-1) / (factorial(k) * factorial(n - 1));				//формула сочетания с повторениями
						std::cout << "\nОтвет: " << C << "\n\n";
						return 0;
					}
				}
				else if (povtor == 0)														//выходим в главное меню
				{
					break;
				}
				else
				{
					std::cout << "Неверный ввод\n";									//проверяем ввод
					Sleep(1500);
				}
			}
		}
		else if (choose == 3)
		{
			while (true)
			{
				system("cls");
				std::cout << "\n\n\n\nТип задачи P (перестановка)\n\n";
				std::cout << "1 - Без повторений\n\n";
				std::cout << "2 - С повторениями\n\n";
				std::cout << "0 - Обратно к типу задачи\n\n";
				std::cout << "Ввод: ";
				std::cin >> povtor;
				if (povtor == 1)
				{
					while (true)
					{
						system("cls");
						std::cout << "\n\n\n\nЗадача Р (перестановка без повторений)\n\n";			//Вводим значение n
						std::cout << "Введите значения n: ";
						std::cin >> n;
						if (n < 0)
						{
							std::cout << "\nБыть такого не может!";					//проверяем правильное ли число ввёл
							Sleep(1500);
							continue;
						}
						P = factorial(n);										// формула перестановки с повторениями
						std::cout << "\nОтвет: " << P << "\n\n";
						return 0;
					}

				}
				else if (povtor == 2)
				{
					while (true)
					{
						system("cls");
						std::cout << "\n\n\n\nЗадача P (перестановка с повторениями)\n\n";

						std::cout << "Введите кол-во n: ";						//вводим количество n
						std::cin >> n;
						if (n < 0)
						{
							std::cout << "\nНе может быть такого!";							//проверяем
							Sleep(1500);
							continue;
						}
						for (int i = 0; i < n; i++)
						{
							std::cout << "\nВведите значение для n" << i + 1 << ": ";						//просим пользователя вводить для каждого n значение пока количество n не кончатся
							std::cin >> n1;
							k += n1;
							P_znamenatel *= factorial(n1);                                         //полученные факториалы умножаем между собой
							if (n1 < 0)
							{
								proverka_na_null = 0;
								std::cout << "\nНельзя писать отрицательные числа!\n\n";							//проверяем на правильные числа
								Sleep(1500);
								break;
							}
						}
						if (proverka_na_null == 1)
						{
							P = factorial(k) / P_znamenatel;								// Формула перестановки с повторениями


							std::cout << "\nОтвет: " << P << "\n\n";
							return 0;
						}
					}
				}
				else if (povtor == 0)								//выйти в меню
				{
					break;
				}
				else
				{
					std::cout << "Неверный ввод\n";					//проверка ввода
					Sleep(1500);
				}
			}
		}
		else
		{
			std::cout << "Неверный ввод\n";						//проверка ввода
			Sleep(1500);
		}
	}



*/

/*
	int task;
	std::cout << "Введите номер задачи (1, 2 или 3): ";
	std::cin >> task;

	if (task == 1)
	{
		int numbers;
		int n1 = 0;
		int n2 = 0;
		int n3 = 0;
		int n4 = 0;
		int n5 = 0;
		int n6 = 0;
		int num123 = 0;
		int num456 = 0;
		std::cout << "Введите шестизначное число: ";
		std::cin >> numbers;
		if (numbers>=100000 && numbers <=999999)
		{
			n1 = numbers / 100000;
			n2 = (numbers / 10000) % 10;
			n3 = (numbers / 1000) % 10;
			n4 = (numbers / 100) % 10;
			n5 = (numbers / 10) % 10;
			n6 = numbers % 10;

			num123 = n1 + n2 + n3;
			num456 = n4 + n5 + n6;
			if (num123 == num456)
			{
				std::cout << "Число счастливое";
			}
			else
			{
				std::cout << "Не счастливое";
			}
		}
		else
		{
			std::cout << "Число не шестизначное";
		}
	}
	else if (task == 2)
	{
		int numbers = 0;
		int n1 = 0;
		int n2 = 0;
		int n3 = 0;
		int n4 = 0;

		std::cout << "Введи четырёхзначное число: ";
		std::cin >> numbers;
		if (numbers >= 1000 && numbers <= 9999)
		{
			n1 = numbers / 1000;
			n2 = (numbers / 100) % 10;
			n3 = (numbers / 10) % 10;
			n4 = numbers % 10;
			std::cout << n2 << "" << n1 << "" << n4 << "" << n3;
		}
		else
		{
			std::cout << "Ошибка";
		}
	}
	else if (task == 3)
	{
		int numbers;
		int n1 = 0;
		int n2 = 0;
		int n3 = 0;
		int n4 = 0;
		int n5 = 0;
		int n6 = 0;
		int n7 = 0;
		int max = 0;
		std::cout << "Введите семизначное число: ";
		std::cin >> numbers;
		if (numbers >= 1000000 && numbers <= 9999999)
		{
			n1 = numbers / 1000000;
			n2 = (numbers / 100000) % 10;
			n3 = (numbers / 10000) % 10;
			n4 = (numbers / 1000) % 10;
			n5 = (numbers / 100) % 10;
			n6 = (numbers / 10) % 10;
			n7 = numbers % 10;
			std::cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << " " << n6 << " " << n7 << " ";
			max = n1;
			if (max < n2)
			{
				max = n2;
			}
			if (max < n3)
			{
				max = n3;
			}
			if (max < n4)
			{
				max = n4;
			}
			if (max < n5)
			{
				max = n5;
			}
			if (max < n6)
			{
				max = n6;
			}
			if (max < n7)
			{
				max = n7;
			}
			std::cout << "Максимальная циферка: " << max;
		}
	}
	else
	{
		std::cout << "Не то нажали";
	}
*/

/*




	int task;
	std::cout << "Введите номер задачи (1 или 2): ";
	std::cin >> task;



	if (task == 1)
	{
		int c = 0;
		int summa = 0;

		do {
			summa += c;

			std::cout << "Введите число (0 - конец): ";
			std::cin >> c;

		} while (c != 0);


		std::cout << "Сумма всех чисел: " << summa;
	}
	else if (task == 2)
	{
		int i = 0;

		do
		{
			std::cout << "\tМеню\n";
			std::cout << "1 - Новая игра\n";
			std::cout << "2 - Настройка\n";
			std::cout << "3 - Выход\n";
			std::cin >> i;
			if (i == 1)
			{
				std::cout << "Выбрана новая игра\n";
			}
			else if (i == 2)
			{
				std::cout << "Выбраны настройки\n";
			}
			else if (i == 3)
			{
				std::cout << "Выбран выход\n";
			}
			else
			{
				std::cout << "Не то что то ввели\n\n";
			}
		} while (i != 1 && i != 2 && i != 3);




	}





















do
	{


	} while (true);








int c = 0;

	while (c < 5)
	{

		std::cout << "Hello ";

		c++;

		if (c == 3)
		{
			continue;
		}
		std::cout << "world\n";
	}








	int task;

	std::cout << "Введите номер задания (1, 2, 3): ";
	std::cin >> task;

	if (task == 1)
	{
		double way;
		double time;
		double speed;
		std::cout << "\nВведите расстояние (в километрах) до аэропорта: ";
		std::cin >> way;
		std::cout << "\nВведите время (в часах), за которое нужно доехать: ";
		std::cin >> time;
		speed = way / time;
		std::cout << "\nСкорость с которой нужно ехать: " << speed << " км/ч\n";
	}

	else if (task == 2)
	{
		double start_time_hour;
		double start_time_minute;
		double start_time_second;
		double end_time_hour;
		double end_time_minute;
		double end_time_second;
		double start_time;
		double end_time;
		double time;
		double price;
		std::cout << "\nВведите время начала использования скутера. Часы, минуты и секунды.";
		std::cout << "\nВведите часы: ";
		std::cin >> start_time_hour;
		std::cout << "\nВведите минуты: ";
		std::cin >> start_time_minute;
		std::cout << "\nВведите секунды: ";
		std::cin >> start_time_second;

		std::cout << "\nВведите время завершения использования скутера. Часы, минуты и секунды.";
		std::cout << "\nВведите часы: ";
		std::cin >> end_time_hour;
		std::cout << "\nВведите минуты: ";
		std::cin >> end_time_minute;
		std::cout << "\nВведите секунды: ";
		std::cin >> end_time_second;

		start_time = (start_time_hour * 3600) + start_time_minute + (start_time_second / 60);
		end_time = (end_time_hour * 3600) + end_time_minute  + (end_time_second / 60);

		time = end_time - start_time;

		price = time * 2;
		std::cout << "\nСтоимость за использования скутера: "<< price << " гривна";

	}

	else if (task == 3)
	{
		double way;
		double consumption;
		double fuel1;
		double fuel2;
		double fuel3;
		double price1;
		double price2;
		double price3;
		double size;
		std::cout << "\nВведите расстояние (в километрах): ";
		std::cin >> way;

		std::cout << "\nВведите расход бензина на 100 км (в литрах): ";
		std::cin >> consumption;

		std::cout << "\nВведите стоимость первого вида бензина(за литр): ";
		std::cin >> fuel1;

		std::cout << "\nВведите стоимость второго вида бензина(за литр): ";
		std::cin >> fuel2;

		std::cout << "\nВведите стоимость третьего вида бензина(за литр): ";
		std::cin >> fuel3;
		size = (way * consumption) / 100;
		price1 = size * fuel1;
		price2 = size * fuel2;
		price3 = size * fuel3;

		std::cout << "\n\n" << "\tВид бензина\t" << " " << "Цена за литр\t" << " " << "Общий расход\t" << " " << "Стоимость поездки" << "\n\n";
		std::cout << "" << "\tПервый бензин" << "\t " << fuel1 << "\t\t " << size << "\t\t " << price1 <<"\n";
		std::cout << "" << "\tВторой бензин" << "\t " << fuel2 << "\t\t " << size << "\t\t " << price2 << "\n";
		std::cout << "" << "\tТретий бензин" << "\t " << fuel3 << "\t\t " << size << "\t\t " << price3 << "\n";



	}

	else
	{
		std::cout << "Что-то не то ввели";
	}











std::cout << "\tHello World " << "Ламонов Ярослав\n\n\n\n\n";

	std::cout << "-------------------------\n";
	std::cout << "< Hecker угольные шахты >\n";
	std::cout << "-------------------------\n";
	std::cout << "\t\\   ^__^\n";
	std::cout << "\t \\  (00)\\________\n";
	std::cout << "\t    (__)\\        )\\/\\\n";
	std::cout << "\t        ||------W|\n";
	std::cout << "\t        ||      ||\n";






*/

