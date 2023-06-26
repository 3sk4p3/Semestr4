#include "Reader.h"
//1stwczytanie tak jak w pamieci, potem odworcenie.

bool Reader::ReadFile(const char* file_name)
{
	
		std::fstream File;
		File.open(file_name, std::ios::in | std::ios::binary | std::ios::ate);
		if (!File.is_open())return false;

		//chyyyyyyyyyba nie potrzebuje wiedziec teraz calej dlugosci??
		std::ifstream::pos_type FileSize = File.tellg();

		File.seekg(0, std::ios::beg);

		data = std::vector<unsigned char>(FileSize);
		File.read((char*)&data[0], FileSize);
		File.close();
		return true;
}

bool Reader::WriteFile(const char* file_name)
{
	std::fstream File(file_name, std::ios::out | std::ios::binary);
	//
	if (!File.is_open())
	{
		std::cerr << "error";
		return false;
	}

	
		File.write(reinterpret_cast< char*> ( & data[0]), data.size());
		

	
	return true;
	File.close();
}





//uint32_t Hex_Arr_To_Int(unsigned char* arr)
//{
//	return uint32_t();
//}

void Byte_reverse(unsigned char* _container, size_t cap)
{
	for (size_t i = 0; i < cap / 2; ++i)
	{
		unsigned char buf = _container[i];
		_container[i] = _container[cap - i - 1];
		_container[cap - i - 1] = buf;
	}

}

uint32_t Hex_Arr_To_Int(unsigned char* arr)
{
	
		uint32_t mycastint = (arr[0] << 24) | (arr[1] << 16) | (arr[2] << 8) | (arr[3]);
		return mycastint;

	
}
