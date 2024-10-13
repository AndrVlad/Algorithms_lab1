#include <clocale> 
#include <iostream>
#include <string>
#include "serial.h"
//#include "related.h";
using namespace std;

int TIME, last_time, elem_num = 0;

struct Detail
{
	string kod;
	int time = 0;
};

int main()
{	
	setlocale(LC_ALL, "");
	Detail detail;
	int detal = 0;
	int choose = 0;
	Queue <Detail> q;
	do
	{

		std::cout << "___________________________________________" << std::endl
			<< "Выберите действие: " << std::endl
			<< "1. Постановка детали на обработку" << std::endl
			<< "2. Следующий момент модального времени" << std::endl
			<< "3. Снятие детали с обработки до её завершения" << std::endl
			<< "4. Вывод списка обрабатываемых деталей в порядке очереди " << std::endl
			<< "5. Сброс процесса моделирования" << std::endl
			<< "______________________________________________" << std::endl;
		std::cout << "tail = " << q.tail << std::endl;
		std::cout << "head = " << q.head << std::endl;
		std::cin >> choose;
				switch (choose)
				{
				case 1:
				{
					cout << "Введите код детали и время её обработки" << endl;

					cin >> detail.kod >> detail.time;

					try {
						q.Enqueue(detail);
					}
					catch(const char* error_message){
						cout << error_message << endl;
					};

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

					break;
				}
				case 3:
				{
					if (!(q.Dequeue(detail))) {
						cout << "Очередь пуста!" << endl;
					}
					else {
						TIME = last_time = 0;
						cout << "Отказ установки! " << " Деталь была снята" << endl;
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
							cout << " <- " << detail.kod;
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
					cout << "Ошибка! Нет такого пункта меню" << endl;
				}
			} while (true);

	return 0;
}
