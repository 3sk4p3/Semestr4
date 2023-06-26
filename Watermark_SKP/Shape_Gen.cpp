#include "Shape_Gen.h"




void Shape_Gen::SetColor()
{
	Color[0] = { (unsigned char)Rando_Num(Max_Color) };

}


void Shape_Gen::SetShape()
{
	Shape = (unsigned int)Rando_Num(1);
}

void Shape_Gen::SetWidth()
{
	MarkWidth = (unsigned int)Rando_Num(10);
}

void Shape_Gen::StealInfo(Info_Header& ih)
{

	Max_Color = ih.GetColorUsed();
	Width = ih.GetWidth();
	Height = ih.GetHeight();
	std::cout << "max kolor: " << Max_Color << std::endl;
	std::cout << "Width: " << Width << std::endl;
	std::cout << "Height: " << Height << std::endl;

}

void Shape_Gen::Generate()
{

	SetColor();
	SetWidth();
	SetShape();
	std::cout << Shape << std::endl;
	int castedint = (int)Color[0];
}

	

int Rando_Num(int max)
{
	std::random_device rd;
	std::mt19937 mt(rd());;
	//std::default_random_engine defEngine(time(0));
	std::uniform_int_distribution<int> intDistro(0,max );
	int result = intDistro(mt);
	return result;
}
