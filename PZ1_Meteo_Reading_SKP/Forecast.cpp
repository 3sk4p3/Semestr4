#include "Forecast.h"

 void Forecast::FillSection( size_t offset)
{
	// std::memcpy(&m_Section0->m_Header[0], &m_Data[offset-1], size);
	 //m_Section0->ReadToSection(offset,m_Data);
	  offset=m_Section5->ReadToSection( m_Section4->ReadToSection( m_Section2->ReadToSection(m_Section1->ReadToSection(m_Section0->ReadToSection(offset, m_Data), m_Data),m_Data),m_Data),m_Data) ;
	  std::cout << "offset:" << offset << std::endl;
	 SetSize();

	 std::cout << "Size:" << m_Size << std::endl;
	 
}

 void Forecast::SetSize()
 {
	 m_Size= m_Section0->GetSize();
 }

 Forecast::Forecast()
	 :m_Size(0)
 {
	 m_Section0 = new Section0();
	 m_Section1 = new Section1();
	 m_Section2 = new Section2();
	 m_Section4 = new Section4();
	 m_Section5 = new Section5();
 }

 void Forecast::LoadData(const char* I_Path)
 {
	 std::fstream File;
	 File.open(I_Path,std::fstream::in|std::fstream::binary);
	 if (File.is_open())
	 {
		 char buffer;
		 while (File.get(buffer))m_Data.push_back(buffer);
		


		 File.close();
	 }
	 else std::cout << "error reading the file" << std::endl;

 }

 void ReverseBytes(size_t I_Size, char* I_Data)
 {
	 for (size_t i = 0; i < I_Size/2; ++i)
	 {
		 char buf;
		 buf = I_Data[i];
		 I_Data[i] = I_Data[I_Size - i - 1];
		 I_Data[I_Size - i - 1] = buf;
	 }
 }
