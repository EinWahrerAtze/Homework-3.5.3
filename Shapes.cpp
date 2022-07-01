#include "Shapes.h"

// Фигура
Figure::Figure(const std::wstring & nm, const int sides) : m_name(nm), m_sides(sides)
{
}

bool Figure::check() const
{
	if (m_sides == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Figure::print_info() const
{
	std::wcout << m_name << std::endl;
	std::wcout << (check() ? L"Правильная\n" : L"Неправильная\n");
	std::wcout << L"Количество сторон: " << m_sides << std::endl;
}

Figure::~Figure()
{
}

// Равносторонний треугольник
Equilateral_triangle::Equilateral_triangle(const std::wstring & nm, const int sides, const int a, const int A) : Figure(nm, sides)
{
	m_a = a;
	m_A = A;
}

bool Equilateral_triangle::check() const
{
	if (m_sides == 3 && m_A * 3 == 180)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Equilateral_triangle::print_info() const
{
	Figure::print_info();
	std::wcout << L"Стороны: a = " << m_a << L", b = " << m_a << L", c = " << m_a << std::endl;
	std::wcout << L"Углы: A = " << m_A << L"°, B = " << m_A << L"°, C = " << m_A << L"°\n";
}

// Равнобедренный треугольник
Isosceles_triangle::Isosceles_triangle(const std::wstring & nm, const int sides, const int a, const int b, const int A,
									   const int B) : Equilateral_triangle(nm, sides, a, A)
{
	m_b = b;
	m_B = B;
}

bool Isosceles_triangle::check() const
{
	if (m_sides == 3 && m_A * 2 + m_B == 180)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Isosceles_triangle::print_info() const
{
	Figure::print_info();
	std::wcout << L"Стороны: a = " << m_a << L", b = " << m_b << L", c = " << m_a << std::endl;
	std::wcout << L"Углы: A = " << m_A << L"°, B = " << m_B << L"°, C = " << m_A << L"°\n";
}

// Треугольник
Triangle::Triangle(const std::wstring & nm, const int sides, const int a, const int b, const int c,
				   const int A, const int B, const int C) : Isosceles_triangle(nm, sides, a, b, A, B)
{
	m_c = c;
	m_C = C;
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

void Triangle::print_info() const
{
	Figure::print_info();
	std::wcout << L"Стороны: a = " << m_a << L", b = " << m_b << L", c = " << m_c << std::endl;
	std::wcout << L"Углы: A = " << m_A << L"°, B = " << m_B << L"°, C = " << m_C << L"°\n";
}

// Правильный прямоугольный треугольник
Right_triangle::Right_triangle(const std::wstring & nm, const int sides, const int a, const int b, const int c,
							   const int A, const int B) : Triangle(nm, sides, a, b, c, A, B, 90)
{
}

// Неправильный прямоугольный треугольник
Wrong_right_triangle::Wrong_right_triangle(const std::wstring & nm, const int sides, const int a, const int b, const int c,
										   const int A, const int B) : Triangle(nm, sides, a, b, c, A, B, 90)
{
}

// Квадрат
Square::Square(const std::wstring & nm, const int sides, const int a, const int A) : Equilateral_triangle(nm, sides, a, A)
{
}

bool Square::check() const
{
	if (m_sides == 4 && m_A * 4 == 360)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Square::print_info() const
{
	Figure::print_info();
	std::wcout << L"Стороны: a = " << m_a << L", b = " << m_a << L", c = " << m_a << L", d = " << m_a << std::endl;
	std::wcout << L"Углы: A = " << m_A << L"°, B = " << m_A << L"°, C = " << m_A << L"°, D = " << m_A << L"°\n";
}

// Ромб
Rhombus::Rhombus(const std::wstring & nm, const int sides, const int a, const int A, const int B) : Square(nm, sides, a, A)
{
	m_B = B;
}

bool Rhombus::check() const
{
	if (m_sides == 4 && m_A * 2 + m_B * 2 == 360)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Rhombus::print_info() const
{
	Figure::print_info();
	std::wcout << L"Стороны: a = " << m_a << L", b = " << m_a << L", c = " << m_a << L", d = " << m_a << std::endl;
	std::wcout << L"Углы: A = " << m_A << L"°, B = " << m_B << L"°, C = " << m_A << L"°, D = " << m_B << L"°\n";
}

// Параллелограмм
Parallelogram::Parallelogram(const std::wstring & nm, const int sides, const int a, const int b, const int A,
							 const int B) : Isosceles_triangle(nm, sides, a, b, A, B)
{
}
bool Parallelogram::check() const
{
	if (m_sides == 4 && m_A * 2 + m_B * 2 == 360)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Parallelogram::print_info() const
{
	Figure::print_info();
	std::wcout << L"Стороны: a = " << m_a << L", b = " << m_b << L", c = " << m_a << L", d = " << m_b << std::endl;
	std::wcout << L"Углы: A = " << m_A << L"°, B = " << m_B << L"°, C = " << m_A << L"°, D = " << m_B << L"°\n";
}

// Прямоугольник
Rectangle::Rectangle(const std::wstring & nm, const int sides, const int a, const int b, const int A) : Square(nm, sides, a, A)
{
	m_b = b;
}

bool Rectangle::check() const
{
	if (m_sides == 4 && m_A * 4 == 360)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Rectangle::print_info() const
{
	Figure::print_info();
	std::wcout << L"Стороны: a = " << m_a << L", b = " << m_b << L", c = " << m_a << L", d = " << m_b << std::endl;
	std::wcout << L"Углы: A = " << m_A << L"°, B = " << m_A << L"°, C = " << m_A << L"°, D = " << m_A << L"°\n";
}

// Четырёхугольник
Quadrangle::Quadrangle(const std::wstring & nm, const int sides, const int a, const int b, const int c, const int d,
					   const int A, const int B, const int C, const int D) : Triangle(nm, sides, a, b, c, A, B, C)
{
	m_d = d;
	m_D = D;
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

void Quadrangle::print_info() const
{
	Figure::print_info();
	std::wcout << L"Стороны: a = " << m_a << L", b = " << m_b << L", c = " << m_c << L", d = " << m_d << std::endl;
	std::wcout << L"Углы: A = " << m_A << L"°, B = " << m_B << L"°, C = " << m_C << L"°, D = " << m_D << L"°\n";
}