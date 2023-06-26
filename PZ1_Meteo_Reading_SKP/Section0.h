#pragma once
#include "SectionBase.h"
class Section0 :public SectionBase
{
public:
	Section0() {};
	char m_Header[4];
	char m_Length[3];
	char m_Edition[1];

public:
	Section0(const Section0& S0) = delete;
	Section0& operator=(const Section0& S0) = delete;
	int ReadToSection(size_t offset,  std::vector<char>& I_Data) override;
	int GetSize();
	void DisplaySection() override;
};