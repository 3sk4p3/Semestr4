#include "Section0.h"



int Section0::ReadToSection(size_t offset, std::vector<char>& I_Data)
{
	const char* crlf2 = "GRIB";
	auto it = std::search(I_Data.begin() + offset, I_Data.end(), crlf2, crlf2 + 4);
	if (it != I_Data.end())
	{
		int where_at = it - I_Data.begin();
		std::cout << "``````````````````SECTION0```````````````````\n";
		std::cout << "GRIB at" << where_at << std::endl;
		std::memcpy(&this->m_Header[0], &I_Data[where_at], 8);	
		std::cout << "version:" << static_cast<int>(m_Edition[0]) << std::endl;
	
		return where_at+8;
	}
	return -1;
}

int Section0::GetSize()
{
	char bufsize[4];
	bufsize[0] = 0;
	for (size_t i = 1; i < 4; ++i)
	{
		bufsize[i] = m_Length[i - 1];
	}

	ReverseBytes(4, bufsize);

	int* buf4 = (int*)bufsize;
	m_Size = *buf4;
	return m_Size;
}

void Section0::DisplaySection()
{

}
