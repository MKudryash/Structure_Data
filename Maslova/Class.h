#pragma once
class Heap {
	static const int SIZE = 100; // максимальный размер кучи
	int* h;         // указатель на массив кучи
	int HeapSize; // размер кучи
public:
	Heap();  // конструктор кучи
	void addelem(int);  // добавление элемента кучи
	void outHeap();  // вывод элементов кучи в форме кучи
	void out();  // вывод элементов кучи в форме массива
	int getmax();  // удаление вершины (максимального элемента)
	void heapify(int);  // упорядочение кучи
};

