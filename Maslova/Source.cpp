#include <iostream>
#include <cassert>
using namespace std;

//��������� ����������� ������ �����
struct CArray1
{
	int* Buffer;
	int BufferSize;
	int RealSize;

	CArray1() :Buffer(0), BufferSize(0), RealSize(0) {}
};
//������ � �������� ������� �� �������
int GetAt(CArray1& mas, int index)
{
	assert(index >= 0 && index < mas.RealSize && mas.Buffer != 0);
	return mas.Buffer[index];
}
//���������� ������
void Grow(CArray1& mas)
{
	//������� ����� �����
	int newBufferSize = mas.BufferSize * 2;
	int* newBuffer = new int[newBufferSize];
	//��������
	for (int i = 0; i < mas.RealSize; i++)
	{
		newBuffer[i] = mas.Buffer[i];
		//������ ������ �����
	}
	delete[] mas.Buffer;
	mas.Buffer = newBuffer;
	mas.BufferSize = newBufferSize;
}
// ���������� ������ ��������
void Add(CArray1& mas, double element)
{
	if (mas.RealSize == mas.BufferSize)
	{
		Grow(mas);
	}
	assert(mas.RealSize < mas.BufferSize && mas.Buffer != 0);
	mas.Buffer[mas.RealSize++] = element;
}


//��������� ����������� ����������� ������
struct list
{
	int field; // ���� ������
	struct list* ptr; // ��������� �� ��������� �������
};
//������������� ���
struct list* initList(int a) // �- �������� ������� ����
{
	struct list* lst;
	// ��������� ������ ��� ������ ������
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->ptr = NULL; // ��� ��������� ���� ������
	return(lst);
}
//���������� ���� � ���
struct list* addelem(list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr; // ���������� ��������� �� ��������� ����
	lst->ptr = temp; // ���������� ���� ��������� �� �����������
	temp->field = number; // ���������� ���� ������ ������������ ����
	temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
	return(temp);
}
//�������� ���� ���
struct list* deletelem(list* lst, list* root)
{
	struct list* temp;
	temp = root;
	while (temp->ptr != lst) // ������������� ������ ������� � �����
	{ // ���� �� ������ ����, �������������� lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // ������������ ���������
	free(lst); // ����������� ������ ���������� ����
	return(temp);
}
//����� ��������� ������
void listprint(list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->field); // ����� �������� �������� p
		p = p->ptr; // ������� � ���������� ����
	} while (p != NULL);
}


//������� ����������� ����� � �������������� ����������
struct CNode
{
	int Data;
	CNode* Next;
	CNode* Prev;
	CNode() :Data(0), Next(0), Prev(0) {}
};
//�������� ������� "�" � ������. ���������� 0, ���� ������� �� ������
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
//������� �������� "�" ����� ��������
CNode* InsertAfter(CNode* node, int a)
{
	assert(node != 0);
	//������� ����� �������
	CNode* newNode = new CNode();
	newNode->Data = a;
	newNode->Next = node->Next;
	newNode->Prev = node;
	//��������� Prev ���������� ��������, ���� �� ����
	if (node->Next != 0)
	{
		node->Next->Prev = newNode;
	}
	//��������� Next �������� ��������
	node->Next = newNode;
	return newNode;
}
//����������� �������. � ������ 1 ���������� ������ 2
void Union(CNode* head1, CNode* head2)
{
	assert(head1 != 0 && head2 != 0);
	//���� �  ����� ������ 1
	CNode* tail1 = head1;
	for (; tail1->Next != 0; tail1 = tail1->Next);
	//��������� Next ������
	tail1->Next = head2;
	//��������� prev ������ ������� ������
	head2->Prev = tail1;
}
void listprint(CNode* head)
{
	struct CNode* p;
	p = head;
	do {
		printf("%d ", p->Data); // ����� �������� �������� p
		p = p->Prev; // ������� � ���������� ����
	} while (p != NULL); // ������� ��������� ������
}
struct CNode* addelem(CNode* lst, int number)
{
	struct CNode* temp, * p;
	temp = (struct CNode*)malloc(sizeof(CNode));
	p = lst->Next; // ���������� ��������� �� ��������� ����
	lst->Next = temp; // ���������� ���� ��������� �� �����������
	temp->Data = number; // ���������� ���� ������ ������������ ����
	temp->Next = p; // ��������� ���� ��������� �� ��������� ����
	temp->Prev = lst; // ��������� ���� ��������� �� ���������� ����
	if (p != NULL)
		p->Prev = temp;
	return(temp);
}
struct CNode* init(int a)  // �- �������� ������� ����
{
	struct CNode* lst;
	// ��������� ������ ��� ������ ������
	lst = (struct CNode*)malloc(sizeof(struct CNode*));
	lst->Data = a;
	lst->Next = NULL; // ��������� �� ��������� ����
	lst->Prev = NULL; // ��������� �� ���������� ����
	return(lst);
}


//������������� ���
struct list* initCircle(int a) // �- �������� ������� ����
{
	struct list* lst;
	// ��������� ������ ��� ������ ������
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->ptr = lst; // ��������� �� ��� �������� ����
	return(lst);
}
//���������� ���� � ���
struct list* addelem�ircle(list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr; // ���������� ��������� �� ��������� �������
	lst->ptr = temp; // ���������� ���� ��������� �� �����������
	temp->field = number; // ���������� ���� ������ ������������ ����
	temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
	return(temp);
}
//�������� ���� ���
struct list* deletelem�ircle(list* lst)
{
	struct list* temp;
	temp = lst;
	while (temp->ptr != lst) // ������������� ������ ������� � �����
	{ // ���� �� ������ ����, �������������� lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // ������������ ���������
	free(lst); // ����������� ������ ���������� ����
	return(temp);
}
//����� ��������� ��� 
void listprint�ircle(list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->field); // ����� �������� ���� p
		p = p->ptr; // ������� � ���������� ����
	} while (p != lst); // ������� ��������� ������
}
 
 
//��������� ����������� ����
struct CStack
{
	int* buffer;
	int bufferSize;
	int top;
};
//���������� ��������
void Push(CStack& stack, int a)
{
	assert(stack.top + 1 < stack.bufferSize);
	stack.buffer[stack.top++] = a;
}
//������������ ��������
int Pop(CStack& stack)
{
	assert(stack.top != 1);
	return stack.buffer[stack.top--];
}

//��������� ����������� �������
struct CQueue
{
	int* buffer;
	int bufferSize;
	int head;
	int tail;
};
//���������� ��������
void AddEnqueue(CQueue& queue, int a)
{
	//assert((queue.head - queue.tail + queue.bufferSize) % queue.bufferSize != 1);
	queue.buffer[queue.tail++] = a;
	if (queue.tail == queue.bufferSize)
		queue.tail = 0;
}
//���������� ��������
int DeleteEnqueue(CQueue& queue)
{
	assert(queue.head != queue.tail);
	int result = queue.buffer[queue.head++];
	if (queue.head == queue.bufferSize)
		queue.head = 0;
	return result;
}


struct Heap {
	static const int SIZE = 100; // ������������ ������ ����
	int* h;         // ��������� �� ������ ����
	int HeapSize; // ������ ����
};
//����� ��������� ����
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
//����� ��������� ���� � ����� �������
void out(Heap& heap) {
	for (int i = 0; i < heap.HeapSize; i++) {
		cout << heap.h[i] << " ";
	}
	cout << endl;
}
//����� ��������� � ����� ����
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
//������������ ����
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
//�������� ������� ���� 
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
	//��������� ������ ������������ ������
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

	//����������� ������
	/*list* lists = new list;
	lists = init(10);
	addelem(lists, 6);
	addelem(lists, 5);
	addelem(lists, 4);
	addelem(lists, 3);
	addelem(lists, 2);
	addelem(lists, 1);
	listprint(lists);*/

	//���������� ������
	/*CNode* spisok = init(1);
	spisok = addelem(spisok, 4);
	spisok = addelem(spisok, 5);
	spisok = addelem(spisok, 6);
	spisok = addelem(spisok, 7);
	spisok = addelem(spisok, 1);
	spisok = addelem(spisok, 2);
	listprint(spisok);*/

	//�������� ������
	/*list* lists = new list;
	lists = initCircle(10);
	addelem�ircle(lists, 6);
	addelem�ircle(lists, 5);
	addelem�ircle(lists, 4);
	addelem�ircle(lists, 3);
	addelem�ircle(lists, 2);
	addelem�ircle(lists, 1);
	listprint�ircle(lists);*/

	//����
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
	}*///����

	//�������
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
	printf("������� �� ��������: %d\n", DeleteEnqueue(queue));*/

	//�������� ����
	/*Heap heap;
	heap.h = new int[100];
	heap.HeapSize = 0;
	int k;
	for (int i = 0; i < 16; i++) {
		cout << "������� ������� " << i + 1 << ": ";
		cin >> k;
		addelem(heap, k);
	}
	outHeap(heap);
	printf("\n");
	out(heap);
	printf("������������ �������: %d\n", getmax(heap));
	printf("����� ����:");
	outHeap(heap);
	printf("\n");
	out(heap);
	printf("������������ �������: %d\n", getmax(heap));
	printf("����� ����:");
	outHeap(heap);
	printf("\n");
	out(heap);*/
	return 0;
}