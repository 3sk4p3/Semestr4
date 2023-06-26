#pragma once
#include <fstream>
#include <vector>
#include <iostream>
//extern const size_t InfoHeaderSize = 40;
//extern const size_t FileHeaderSize = 14;

class Reader
{
protected:
	
public:
	//w pewnych przypadkach oplaca sie dac static, ale na potrzebe tego programu wystarczyt to zapamietac.
 std::vector<unsigned char> data;
	Reader() {};
	~Reader() {};
	  bool ReadFile(const char* file_name);
	  bool WriteFile(const char* file_name);
	//virtual void InitializeClass()=0;


};
//uint32_t  Hex_Arr_To_Int(unsigned char* arr)
//{
//
//	uint32_t mycastint = (arr[0] << 24) | (arr[1] << 16) | (arr[2] << 8) | (arr[3]);
//	return mycastint;
//
//}
void Byte_reverse(unsigned char* _container, size_t cap);
uint32_t Hex_Arr_To_Int(unsigned char* arr);

