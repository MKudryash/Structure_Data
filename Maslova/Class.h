#pragma once
class Heap {
	static const int SIZE = 100; // ������������ ������ ����
	int* h;         // ��������� �� ������ ����
	int HeapSize; // ������ ����
public:
	Heap();  // ����������� ����
	void addelem(int);  // ���������� �������� ����
	void outHeap();  // ����� ��������� ���� � ����� ����
	void out();  // ����� ��������� ���� � ����� �������
	int getmax();  // �������� ������� (������������� ��������)
	void heapify(int);  // ������������ ����
};

