#pragma once
#include "Reader.h"


class Info_Header: public Reader
{
	friend class Pixel;

private:
	unsigned char Size[4];//trzeba spytac knura o wchar_t; little endian
	unsigned char Width[4];//szerokosc obrazka little endian
	unsigned char Height[4];//wysokosc obrazka little endian
	unsigned char Planes[2];//huj wie co to jest=1 little endian
	unsigned char BitCount[2];//toi jest wazne bo od tego zalezy istenienie tablicy kolorów, bpp<=8-->istenieje little endian
	unsigned char Compression[4];//huij wie jak to dziala
	unsigned char ImageSize[4];//(compressed)size of image jak compressionb jest0 to to tez moze byc 0.little endian
	unsigned char XpixelsperM[4];//rozdzialka w pixel/metr little endian
	unsigned char YpixelsperM[4];//rozdzialaka pixel/metr little endian
	unsigned char ColorUsed[4];//liczba kolorów. little endian
	unsigned char ColorsImportant[4];//Huj wie co to jest ile kolorow z palety jest uzywanych little endian
public:


	void InitializeHeader(Reader* _r);
	uint32_t GetColorUsed();
	uint32_t GetWidth();
	uint32_t GetHeight();


	Info_Header() {};
	~Info_Header() {};
	//virtual void InitializeClass();

};


