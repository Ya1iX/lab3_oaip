#define _CRT_SECURE_NO_WARNINGS

#include "Funcs.h"
#include "Classes.h"
#include <stdio.h>
#include <iostream>


using namespace std;

void ReadPointsFile(char* FN, Point* points)
{
	FILE* file;
	float coords[4];
	file = fopen(FN, "r");
	if (!file || feof(file))
	{
		cout << "File not found!" << endl;
		file = fopen(FN, "w");
		fclose(file);
		cout << "File " << FN << " was created! Please fill it." << endl << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < 4; i++)
	{
		fscanf(file, "%f", &coords[i]);
	}
	fclose(file);
	points[0].SetPoint(coords[0], coords[1]);
	points[1].SetPoint(coords[2], coords[3]);
}
void SaveResults(char* FN, Cube cb)
{
	FILE* file;
	file = fopen(FN, "w");
	fprintf(file, "Cube:\nSideCoords: A(%.1f, %.1f); B(%.1f, %.1f); C(%.1f, %.1f); D(%.1f, %.1f)\n", cb.GetA().GetX(), cb.GetA().GetY(), cb.GetB().GetX(), cb.GetB().GetY(), cb.GetC().GetX(), cb.GetC().GetY(), cb.GetD().GetX(), cb.GetD().GetY());
	fprintf(file, "CubeArea: %f\nCubeVolume: %f\n", cb.FindCubeArea(), cb.FindCubeVolume());
	cb.Rotate(90);
	fprintf(file, "SideCoords after 90 degree rotation: A(%.1f, %.1f); B(%.1f, %.1f); C(%.1f, %.1f); D(%.1f, %.1f)\n", cb.GetA().GetX(), cb.GetA().GetY(), cb.GetB().GetX(), cb.GetB().GetY(), cb.GetC().GetX(), cb.GetC().GetY(), cb.GetD().GetX(), cb.GetD().GetY());
	fclose(file);
}