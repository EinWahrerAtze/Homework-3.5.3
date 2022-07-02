#include <iostream>
#include "Shapes.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	const int SIZE = 11;
	Figure * pointer[SIZE];

	pointer[0] = new Figure;
	pointer[1] = new Triangle;
	pointer[2] = new Wrong_right_triangle;
	pointer[3] = new Right_triangle;
	pointer[4] = new Isosceles_triangle;
	pointer[5] = new Equilateral_triangle;
	pointer[6] = new Quadrangle;
	pointer[7] = new Rectangle;
	pointer[8] = new Square;
	pointer[9] = new Parallelogram;
	pointer[10] = new Rhombus;

	for (int i = 0; i < SIZE; ++i)
	{
		pointer[i]->print();
		std::wcout << (i == SIZE - 1 ? "" : "\n");
	}

	for (int i = 0; i < SIZE; ++i)
	{
		delete pointer[i];
	}

	return 0;
}