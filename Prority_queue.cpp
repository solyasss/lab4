#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class QueuePriority
{
	// Очередь
	int* Wait;
	// Приоритет
	int* Pri;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	QueuePriority(int m);

	//Деструктор
	~QueuePriority();

	// Добавление элемента
	void Add(int c, int p);

	// Извлечение элемента
	int Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();
};

void QueuePriority::Show() {
	cout << "\n-------------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " - " << Pri[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}

QueuePriority::~QueuePriority()
{
	//удаление очереди
	delete[]Wait;
	delete[]Pri;
}

QueuePriority::QueuePriority(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

void QueuePriority::Clear()
{
	// Эффективная "очистка" очереди 
	QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool QueuePriority::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	// Количество присутствующих в очереди элементов
	return QueueLength;
}

void QueuePriority::Add(int c, int p)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull()) {
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}

int QueuePriority::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// у которого наивысший приоритет и сдвигаем очередь	
	if (!IsEmpty()) {


		//пусть приоритетный элемент - нулевой
		int max_pri = Pri[0];
		//а приоритетный индекс = 0
		int pos_max_pri = 0;

		//ищем приоритет
		for (int i = 1; i < QueueLength; i++)
			//если встречен более приоритетный элемент
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}

		//вытаскиваем приоритетный элемент
		int temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		//сдвинуть все элементы
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//уменьшаем количество
		QueueLength--;
		// возврат извлеченного элемента	
		return temp1;

	}
	else return -1;
}

void main()
{
	srand(time(0));

	//создание очереди
	QueuePriority QUP(25);

	//заполнение части элементов
	for (int i = 0; i < 5; i++) {

		// значения от 0 до 99 (включительно)
		// и приоритет от 0 до 11 (включительно)
		QUP.Add(rand() % 100, rand() % 12+1);
	}
	//показ очереди
	QUP.Show();

	//извлечение элемента
	QUP.Extract();

	//показ очереди
	QUP.Show();
}