#pragma once
#include "Reader.h"
#include <random>
#include <ctime>
#include "Info_Header.h"
#include "File_Header.h"
class Shape_Gen:public Reader
{
	friend class Info_Header;
	friend class File_Header;
	friend class Pixel;
private:
	unsigned char Color[1];
	unsigned int MarkWidth;
	unsigned int Shape;
	unsigned int Width;
	unsigned int Height;
	int Max_Color;

	

public:
	void SetColor();
	void SetShape();
	void SetWidth();
	void StealInfo(Info_Header& ih);
	void Generate();


};
int Rando_Num(int max);
