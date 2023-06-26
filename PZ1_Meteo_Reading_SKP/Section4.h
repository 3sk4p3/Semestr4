#pragma once
#include "SectionBase.h"
class Section4 :public SectionBase
{
public:
	Section4() {};
	char m_Length[3];
	char m_Flag[1];
	char m_Scale[2];
	char m_ReferenceValue[4];
	char m_NoBits[1];
	char m_Var[2];
	char m_Flags[1];
	


public:
	Section4(const Section4& S1) = delete;
	Section4& operator=(const Section4& S1) = delete;
	int ReadToSection(size_t offset, std::vector<char>& I_Data) override;
	int GetSize();
	void DisplaySection() override;
};