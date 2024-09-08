
#include <clocale> 
#include <iostream>
#include <string>
#include "serial.h"
using namespace std;

int TIME, last_time, elem_num = 0;

struct Detail
{
	string kod;
	int time = 0;
	//int time;
};

int main()
{	
	setlocale(LC_ALL, "");
	Detail detail;
	int detal = 0;
	int choose = 0;
	//Queue <int> q;
	Queue <Detail> q;
	do
	{
		std::cout << "Текущее время: " << TIME << std::endl;
		std::cout << "last time: " << last_time << std::endl;
		std::cout << "___________________________________________" << std::endl
			<< "Выберите действие: " << std::endl
			<< "1. Постановка детали на обработку" << std::endl
			<< "2. Следующий момент модального времени" << std::endl
			<< "3. Снятие детали с обработки до её завершения" << std::endl
			<< "4. Вывод списка обрабатываемых деталей в порядке очереди " << std::endl
			<< "5. Сброс процесса моделирования" << std::endl
			<< "______________________________________________" << std::endl;
		std::cin >> choose;
				switch (choose)
				{
				case 1:
				{
					cout << "Введите код детали и время её обработки" << endl;

					cin >> detail.kod >> detail.time;
					//cin >> detal;

					if (q.Enqueue(detail)) {
						cout << "Деталь добавлена";
					}
					else {
						cout << "Очередь полна!";
					};

					cout << "head = " << q.head << "tail = " << q.tail;

					break;
				}
				case 2:
				{
					TIME++;
					
					if (q.getDetail(detail)) {
						
						if (TIME == (detail.time + last_time)) {
							q.Dequeue(detail);
							last_time += detail.time;
							cout << "Деталь " << detail.kod << " была обработана" << endl;
						}
					}
					else {
						last_time = TIME;
					}

					/*if (q.Dequeue(detail)) {
						cout << "Деталь удалена";
					}
					else {
						cout << "Пусто";
					};

					cout << "head = " << q.head << "tail = " << q.tail;*/
					break;
				}
				case 3:
				{
					if (!(q.Dequeue(detail))) {
						cout << "Очередь пуста!" << endl;
					}
					else {
						TIME = last_time = 0;
						cout << "Отказ установки! " << " Деталь " << detail.kod << " была снята" << endl;
					}

					break;
				}
				case 4:
				{
					if (!(q.ElemCount())) {
						cout << "Очередь пуста!" << endl;
					}
					else {
						elem_num = q.ElemCount();
						for (int i = 0; i < elem_num; i++) {
							q.getDetail(detail, i);
							cout << " <- " << detail.kod << endl;
						}
					}

					break;
				}
				case 5:
				{
					TIME = last_time = 0;
					q.InitQueue();
					break;
				}
				default:
					cout << "Ошибка! Попробуйте ввести другое число." << endl;
				}
			} while (true);

	return 0;
}

/*

#include <clocale> 
#include <iostream>
#include <string>
using namespace std;
#include "serial.h"
//#include "svyaznaya.h"

struct Detail
{
	string kod;
	int vremya_obrabotki;
};

int main()
{
	setlocale(LC_ALL, "");
	int choose;
	int model_time = 0;
	Detail detail;
	Queue<Detail> ochered;
	do
	{
		cout << "___________________________________________" << endl
			<< "Выберите действие: " << endl
			<< "1. Постановка детали на обработку" << endl
			<< "2. Переход к следующему моменту модельного времени" << endl
			<< "3. Снятие детали с обработки до её завершения" << endl
			<< "4. Вывод списка обрабатываемых деталей в порядке очереди " << endl
			<< "5. Сброс процесса моделиования" << endl
			<< "______________________________________________" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			cout << "Введите код детали и время её обработки" << endl;
			cin >> detail.kod >> detail.vremya_obrabotki;
			if (ochered.enQueue(detail))
				cout << "Деталь успешно добавлена" << endl;
			else
				cout << "Ошибка, очередь переполнена" << endl;
			break;
		}
		case 2:
		{
			model_time++;
			if (!ochered.isEmpty())
			{
				ochered.retFirst(detail);
				if (detail.vremya_obrabotki == model_time)
				{
					ochered.deQueue(detail);
					model_time = 0;
					cout << "Обработка детали успешно завершена" << endl;
				}
			}
			break;
		}
		case 3:
		{
			if (ochered.deQueue(detail))
			{
				model_time = 0;
				cout << "Обработка детали аварийно завершена " << endl;
			}
			else
				cout << "Ошибка, очередь пуста" << endl;
			break;
		}
		case 4:
		{
			int count = ochered.retN();
			while (count-- > 0)
			{
				ochered.deQueue(detail);
				cout << detail.kod << ' ';
				ochered.enQueue(detail);
			}
			cout << endl;
			break;
		}
		case 5:
		{
			while (!ochered.isEmpty())
			{
				ochered.deQueue(detail);
			}
			model_time = 0;
			break;
		}
		default:
			cout << "Ошибка! Попробуйте ввести другое число." << endl;
		}
	} while (true);
}
*/
