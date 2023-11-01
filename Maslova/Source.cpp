#include <iostream>
#include <cassert>
using namespace std;

//Структура описывающая массив чисел
struct CArray1
{
	int* Buffer;
	int BufferSize;
	int RealSize;

	CArray1() :Buffer(0), BufferSize(0), RealSize(0) {}
};
//Доступ к элементу массива по индексу
int GetAt(CArray1& mas, int index)
{
	assert(index >= 0 && index < mas.RealSize && mas.Buffer != 0);
	return mas.Buffer[index];
}
//Увелечение буфера
void Grow(CArray1& mas)
{
	//Создаем новый буфер
	int newBufferSize = mas.BufferSize * 2;
	int* newBuffer = new int[newBufferSize];
	//Копируем
	for (int i = 0; i < mas.RealSize; i++)
	{
		newBuffer[i] = mas.Buffer[i];
		//Чистим старый буфер
	}
	delete[] mas.Buffer;
	mas.Buffer = newBuffer;
	mas.BufferSize = newBufferSize;
}
// Добавление нового элемента
void Add(CArray1& mas, double element)
{
	if (mas.RealSize == mas.BufferSize)
	{
		Grow(mas);
	}
	assert(mas.RealSize < mas.BufferSize && mas.Buffer != 0);
	mas.Buffer[mas.RealSize++] = element;
}


//Структура описывающая односвязный спсиок
struct list
{
	int field; // поле данных
	struct list* ptr; // указатель на следующий элемент
};
//Инициализация ОЛС
struct list* initList(int a) // а- значение первого узла
{
	struct list* lst;
	// выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->ptr = NULL; // это последний узел списка
	return(lst);
}
//Добавление узла в ОЛС
struct list* addelem(list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr; // сохранение указателя на следующий узел
	lst->ptr = temp; // предыдущий узел указывает на создаваемый
	temp->field = number; // сохранение поля данных добавляемого узла
	temp->ptr = p; // созданный узел указывает на следующий элемент
	return(temp);
}
//Удаление узла ОЛС
struct list* deletelem(list* lst, list* root)
{
	struct list* temp;
	temp = root;
	while (temp->ptr != lst) // просматриваем список начиная с корня
	{ // пока не найдем узел, предшествующий lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // переставляем указатель
	free(lst); // освобождаем память удаляемого узла
	return(temp);
}
//Вывод элементов списка
void listprint(list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->field); // вывод значения элемента p
		p = p->ptr; // переход к следующему узлу
	} while (p != NULL);
}


//Элемент двусвязного спика с целочисленными значениями
struct CNode
{
	int Data;
	CNode* Next;
	CNode* Prev;
	CNode() :Data(0), Next(0), Prev(0) {}
};
//линейный элемент "а" в списке. Возвращает 0, если элемент не найден
CNode* Search(CNode* head, int a)
{
	CNode* current = head;
	while (current != 0)
	{
		if (current->Data == a)
			return current;
		current = current->Next;
	}
	return 0;
}
//Вставка элемента "а" после текущего
CNode* InsertAfter(CNode* node, int a)
{
	assert(node != 0);
	//Создаем новый элемент
	CNode* newNode = new CNode();
	newNode->Data = a;
	newNode->Next = node->Next;
	newNode->Prev = node;
	//Обновляем Prev следующего элемента, если он есть
	if (node->Next != 0)
	{
		node->Next->Prev = newNode;
	}
	//Обновляем Next текущего элемента
	node->Next = newNode;
	return newNode;
}
//Объединение списков. К списку 1 подцепляем список 2
void Union(CNode* head1, CNode* head2)
{
	assert(head1 != 0 && head2 != 0);
	//ижем в  хвост списка 1
	CNode* tail1 = head1;
	for (; tail1->Next != 0; tail1 = tail1->Next);
	//Обновляем Next хвоста
	tail1->Next = head2;
	//Обновляем prev головы второго списка
	head2->Prev = tail1;
}
void listprint(CNode* head)
{
	struct CNode* p;
	p = head;
	do {
		printf("%d ", p->Data); // вывод значения элемента p
		p = p->Prev; // переход к следующему узлу
	} while (p != NULL); // условие окончания обхода
}
struct CNode* addelem(CNode* lst, int number)
{
	struct CNode* temp, * p;
	temp = (struct CNode*)malloc(sizeof(CNode));
	p = lst->Next; // сохранение указателя на следующий узел
	lst->Next = temp; // предыдущий узел указывает на создаваемый
	temp->Data = number; // сохранение поля данных добавляемого узла
	temp->Next = p; // созданный узел указывает на следующий узел
	temp->Prev = lst; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->Prev = temp;
	return(temp);
}
struct CNode* init(int a)  // а- значение первого узла
{
	struct CNode* lst;
	// выделение памяти под корень списка
	lst = (struct CNode*)malloc(sizeof(struct CNode*));
	lst->Data = a;
	lst->Next = NULL; // указатель на следующий узел
	lst->Prev = NULL; // указатель на предыдущий узел
	return(lst);
}


//Инициализация ОЦС
struct list* initCircle(int a) // а- значение первого узла
{
	struct list* lst;
	// выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->ptr = lst; // указатель на сам корневой узел
	return(lst);
}
//Добавление узла в ОЦС
struct list* addelemСircle(list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr; // сохранение указателя на следующий элемент
	lst->ptr = temp; // предыдущий узел указывает на создаваемый
	temp->field = number; // сохранение поля данных добавляемого узла
	temp->ptr = p; // созданный узел указывает на следующий элемент
	return(temp);
}
//Удаление узла ОЦС
struct list* deletelemСircle(list* lst)
{
	struct list* temp;
	temp = lst;
	while (temp->ptr != lst) // просматриваем список начиная с корня
	{ // пока не найдем узел, предшествующий lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // переставляем указатель
	free(lst); // освобождаем память удаляемого узла
	return(temp);
}
//Вывод элементов ОЦС 
void listprintСircle(list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->field); // вывод значения узла p
		p = p->ptr; // переход к следующему узлу
	} while (p != lst); // условие окончания обхода
}
 
 
//Структура описывающая стек
struct CStack
{
	int* buffer;
	int bufferSize;
	int top;
};
//Добавление элемента
void Push(CStack& stack, int a)
{
	assert(stack.top + 1 < stack.bufferSize);
	stack.buffer[stack.top++] = a;
}
//Извлевечение элемента
int Pop(CStack& stack)
{
	assert(stack.top != 1);
	return stack.buffer[stack.top--];
}

//Структура описывающая очередь
struct CQueue
{
	int* buffer;
	int bufferSize;
	int head;
	int tail;
};
//Добавление элемента
void AddEnqueue(CQueue& queue, int a)
{
	//assert((queue.head - queue.tail + queue.bufferSize) % queue.bufferSize != 1);
	queue.buffer[queue.tail++] = a;
	if (queue.tail == queue.bufferSize)
		queue.tail = 0;
}
//Извлечение элемента
int DeleteEnqueue(CQueue& queue)
{
	assert(queue.head != queue.tail);
	int result = queue.buffer[queue.head++];
	if (queue.head == queue.bufferSize)
		queue.head = 0;
	return result;
}


struct Heap {
	static const int SIZE = 100; // максимальный размер кучи
	int* h;         // указатель на массив кучи
	int HeapSize; // размер кучи
};
//Вывод элементов кучи
void addelem(Heap& heap, int n) {
	int i, parent;
	i = heap.HeapSize;
	heap.h[i] = n;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0) {
		if (heap.h[i] > heap.h[parent]) {
			int temp = heap.h[i];
			heap.h[i] = heap.h[parent];
			heap.h[parent] = temp;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	heap.HeapSize++;
}
//Вывод элементов кучи в форме массива
void out(Heap& heap) {
	for (int i = 0; i < heap.HeapSize; i++) {
		cout << heap.h[i] << " ";
	}
	cout << endl;
}
//Вывод элементов в форме кучи
void outHeap(Heap& heap) {
	int i = 0;
	int k = 1;
	while (i < heap.HeapSize) {
		while ((i < k) && (i < heap.HeapSize)) {
			cout << heap.h[i] << " ";
			i++;
		}
		cout << endl;
		k = k * 2 + 1;
	}
}
//Упорядочение кучи
void heapify(Heap& heap, int i) {
	int left, right;
	int temp;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < heap.HeapSize) {
		if (heap.h[i] < heap.h[left]) {
			temp = heap.h[i];
			heap.h[i] = heap.h[left];
			heap.h[left] = temp;
			heapify(heap, left);
		}
	}
	if (right < heap.HeapSize) {
		if (heap.h[i] < heap.h[right]) {
			temp = heap.h[i];
			heap.h[i] = heap.h[right];
			heap.h[right] = temp;
			heapify(heap, right);
		}
	}
}
//Удаление вершины кучи 
int getmax(Heap& heap) {
	int x;
	x = heap.h[0];
	heap.h[0] = heap.h[heap.HeapSize - 1];
	heap.HeapSize -= 1;
	heapify(heap, 0);
	return(x);
}



int main()
{
	system("chcp 1251");
	//Структура данных динамический массив
	/*CArray1 initArray;
	srand(clock());
	initArray.BufferSize = 5;
	initArray.RealSize = 5;
	initArray.Buffer = new int[5];
	for (size_t i = 0; i < 5; i++)
	{
		initArray.Buffer[i] = rand() % 50;
	}

	for (int i = 0; i < initArray.RealSize; i++)
	{
		printf("%d ", initArray.Buffer[i]);
	}

	Add(initArray, 5);

	printf("\n");
	for (int i = 0; i < initArray.RealSize; i++)
	{
		printf("%d ",initArray.Buffer[i]);
	}*/

	//Односвязный список
	/*list* lists = new list;
	lists = init(10);
	addelem(lists, 6);
	addelem(lists, 5);
	addelem(lists, 4);
	addelem(lists, 3);
	addelem(lists, 2);
	addelem(lists, 1);
	listprint(lists);*/

	//Двусвязный список
	/*CNode* spisok = init(1);
	spisok = addelem(spisok, 4);
	spisok = addelem(spisok, 5);
	spisok = addelem(spisok, 6);
	spisok = addelem(spisok, 7);
	spisok = addelem(spisok, 1);
	spisok = addelem(spisok, 2);
	listprint(spisok);*/

	//Круговой список
	/*list* lists = new list;
	lists = initCircle(10);
	addelemСircle(lists, 6);
	addelemСircle(lists, 5);
	addelemСircle(lists, 4);
	addelemСircle(lists, 3);
	addelemСircle(lists, 2);
	addelemСircle(lists, 1);
	listprintСircle(lists);*/

	//Стек
	/*CStack stack;
	srand(clock());
	stack.bufferSize = 15;
	stack.top = 5;
	stack.buffer = new int[5];
	for (size_t i = 0; i < 5; i++)
	{
		stack.buffer[i] = rand() % 50;
	}

	for (int i = 0; i < stack.top; i++)
	{
		printf("%d ", stack.buffer[i]);
	}

	Push(stack, 10);
	Push(stack, 12);
	Push(stack, 11);

	printf("\n");
	for (int i = 0; i < stack.top; i++)
	{
		printf("%d ", stack.buffer[i]);
	}
	Pop(stack);

	printf("\n");
	for (int i = 0; i < stack.top; i++)
	{
		printf("%d ", stack.buffer[i]);
	}*///Стек

	//Очередь
	/*CQueue queue;
	srand(clock());
	queue.bufferSize = 15;
	queue.head = 0;
	queue.tail = 0;

	AddEnqueue(queue, 10);
	AddEnqueue(queue, 12);
	AddEnqueue(queue, 11);

	printf("\n");
	for (int i = 0; i < queue.tail; i++)
	{
		printf("%d ", queue.buffer[i]);
	}
	printf("Элемент на удаление: %d\n", DeleteEnqueue(queue));*/

	//Двоичная куча
	/*Heap heap;
	heap.h = new int[100];
	heap.HeapSize = 0;
	int k;
	for (int i = 0; i < 16; i++) {
		cout << "Введите элемент " << i + 1 << ": ";
		cin >> k;
		addelem(heap, k);
	}
	outHeap(heap);
	printf("\n");
	out(heap);
	printf("Максимальный элемент: %d\n", getmax(heap));
	printf("Новая куча:");
	outHeap(heap);
	printf("\n");
	out(heap);
	printf("Максимальный элемент: %d\n", getmax(heap));
	printf("Новая куча:");
	outHeap(heap);
	printf("\n");
	out(heap);*/
	return 0;
}