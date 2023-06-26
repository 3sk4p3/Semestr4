#include "Section5.h"

int Section5::ReadToSection(size_t offset, std::vector<char>& I_Data)
{
	std::memcpy(&this->m_MoneyMaker[0], &I_Data[offset], 4);
	this->DisplaySection();
	return offset + 4;
}

void Section5::DisplaySection()
{
	std::cout << "~~~~~~~~~~~~SECTION5~~~~~~~~~~~~~\n";
	for (size_t i = 0; i < 4; ++i)
	{
		std::cout << m_MoneyMaker[i];
	}
	std::cout << std::endl;
}
