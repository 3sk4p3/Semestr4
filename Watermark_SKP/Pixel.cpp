#include "Pixel.h"

void Pixel::Overwritedata(Reader& _r)
{
	DrawShape(_r);

}


//trzeba dodac losowo generowany argument, i zrobc switcha dla kwadratu/trojkata
void Pixel::DrawShape(Reader& _r)
{
	Shape = 1;
	std::cout << "Shape: " << Shape << std::endl;
	switch (Shape)
	{

		//kwadrat
	case 0:

	{
		{unsigned int c_x = Rando_Num(Width);
		unsigned int Thickness = Rando_Num(10);
		//gwarancja ze bedzie mniejszy.
		unsigned int d_x = Rando_Num(c_x);
		unsigned int BottomY = Rando_Num(Height);
		unsigned int a_c_len = Rando_Num(Height - BottomY);
		unsigned int c_d_len = c_x - d_x;


		std::cout << "c_X: " << c_x << std::endl;
		std::cout << "d_X: " << d_x << std::endl;
		std::cout << "BottomY: " << BottomY << std::endl;
		std::cout << "a_c_len: " << a_c_len << std::endl;
		std::cout << "c_d_len: " << c_d_len << std::endl;
		std::cout << "Thickneszs: " << Thickness << std::endl;


		for (int i = 0; i < a_c_len; ++i)
		{
			std::cout << "1st i: " << i << std::endl;
			for (size_t k = 0; k < Thickness; ++k)
			{
				//lewy mozliwe ze trzeba zamienic k.
		//_r.data[index + BottomY * Height + i * Height - k + c_x]= (unsigned char)(((unsigned int)_r.data[index + BottomY * Height + i * Height - k + c_x] + 10) % Max_Color);
				_r.data[index + BottomY * Height + i * Height - k + c_x] = _r.data[index + BottomY * Height + i * Height - k + c_x] + 10;
				//prawy mozeliwe ze trzeba zamienic k.
				//_r.data[index + BottomY * Height +i*Height+k+d_x] = Color[0];
			//	_r.data[index + BottomY * Height + i * Height + k + d_x] = (unsigned char)(((unsigned int)_r.data[index + BottomY * Height + i * Height + k + d_x] + 10) % Max_Color);
				_r.data[index + BottomY * Height + i * Height + k + d_x] = _r.data[index + BottomY * Height + i * Height + k + d_x] + 10;
			}
		}
		for (size_t i = 0; i < c_d_len; ++i)
		{
			std::cout << "2nd i: " << i << std::endl;
			for (size_t k = 0; k < Thickness; ++k)
			{
				//dol to sie moze wyjebac jak BottomY<10
				//_r.data[index +	BottomY*Height+d_x+k*Height+i] = Color[0];
				//_r.data[index +	BottomY*Height+d_x+k*Height+i]=(unsigned char)(((unsigned int)_r.data[index + BottomY * Height + d_x + k * Height + i] + 10) % Max_Color);
				_r.data[index + BottomY * Height + d_x + k * Height + i] = _r.data[index + BottomY * Height + d_x + k * Height + i] + 10;

				//gora
				//_r.data[index +	BottomY*Height+a_c_len*Height+d_x-k*Height+i] = Color[0];
				//_r.data[index +	BottomY*Height+a_c_len*Height+d_x-k*Height+i] = (unsigned char)(((unsigned int)_r.data[index + BottomY * Height + a_c_len * Height + d_x - k * Height + i] + 10) % Max_Color);
				_r.data[index + BottomY * Height + a_c_len * Height + d_x - k * Height + i] = _r.data[index + BottomY * Height + a_c_len * Height + d_x - k * Height + i] + 10;
			}



































			/*ANIMAL EDITION:*/
			//int PosX = Rando_Num(Height);
			////grubosc
			//int Thickness = Rando_Num(10);
			//int Ybeg = Rando_Num(Width);
			//int Xdiff = Rando_Num(Width);
			//int div = Rando_Num(Width);
			//int mul = Rando_Num(div);
			//int randoHeight = Rando_Num(Height);
			//int Ydiff = Rando_Num(randoHeight);
			//bool visited = false;
			////zaczynamy w losowym miejscu ale tak samo od gory jak od dolu
			//std::cout << "posx: " << PosX << std::endl;
			//std::cout << "XDIFF: " << Xdiff << std::endl;
			//std::cout << "Ydiff: " << Ydiff << std::endl;
			//std::cout << "mul: " << mul << std::endl;
			//std::cout << "div: " << div << std::endl;
			//std::cout << "random hieght: " << randoHeight << std::endl;
			//std::cout << "data.size(): " << _r.data.size() << std::endl;
			////i<_r.data.size() - (PosX+Ydiff*Height)
			//for (size_t i = (index + PosX + Ydiff * Height); i < index + randoHeight * Height; i += Height)
			//{
			//	for (int k = 0; k < Thickness; ++k)
			//	{
			//		_r.data[i + Xdiff / div + k] = Color[0];
			//		_r.data[i + (Xdiff * mul) / div - k] = Color[0];

			//	}
			//	if (i == index + PosX + Ydiff * Height || i > (index + randoHeight * Height) - Height)
			//	{

			//		if (visited == false)
			//		{
			//			visited = true;
			//			for (size_t j = i + Xdiff / div; j < i + (Xdiff * mul) / div; ++j)
			//			{

			//				for (int k = 0; k <= Thickness; ++k)
			//				{
			//					_r.data[j + k * Height] = Color[0];
			//				}

			//			}

			//		}
			//		else
			//			for (size_t j = i + Xdiff / div; j < i + (Xdiff * mul) / div; ++j)
			//			{

			//				for (int k = 0; k < Thickness; ++k)
			//				{
			//					_r.data[j - k * Height] = Color[0];
			//				}
			//			}
			//	}

			//	std::cout << "i: " << i << std::endl;
		}
		}
		break;
		//trojkat
	case 1:
	{
		//moze to bedzie latwiej zrobic jak trojkat bedzie wypelniony?
		unsigned int Thickness = Rando_Num(10);
		unsigned int c_y = Rando_Num(Height);
		unsigned int c_x = Rando_Num(Width);
		//b_x mniejsze od c_x
		unsigned int b_x = Rando_Num(c_x - 1);
		unsigned int a_c_len = c_x - b_x;

		//dlugosc podstawy musi byc krotsza niz odleglosc od punktu c do konca obrazu.
		while (Height - a_c_len - Thickness <= 0)
		{
			c_y = Rando_Num(Height);
			c_x = Rando_Num(Width);
			b_x = Rando_Num(c_x - 1);

		}
		//bardziej chodzi o dlugosc niz pozycje w tym przypadku.
		std::cout << "a_c_len: " << a_c_len << std::endl;
		std::cout << "b_x: " << b_x << std::endl;
		std::cout << "c_x: " << c_x << std::endl;
		std::cout << "c_y: " << c_y << std::endl;

		for (size_t i = 0; i < a_c_len; ++i)
		{

			std::cout << "i: " << i << std::endl;
			for (size_t k = 0; k < Thickness; ++k)

			{

				//_r.data[index + Height * c_y + i + b_x + k * Height] = Color[0];
				_r.data[index + Height * c_y + i + b_x + k * Height] = _r.data[index + Height * c_y + i + b_x + k * Height] + 10;


			//	_r.data[index + c_y * Height + i * Height + k + b_x] = Color[0];
				_r.data[index + c_y * Height + i * Height + k + b_x] = _r.data[index + c_y * Height + i * Height + k + b_x]+10;



				_r.data[index + c_y * Height + c_x + i * Height - i + k * Height] = _r.data[index + c_y * Height + c_x + i * Height - i + k * Height]+10;
				//_r.data[index + c_y * Height + c_x + i * Height - i + k * Height] = Color[0];
				_r.data[index + c_y * Height + c_x + i * Height - i + k] = _r.data[index + c_y * Height + c_x + i * Height - i + k] +10;
			//	_r.data[index + c_y * Height + c_x + i * Height - i + k] = Color[0];
			}
		}
		//for (size_t j = 0; j < a_c_len; ++j)
		//{
		//	std::cout << "2nd j:" << j << std::endl;

		//	for (size_t k = 0; k < Thickness; ++k)
		//	{
		//		


		//	}
		//}
		//schodki/przeciwprostokatna
		//for (size_t i = 0; i < a_c_len; ++i)
		//{
		//	std::cout << "3rd i: " << i << std::endl;



		//	
		//}

	}
	break;






	}
	}
}
