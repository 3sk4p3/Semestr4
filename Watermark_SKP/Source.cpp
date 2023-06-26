#include "Reader.h"
#include "Info_Header.h"
#include "File_Header.h"
#include "Shape_Gen.h"
#include "Pixel.h"
////musze zainicjalizowac tak vector jak chce zeby byl static
//std::vector<unsigned char>Reader::data;

int main()
{
	Reader r;
	r.ReadFile("lena.bmp");
	File_Header fh;
	Info_Header ih;
	


	//std::vector<int> numbers;
	//std::default_random_engine defEngine(time(0));
	//std::uniform_int_distribution<int> intDistro(0, 100);
	//for (int i = 1; i <= 20; i++) {
	//	numbers.push_back(intDistro(defEngine));
	//}
	//for (const int n : numbers) {
	//	std::cout << n << " ";
	//}

	fh.InitializeHeader(&r);
	ih.InitializeHeader(&r);


	Shape_Gen sg;
	sg.StealInfo(ih);
	sg.Generate();//generowanie losowych wartosci;
	//wstrzykuje to do pixela
	Pixel px(sg);
	//to da sie ladniejh w huj zrobicx
	px.SetIndex(GetDataOffset(fh));//ustalenie gdzie w data zaczynaja sie pixele.
	//zmieniam r->data
	px.Overwritedata(r);
	//zapisuje do nowego pliku.
	r.WriteFile("ANewLena.bmp");
	//fh.ReadFile("all_gray.bmp");

//	uint32_t le = 0x12345678;
//	uint32_t be = __builtin_bswap32(le);






















	/*struct chunk
	{
		uint8_t size[4];
		uint8_t chunk_type[4];
	};
	const char* path = "PNG_random.png";
	const char* path_2 = "PNG_random_with_opacity.png";
	std::fstream image;	
	std::fstream image_2;	
	image.open(path, std::ios::in | std::ios::binary | std::ios::ate);
	image_2.open(path_2, std::ios::out | std::ios::binary );
	if (!image.is_open())
	{
		std::cerr << "error";
		return false;
	}
	if (!image_2.is_open())
	{
		std::cerr << "error_2";
		return false;
	}
	std::ifstream::pos_type FileSize = image.tellg();
	if (FileSize < 0)
	{
		image.close();
		return false;
	}

	
	image.seekg(0, std::ios::beg);
	std::vector< char>data;
	data = std::vector<char>(FileSize);
	image.read(&data[0], FileSize);

	




	if (data[0] == -119&& data[1] == 80&& data[2] == 78&& data[3] == 71&& data[4] ==13&& data[5] == 10&& data[6] == 26&& data[7] == 10)
	{
		for (size_t i = 0; i <8; ++i)
		{
			std::cout << (int)data[i] << std::endl;
		}

	}
	image.close();
	image_2.close();
*/



	//PPM image blender

	//std::ifstream image;
	//std::ifstream image_3;
	//std::ofstream image_2;

	//image.open("image_7.ppm");
	//image_3.open("image_4_transparent.ppm");//wiekszy
	//image_2.open("image_8_mod4.ppm");
	//std::string type = "", width = "", height = "", RGB = "";
	//image_3 >> type;
	//image_3 >> width;
	//image_3 >> height;
	//image_3 >> RGB;
	//image_2 << type << std::endl;
	//image_2 << width<<" " <<height<< std::endl;
	//image_2 << RGB<<std::endl;
	//image >> type;
	//image >> width;
	//image >> height;
	//image >> RGB;
	//std::string red = "", green = "", blue = "";
	//std::string red2 = "", green2 = "", blue2 = "";
	//int r = 0, g = 0, b = 0;
	//int counter = 0;
	//int r1 = 0, g1 = 0, b1 = 0;
	//while (!image_3.eof())
	//{
	//	bool toggler = false;
	//	image_3 >> red;
	//	image_3 >> green;
	//	image_3 >> blue;

	//	std::stringstream redstream(red);
	//	std::stringstream greenstream(green);
	//	std::stringstream bluestream(blue);

	//	redstream >> r;
	//	greenstream >> g;
	//	bluestream >> b;

	//	if (!image.eof())
	//	{
	//		image >> red2;
	//		image >> green2;
	//		image >> blue2;
	//		std::stringstream redstream2(red);
	//		std::stringstream greenstream2(green2);
	//		std::stringstream bluestream2(blue2);


	//		redstream2 >> r1;
	//		greenstream2 >> g1;
	//		bluestream2 >> b1;


	//		if (counter % 4 == 0)
	//		{
	//			toggler = true;
	//			image_2 << r1 << " " << g1 << " " << b1 << std::endl;
	//		}
	//		

	//	}
	//	
	//	if (toggler==false)
	//	{
	//		image_2 << r << " " << g << " " << b << std::endl;
	//	}
	//	
	//	
	//	++counter;
	//}
	//image.close();
	//image_2.close();
	//image_3.close();

	// PPM image maker
//std::ofstream image;
//image.open("image_7.ppm");
//image << "P3" << std::endl;
//image << "125 125" << std::endl;
//image << "255" << std::endl;
//for (int x = 0; x < 125; ++x)
//{
//	for (int y = 0; y < 125; ++y)
//	{
//		image << (x + y) % 255 << " " << x * y % 255 <<" " << x << std::endl;
//	}
//}
	return 0;
}