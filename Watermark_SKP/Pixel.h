#pragma once
#include "Color.h"
#include "Reader.h"
#include "File_Header.h"
#include "Shape_Gen.h"

class Pixel: public Shape_Gen
{
	
private:
	size_t index;
	

public:
	Pixel(Shape_Gen& sg)
	{
		Color[0] = sg.Color[0];
		Shape = sg.Shape;
		Width = sg.Width;
		Height = sg.Height;
		Max_Color = sg.Max_Color;

	}
	//giga hujowo zrobione imo
	void SetIndex(size_t _index) {//w ktorym miejscu zaczynaja sie pixele.
		index = _index;
		std::cout << "Pixel index: " << index<<std::endl;
	}
	void DrawShape(Reader& _r);
	void Overwritedata(Reader& _r);//to ma zapisywac zmienione pixele spowrotem do data
	Pixel() {};
	~Pixel() {};
};

