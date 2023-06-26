#pragma once
#include "SectionBase.h"
struct Lat_Lon_GRID {
	char Ni_Lat[2];
	char Nj_Lon[2];
	char La1_First[3];
	char Lo1_First[3];
	char Resolution_Flag[1];
	char La2_Last[3];
	char Lo2_Last[3];
	char Di_Increment[2];
	char Regular_Lat_Lon[2];
	char Scan_Flag[1];
	char Reserved[4];
};
class Section2:public SectionBase
{
private:
	char m_Length[3];
	char m_NV[1];
	char m_PVOrPLLocationOffset[1];//if m_Nv!=0 to m_Pv offset, if this !=-1 Pl offset else brak obu.
	char m_DataRepresentationType[1];//MERCATOR AND LAMBERT =32->1,3,13+, SPACE VIEW- 90
	std::vector<char>m_GridDescription;
	std::vector<char>m_PVorPL;//if PV len=4*m_NV,PL=4*NV+PV

public:
	int ReadToSection(size_t offset, std::vector<char>& I_Data) override;
	int GetSize();
	void DisplaySection() override;
	int GetType();
	int GetNoNV();
	int GetOffsetLocation();
	void FillCoordinates(size_t offset, std::vector<char>& I_Data,size_t size);
};