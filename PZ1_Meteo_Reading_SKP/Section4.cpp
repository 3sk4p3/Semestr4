#include "Section4.h"

int Section4::ReadToSection(size_t offset, std::vector<char>& I_Data)
{
	std::memcpy(&this->m_Length[0], &I_Data[offset], 14);
	this->DisplaySection();
	return offset + this->GetSize();
}
int Section4::GetSize()
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

void Section4::DisplaySection()
{
	std::cout << "~~~~~~~~~~~~~~SECTION4~~~~~~~~~~~~~~~\n";


	std::cout << "Flag info:\n";
	if (m_Flag[0] & 1)std::cout << "Spherical Harmonic Coefficients\n";
	else std::cout << "Grid Point Data\n";

	if ((m_Flag[0]>>1) & 1)std::cout << "Second order (\"Complex\") Packing\n";
	else std::cout << "Simple packing\n";

	if ((m_Flag[0] >>2)& 1)std::cout << "Original data were integer values\n";
	else std::cout << "Original data were floating point values\n";

	if ((m_Flag[0] >>3)& 1)std::cout << "Octet 14 contains flag bits 5 - 12\n";
	else std::cout << "No additional flags at octet 14\n";

	int sign = m_ReferenceValue[0] & 128?1:0;
	m_ReferenceValue[0] = m_ReferenceValue[0] &127 ;
	uint8_t exp = uint8_t(m_ReferenceValue[0]);
	float mantis = 0;
	mantis = m_ReferenceValue[1] << 16 | m_ReferenceValue[2] << 8 | m_ReferenceValue[3] ;
	exp =  m_ReferenceValue[0] ;
 	std::cout << "floating point number:" << std::pow(-1.0f, sign)*-1 * std::pow(2,-24) *mantis* std::pow(16,exp-64) << std::endl;

}
