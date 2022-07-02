#pragma once
#include <iostream>
#include <string>

// Фигура
class Figure
{
public:
	void print();
	Figure(const std::wstring & nm = L"Фигура");
	virtual ~Figure();
protected:
	virtual void print_sides() const;
	virtual void print_angles() const;
	virtual bool check() const;
private:
	std::wstring name;
};

// Треугольник
class Triangle : public Figure
{
public:
	Triangle(const std::wstring & nm = L"Треугольник", int sides = 3, int a = 10, int b = 20, int c = 30, int A = 50, int B = 60, int C = 70);
protected:
	void print_sides() const override;
	void print_angles() const override;
	bool check() const override;
private:
	int m_sides;
	int m_a;
	int m_b;
	int m_c;
	int m_A;
	int m_B;
	int m_C;
};

// Правильный прямоугольный треугольник
class Right_triangle : public Triangle
{
public:
	Right_triangle(const std::wstring & nm = L"Прямоугольный треугольник", int sides = 3, int a = 10, int b = 20, int c = 30, int A = 50, int B = 40);
};

// Неправильный прямоугольный треугольник
class Wrong_right_triangle : public Triangle
{
public:
	Wrong_right_triangle(const std::wstring & nm = L"Прямоугольный треугольник", int sides = 3, int a = 10, int b = 20, int c = 30, int A = 50, int B = 60);
};

// Равнобедренный треугольник
class Isosceles_triangle : public Triangle
{
public:
	Isosceles_triangle(const std::wstring & nm = L"Равнобедренный треугольник", int sides = 3, int a = 10, int b = 20, int A = 50, int B = 60);
};

// Равносторонний треугольник
class Equilateral_triangle : public Triangle
{
public:
	Equilateral_triangle(const std::wstring & nm = L"Равносторонний треугольник", int sides = 3, int a = 30, int A = 60);
};

// Четырёхугольник
class Quadrangle : public Figure
{
public:
	Quadrangle(const std::wstring & nm = L"Четырёхугольник", int sides = 4, int a = 10, int b = 20, int c = 30, int d = 40, int A = 50, int B = 60, int C = 70, int D = 80);
protected:
	void print_sides() const override;
	void print_angles() const override;
	bool check() const override;
private:
	int m_sides;
	int m_a;
	int m_b;
	int m_c;
	int m_d;
	int m_A;
	int m_B;
	int m_C;
	int m_D;
};

// Параллелограмм
class Parallelogram : public Quadrangle
{
public:
	Parallelogram(const std::wstring & nm = L"Параллелограмм", int sides = 4, int a = 20, int b = 30, int A = 30, int B = 40);
};

// Прямоугольник
class Rectangle : public Parallelogram
{
public:
	Rectangle(const std::wstring & nm = L"Прямоугольник", int sides = 4, int a = 10, const int b = 20, int A = 90);
};

// Квадрат
class Square : public Rectangle
{
public:
	Square(const std::wstring & nm = L"Квадрат", int sides = 4, int a = 20, int A = 90);
};

// Ромб
class Rhombus : public Parallelogram
{
public:
	Rhombus(const std::wstring & nm = L"Ромб", int sides = 4, int a = 30, int A = 30, int B = 40);
};