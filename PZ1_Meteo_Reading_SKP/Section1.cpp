#include "Section1.h"

int Section1::ReadToSection(size_t offset, std::vector<char>& I_Data)
{
    std::memcpy(&this->m_Length[0], &I_Data[offset], 28);
	this->DisplaySection();
	return offset + this->GetSize();
}

int Section1::GetSize()
{
	char bufsize[4];
	bufsize[0] = 0;
	for (size_t i = 1; i < 4; ++i)
	{
		bufsize[i] = m_Length[i - 1];
	}

	ReverseBytes(4, bufsize);
	//tutaj sa 4 techniki do odczytania rozmiarow, kazda oczywsicie jest poprawna.
	m_Size=*reinterpret_cast<int32_t const*>(&bufsize[0]);
	return m_Size;
	//return static_cast<int32_t >(bufsize[0]);
	//return (static_cast<int32_t>(bufsize[0])) | 
	//	(static_cast<int32_t>	(bufsize[1]) << 8) |
	//	(static_cast<int32_t>	(bufsize[2]) << 16) |
	//	(static_cast<int32_t>	(bufsize[3]) << 24);
	//int* buf4 = (int*)bufsize;
	//return *buf4;*/
}

void Section1::DisplaySection()
{	
	std::cout << "`````````````````SECTION1``````````````" << std::endl;
	std::cout << "Size:" << this->GetSize()<<std::endl;
	this->DisplayDate();
	this->DisplayFlagInfo();
}

void Section1::DisplayDate()
{


	std::cout << "Date:"<<"20" << static_cast<int32_t>(m_YearofCentury[0]) << "." << static_cast<int32_t>(m_MonthOfYear[0])
		<< "." << static_cast<int32_t>(m_DayofMonth[0]) << " " << static_cast<int32_t>(m_HourOfDay[0])
		<< ":" << static_cast<int32_t>(m_MinuteOfHour[0]) << std::endl;

	
}

void Section1::DisplayFlagInfo()
{
	int8_t buffer = static_cast<int8_t>(m_GDSorBMSFlag[0]);
	uint8_t buf = static_cast<uint8_t>((m_GDSorBMSFlag[0] >> 6 & 1));
	int hf = buf;
	 buf+= static_cast<int8_t>(( m_GDSorBMSFlag[0]>>7&1));

	if (buf == 0)std::cout << "GDS omitted& BMS omitted" << std::endl;
	else if (buf == 1&&hf==0)std::cout << "GDS Included& BMS omitted" << std::endl;
	else if (buf == 1&&hf==1)std::cout << "GDS omitted& BMS Included" << std::endl;
	else if (buf == 2)std::cout << "GDS Included& BMS Included" << std::endl;
	else std::cout << "Flag was set incorectly" << std::endl;

}

