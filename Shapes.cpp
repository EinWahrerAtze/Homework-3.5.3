#include "Shapes.h"

// Фигура
void Figure::print()
{
	std::wcout << name << ":\n";
	std::wcout << (check() ? L"Правильная.\n" : L"Неправильная.\n");
	std::wcout << L"Количество сторон: ";
	print_sides();
	print_angles();
}

void Figure::print_sides() const
{
	std::wcout << L"0.\n";
}

void Figure::print_angles() const { }

bool Figure::check() const
{
	return true;
}

Figure::Figure(const std::wstring & nm) : name(nm) { }

Figure::~Figure() { }

// Треугольник
Triangle::Triangle(const std::wstring & nm, int sides, int a, int b, int c, int A, int B, int C) : Figure(nm)
{
	m_sides = sides;
	m_a = a;
	m_b = b;
	m_c = c;
	m_A = A;
	m_B = B;
	m_C = C;
}

void Triangle::print_sides() const
{
	std::wcout << m_sides << L".\n";
	std::wcout << L"Стороны: a = " << m_a << L", b = " << m_b << L", c = " << m_c << L".\n";
}

void Triangle::print_angles() const
{
	std::wcout << L"Углы: A = " << m_A << L"°, B = " << m_B << L"°, C = " << m_C << L"°.\n";
}

bool Triangle::check() const
{
	if (m_sides == 3 && m_A + m_B + m_C == 180)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Прямоугольный треугольник
Right_triangle::Right_triangle(const std::wstring & nm, int sides, int a, int b, int c, int A, int B) : Triangle(nm, sides, a, b, c, A, B, 90) { }

// Неправильный прямоугольный треугольник
Wrong_right_triangle::Wrong_right_triangle(const std::wstring & nm, int sides, int a, int b, int c, int A, int B) : Triangle(nm, sides, a, b, c, A, B, 90) { }

// Равнобедренный треугольник
Isosceles_triangle::Isosceles_triangle(const std::wstring & nm, int sides, int a, int b, int A, int B) : Triangle(nm, sides, a, b, a, A, B, A) { }

// Равносторонний треугольник
Equilateral_triangle::Equilateral_triangle(const std::wstring & nm, int sides, int a, int A) : Triangle(nm, sides, a, a, a, A, A, A) { }

// Четырёхугольник
Quadrangle::Quadrangle(const std::wstring & nm, int sides, int a, int b, int c, int d, int A, int B, int C, int D) : Figure(nm)
{
	m_sides = sides;
	m_a = a;
	m_b = b;
	m_c = c;
	m_d = d;
	m_A = A;
	m_B = B;
	m_C = C;
	m_D = D;
}

void Quadrangle::print_sides() const
{
	std::wcout << m_sides << L".\n";
	std::wcout << L"a = " << m_a << L", b = " << m_b << L", c = " << m_c << L", d = " << m_d << L".\n";
}

void Quadrangle::print_angles() const
{
	std::wcout << L"A = " << m_A << L"°, B = " << m_B << L"°, C = " << m_C << L"°, D = " << m_D << L"°.\n";
}

bool Quadrangle::check() const
{
	if (m_sides == 4 && m_A + m_B + m_C + m_D == 360)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Прямоугольник
Rectangle::Rectangle(const std::wstring & nm, int sides, int a, int b, int A) : Parallelogram(nm, sides, a, b, A, A) { }

// Квадрат
Square::Square(const std::wstring & nm, int sides, int a, int A) : Rectangle(nm, sides, a, a, A) { }

// Параллелограмм
Parallelogram::Parallelogram(const std::wstring & nm, int sides, int a, int b, int A, int B) : Quadrangle(nm, sides, a, b, a, b, A, B, A, B) { }

// Ромб
Rhombus::Rhombus(const std::wstring & nm, int sides, int a, int A, int B) : Parallelogram(nm, sides, a, a, A, B) { }