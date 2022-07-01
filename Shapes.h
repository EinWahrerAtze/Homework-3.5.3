#pragma once
#include <iostream>
#include <string>

// Фигура
class Figure
{
public:
	Figure(const std::wstring & nm = L"Фигура", const int sides = 0);
	virtual bool check() const;
	virtual void print_info() const;
	virtual ~Figure();
protected:
	std::wstring m_name;
	int m_sides;
};

// Равносторонний треугольник
class Equilateral_triangle : public Figure
{
public:
	Equilateral_triangle(const std::wstring & nm = L"Равносторонний треугольник", const int sides = 3, const int a = 30, const int A = 60);
	bool check() const override;
	void print_info() const override;
protected:
	int m_a;
	int m_A;
};

// Равнобедренный треугольник
class Isosceles_triangle : public Equilateral_triangle
{
public:
	Isosceles_triangle(const std::wstring & nm = L"Равнобедренный треугольник", const int sides = 3, const int a = 10,
					   const int b = 20, const int A = 50, const int B = 60);
	bool check() const override;
	void print_info() const override;
protected:
	int m_b;
	int m_B;
};

// Треугольник
class Triangle : public Isosceles_triangle
{
public:
	Triangle(const std::wstring & nm = L"Треугольник", const int sides = 3, const int a = 10, const int b = 20,
			 const int c = 30, const int A = 50, const int B = 60, const int C = 70);
	bool check() const override;
	void print_info() const override;
protected:
	std::wstring m_name;
	int m_c;
	int m_C;
};

// Правильный прямоугольный треугольник
class Right_triangle : public Triangle
{
public:
	Right_triangle(const std::wstring & nm = L"Прямоугольный треугольник", const int sides = 3, const int a = 10,
				   const int b = 20, const int c = 30, const int A = 50, const int B = 40);
};

// Неправильный прямоугольный треугольник
class Wrong_right_triangle : public Triangle
{
public:
	Wrong_right_triangle(const std::wstring & nm = L"Прямоугольный треугольник", const int sides = 3, const int a = 10,
				   const int b = 20, const int c = 30, const int A = 50, const int B = 60);
};

// Квадрат
class Square : public Equilateral_triangle
{
public:
	Square(const std::wstring & nm = L"Квадрат", const int sides = 4, const int a = 20, const int A = 90);
	bool check() const override;
	void print_info() const override;
};

// Ромб
class Rhombus : public Square
{
public:
	Rhombus(const std::wstring & nm = L"Ромб", const int sides = 4, const int a = 30, const int A = 30, const int B = 40);
	bool check() const override;
	void print_info() const override;
private:
	int m_B;
};

// Параллелограмм
class Parallelogram : public Isosceles_triangle
{
public:
	Parallelogram(const std::wstring & nm = L"Параллелограмм", const int sides = 4, const int a = 20,
				  const int b = 30, const int A = 30, const int B = 40);
	bool check() const override;
	void print_info() const override;
};

// Прямоугольник
class Rectangle : public Square
{
public:
	Rectangle(const std::wstring & nm = L"Прямоугольник", const int sides = 4, const int a = 10, const int b = 20, const int A = 90);
	bool check() const override;
	void print_info() const override;
private:
	int m_b;
};

// Четырёхугольник
class Quadrangle : public Triangle
{
public:
	Quadrangle(const std::wstring & nm = L"Четырёхугольник", const int sides = 4, const int a = 10, const int b = 20, const int с = 30,
			   const int d = 40, const int A = 50, const int B = 60, const int C = 70, const int D = 80);
	bool check() const override;
	void print_info() const override;
private:
	int m_d;
	int m_D;
};