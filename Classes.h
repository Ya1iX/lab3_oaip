#pragma once

class Point
{
private:
	double x, y;
public:
	Point();
	Point(double x, double y);
	void SetPoint(double x, double y);
	double GetX();
	double GetY();
};

class Square
{
private:
	Point a, b, c, d;
	double side = 0;
public:
	Square();
	Square(Point a, Point c);
	Square(Point a, double side);
	void SetSquare(Point a, Point c);
	Point GetA();
	Point GetB();
	Point GetC();
	Point GetD();
	double GetSide();
	double FindSquareArea();
	double FindSquarePerimeter();
	void Rotate(double alpha);
};

class Cube : public Square
{
public:
	Cube();
	Cube(Point a, Point c);
	Cube(Point a, double side);
	void SetCube(Point a, Point c);
	double FindCubeArea();
	double FindCubeVolume();
};