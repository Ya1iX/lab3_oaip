/*
	Куб.
	Разработать параметрический конструктор. 
	Разработать методы: вычисления площади пверхности фигуры; вычисления объёма фигуры; поворота фигуры на заданный угол относительно начала координат.
*/

#include <iostream>
#include <cmath>
#include "Classes.h"
#include "Funcs.h"

int main()
{
	char in[] = "Points.txt";
	char out[] = "Result.txt";
	Point pnts[2];
	
	ReadPointsFile(in, pnts);
	Cube cb(pnts[0], pnts[1]);
	
	printf("Cube:\nSideCoords: A(%.1f, %.1f); B(%.1f, %.1f); C(%.1f, %.1f); D(%.1f, %.1f)\n", cb.GetA().GetX(), cb.GetA().GetY(), cb.GetB().GetX(), cb.GetB().GetY(), cb.GetC().GetX(), cb.GetC().GetY(), cb.GetD().GetX(), cb.GetD().GetY());
	printf("CubeArea: %f\nCubeVolume: %f\n", cb.FindCubeArea(), cb.FindCubeVolume());
	
	cb.Rotate(90);
	printf("Coords after 90 degree rotation: A(%.1f, %.1f); B(%.1f, %.1f); C(%.1f, %.1f); D(%.1f, %.1f)\n", cb.GetA().GetX(), cb.GetA().GetY(), cb.GetB().GetX(), cb.GetB().GetY(), cb.GetC().GetX(), cb.GetC().GetY(), cb.GetD().GetX(), cb.GetD().GetY());
	
	SaveResults(out, cb);
	
	printf("\nResult was saved in file!\n");
	system("pause");
}
