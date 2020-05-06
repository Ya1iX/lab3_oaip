#include "Classes.h"
#include <cmath>
#include <iostream>

const double PI = 4 * atan(1);

Point::Point()
{
	x = y = 0;
}
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}
void Point::SetPoint(double x, double y)
{
	this->x = x;
	this->y = y;
}
double Point::GetX()
{
	return x;
}
double Point::GetY()
{
	return y;
}



Square::Square() {}
Square::Square(Point a, Point c) //����������� �������� � ��������� �������
{
	this->a = a;
	this->c = c;
	b.SetPoint(a.GetX(), c.GetY());
	d.SetPoint(c.GetX(), a.GetY());
	side = c.GetX() - a.GetX() + 1;
}
Square::Square(Point a, double side) //����������� �������� � �������� ������ � ������ �������
{
	if (side >= 0)
	{
		this->a = a;
		c.SetPoint(a.GetX() + side - 1, a.GetY() + side - 1);
		b.SetPoint(a.GetX(), c.GetY());
		d.SetPoint(c.GetX(), a.GetY());
		this->side = c.GetX() - this->a.GetX() + 1; //�� ���� ������ this->side = side �� ������ ������, ����� ������ ������������ ����� ������������ � ������ � ������ ��������� ����
	}
}
void Square::SetSquare(Point a, Point c)
{
	this->a = a;
	this->c = c;
}
Point Square::GetA()
{
	return a;
}
Point Square::GetB()
{
	return b;
}
Point Square::GetC()
{
	return c;
}
Point Square::GetD()
{
	return d;
}
double Square::GetSide()
{
	return side;
}
double Square::FindSquareArea()
{
	return pow(side, 2);
}
double Square::FindSquarePerimeter()
{
	return side * 4;
}
void Square::Rotate(double alpha)
{
	a.SetPoint((a.GetX() * cos(alpha * (PI / 180)) - a.GetY() * sin(alpha * (PI / 180))), (a.GetX() * sin(alpha * (PI / 180)) + a.GetY() * cos(alpha * (PI / 180))));
	b.SetPoint((b.GetX() * cos(alpha * (PI / 180)) - b.GetY() * sin(alpha * (PI / 180))), (b.GetX() * sin(alpha * (PI / 180)) + b.GetY() * cos(alpha * (PI / 180))));
	c.SetPoint((c.GetX() * cos(alpha * (PI / 180)) - c.GetY() * sin(alpha * (PI / 180))), (c.GetX() * sin(alpha * (PI / 180)) + c.GetY() * cos(alpha * (PI / 180))));
	d.SetPoint((d.GetX() * cos(alpha * (PI / 180)) - d.GetY() * sin(alpha * (PI / 180))), (d.GetX() * sin(alpha * (PI / 180)) + d.GetY() * cos(alpha * (PI / 180))));
}

Cube::Cube() {}
Cube::Cube(Point a, Point c) : Square(a, c) {}
Cube::Cube(Point a, double side) : Square(a, side) {}
void Cube::SetCube(Point a, Point c)
{
	SetSquare(a, c);
}
double Cube::FindCubeArea()
{
	return FindSquareArea() * 6;
}
double Cube::FindCubeVolume()
{
	return GetSide() * FindSquareArea();
}