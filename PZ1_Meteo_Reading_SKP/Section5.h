#pragma once
#include "SectionBase.h"

class Section5 :public SectionBase
{

private:
	char m_MoneyMaker[4];
public:
	Section5() {};
	
	Section5(const Section5& S5) = delete;
	Section5& operator=(const Section5& S5) = delete;
	int ReadToSection(size_t offset, std::vector<char>& I_Data) override;
	void DisplaySection() override;

};

