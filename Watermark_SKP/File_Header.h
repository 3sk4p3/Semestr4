#pragma once
#include "Reader.h"


class File_Header: public Reader
{
	friend class Pixel;
private:
	unsigned char signature[2];//"BM"bitmap
	unsigned char file_size[4];//rozmiar pliku w bajtach little endian
	unsigned char reserved[4];
	unsigned char data_offset[4];//gdzie sie zaczynaj¹ pixele w pliku little endian
public:
	friend size_t GetDataOffset(File_Header&fh);
	friend void Byte_reverse(unsigned char* _container, size_t cap);

	File_Header() {};
	~File_Header() {};
	
	 
	void InitializeHeader(Reader * _r);




};
size_t GetDataOffset(File_Header& fh);
