#include "Section2.h"



int Section2::ReadToSection(size_t offset, std::vector<char>& I_Data)
{
	std::memcpy(&this->m_Length[0], &I_Data[offset], 6);
	if (this->GetType() == 0)this->FillCoordinates(6 +offset, I_Data, 26);
	this->DisplaySection();

	return offset + this->GetSize();
			
}

int Section2::GetSize()
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

void Section2::DisplaySection()
{
	std::cout << "````````````````SECTION2````````````````````\n";
	std::cout << "Size:" << this->GetSize()<<std::endl;
	std::cout << "Data Representation type: "; 
	if (this->GetOffsetLocation() == 255)std::cout << "Neither PV location nor PL location is present.\n";
	else std::cout << "offset to the PV or PL location:" << this->GetOffsetLocation() << std::endl;
	std::cout << "NV, the number of vertical coordinate parameters:" << this->GetNoNV()<<std::endl;
	if (this->GetType() == 0) {
		Lat_Lon_GRID myLat;
		std::memcpy(&myLat.Ni_Lat[0], &m_PVorPL[0], 26);
		char buf = myLat.Ni_Lat[0];
		myLat.Ni_Lat[0] = myLat.Ni_Lat[1];
		myLat.Ni_Lat[1] = buf;
		 buf = myLat.Nj_Lon[0];
		myLat.Nj_Lon[0] = myLat.Nj_Lon[1];
		myLat.Nj_Lon[1] = buf;


		char bufsize1[4];
		bufsize1[0] = 0;
		int la1Sign = myLat.La1_First[0] & 128;
		myLat.La1_First[0] = char(int(myLat.La1_First[0]) & 127);
		for (size_t i = 1; i < 4; ++i)
		{
			bufsize1[i] = myLat.La1_First[i - 1];
		}
		ReverseBytes(4, bufsize1);
		int* buf4 = (int*)bufsize1;
		
		char bufsize2[4];
		bufsize2[0] = 0;

		int lo1Sign = myLat.Lo1_First[0] & 128;
		myLat.Lo1_First[0] = myLat.Lo1_First[0] & 127;

		for (size_t i = 1; i < 4; ++i)
		{
			bufsize2[i] = myLat.Lo1_First[i - 1];
		}
		ReverseBytes(4, bufsize2);
		int* buf5 = (int*)bufsize2;
		



		char bufsize3[4];
		bufsize3[0] = 0;
		int la2Sign = myLat.La2_Last[0] & 128;
		myLat.La2_Last[0] = char(int(myLat.La2_Last[0]) & 127);
		for (size_t i = 1; i < 4; ++i)
		{
			bufsize3[i] = myLat.La2_Last[i - 1];
		}
		ReverseBytes(4, bufsize3);
		int* buf6 = (int*)bufsize3;

		char bufsize4[4];
		bufsize4[0] = 0;

		int lo2Sign = myLat.Lo2_Last[0] & 128;
		myLat.Lo2_Last[0] = myLat.Lo2_Last[0] & 127;

		for (size_t i = 1; i < 4; ++i)
		{
			bufsize4[i] = myLat.Lo2_Last[i - 1];
		}
		ReverseBytes(4, bufsize4);
		int* buf7 = (int*)bufsize4;
		la1Sign= (la1Sign & 128) ? -1 : 1;
		lo1Sign=(lo1Sign & 128) ? -1 : 1;
		la2Sign=(la2Sign & 128) ? -1 : 1;
		lo2Sign=(lo2Sign & 128) ? -1 : 1;

		int La1 = (*buf4 / 1000) * la1Sign;
		int Lo1 = (*buf5 / 1000) * lo1Sign;
		int LaLast = (*buf6 / 1000) * la2Sign;
		int LoLast = (*buf7 / 1000) * lo2Sign;
		std::cout << "Latitude/Longitude Grid - Equidistant Cylindrical or Plate Carree projection\n";
		std::cout << "Ni - No. of points along a latitude circle:"<<*reinterpret_cast<int16_t const*>(&myLat.Ni_Lat[0]) << std::endl;
		std::cout << "Nj - No. of points along a longitude meridian:"<<*reinterpret_cast<int16_t const*>(&myLat.Nj_Lon[0]) << std::endl;
		std::cout << "La1 " << La1 << " degrees";
		if (la1Sign == 1)std::cout << " North\n";
		else std::cout << " South\n";
		std::cout << "Lo1 " << Lo1<<" degrees";
		if (lo1Sign == 1)std::cout << " East\n";
		else std::cout << " West\n";


		std::cout << "La Last " << LaLast<<" degrees";
		if (la2Sign == 1)std::cout << " North\n";
		else std::cout << " South\n";

		std::cout << "Lo Last " << LoLast<<" degrees";
		if (lo2Sign == 1)std::cout << " East\n";
		else std::cout << "West\n";
	}	
	else std::cout << "Check Table 6 on nco.ncep.noaa.gov\n";



}

int Section2::GetType()
{
	int8_t buffer = static_cast<int8_t>(m_DataRepresentationType[0]);
	return buffer;

}

int Section2::GetNoNV()
{
	int8_t buffer = static_cast<int8_t>(m_NV[0]);
	return buffer;

}

int Section2::GetOffsetLocation()
{
	uint8_t buffer = static_cast<uint8_t>(m_PVOrPLLocationOffset[0]);
	return buffer;
}

void Section2::FillCoordinates(size_t offset, std::vector<char>& I_Data,size_t size)
{
	m_PVorPL.reserve(size);
	for (int i = offset; i < offset + size; ++i)
	{
		m_PVorPL.push_back(I_Data[i]);
	}
}
