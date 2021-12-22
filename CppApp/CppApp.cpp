#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*-----------Parent-----------*/
class StackP {
protected:
	struct Cell {
		int Data;
		Cell* Next;
	};
	int K;
	int Size;
	Cell* Head;
	StackP() {
		Head = NULL;
		Size = 0;
	}
	void add(int i);
	int del();
	bool empty();
	int value();
};

void StackP::add(int i) {
	if (Head == NULL) {
		Cell* a = new Cell;
		a->Data = i;
		a->Next = NULL;
		Head = a;
		Size += 1;
	}
	else {
		Cell* a = new Cell;
		a->Data = i;
		a->Next = Head;
		Head = a;
		Size += 1;
	}
}

int StackP::del() {
	int a;
	a = Head->Data;
	Cell* b = Head->Next;
	delete Head;
	Head = b;
	Size -= 1;
	return a;
}

bool StackP::empty() {
	if (Head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int StackP::value() {
	return (Head->Data);
}

/*-----------Child-----------*/

class StackC : protected StackP {
public:
	void zapolnenie(int count);
	void pokazat_stack();
	void get(int i);
	void set(int i, int b);
	void sortirovka();
	void qsort(int* arr, int size);
	void ochistit_stack();
};


//////////////N_op////////////////////
void StackC::qsort(int* arr, int size)
{
	int* left = arr, * right = arr + size - 1;
	K += 6;
	int j = 0, i = size - 1;
	K += 5;
	int rod = *(arr + (size / 2));
	K += 4;
	while (j < i) {
		K += 1;
		while (*(arr + j) > rod) {
			K += 2;
			j++;
			K += 1;
		}
		while (*(arr + i) < rod) {
			K += 2;
			i--;
			K += 1;
		}
		if (j < i)
		{
			K += 1;
			*(arr + j) += *(arr + i);
			K += 4;
			*(arr + i) = *(arr + j) - *(arr + i);
			K += 5;
			*(arr + j) -= *(arr + i);
			K += 4;
			j++;
			K += 1;
			i--;
			K += 1;
		}
	}
	if (arr + j > left) {
		K += 2;
		K += 1;
		qsort(arr, j);
	}
	if (arr + i < right) {
		K += 2;
		K += 1;
		qsort(arr + j, size - j);
	}
}

void StackC::sortirovka()
{
	Cell* a = Head;
	K += 2;
	int* arr = new int[Size];
	K += 2;
	K += 2;
	for (int i = 0; i < Size; i++)
	{
		K += 2;
		arr[i] = Head->Data;
		K += 1;
		Head = Head->Next;
		K += 1;
	}
	Head = a;
	K += 1;
	qsort(arr, Size);
	K += 1;
	K += 2;
	for (int i = 0; i < Size; i++)
	{
		K += 2;
		set(i, arr[i]);
		K += 5;
	}
	cout << "N_op = " << K << endl << "--------------------" << endl;
}
/////////////N_op//////////////////

void StackC::zapolnenie(int count) {
	int a;
	for (int i = 0; i < count; i++) {
		a = rand();
		add(a);
	}
}

void StackC::set(int i, int b) {
	Cell* a = Head;
	for (int y = 1; y < i; y++) {
		Head = Head->Next;
	}
	Head->Data = b;
	Head = a;
}

void StackC::get(int i) {
	Cell* a = Head;
	for (int y = 1; y < i; y++) {
		Head = Head->Next;
	}

	cout << Head->Data << endl;
	Head = a;

}

void StackC::pokazat_stack() {
	if (empty() == false) {
		Cell* a = Head;
		for (int i = 0; i < Size; i++) {
			cout << Head->Data << endl;
			Head = Head->Next;
		}
		Head = a;
	}
	else {
		cout << "Stack is empty";
	}
}

void StackC::ochistit_stack() {
	while (empty() == false) {
		del();
	}
}

/*-----------Main-----------*/

int main() {
	char i;
	StackC a;
	a.zapolnenie(500);
	//cout << endl << "/*-----------Stack-----------*/" << endl;   показать весь стек
	//a.pokazat_stack();
	//cout << endl << "/*-----------Stack-----------*/" << endl;
	cout << endl << "/*-----------Get-----------*/" << endl;
	a.get(9);
	cout << endl << "/*-----------Get-----------*/" << endl;
	cout << endl << "/*-----------Set-----------*/" << endl;
	a.set(9, 252);
	a.get(9);
	cout << endl << "/*-----------Set-----------*/" << endl;
	cout << endl << "/*-----------Sortirovka-----------*/" << endl;
	unsigned int start = clock();
	a.sortirovka();
	unsigned int end = clock();
	//a.pokazat_stack();
	cout << endl << "/*-----------Sortirovka-----------*/" << endl;
	cout << endl << "Program time: " << end - start << "ms" << endl;
	return 0;
}
