#pragma once
#include <algorithm>
#include <vector>
#include <iostream>	
void ReverseBytes(size_t I_Size, char* I_Data);

class SectionBase
{

protected:
	size_t m_Size;

public:
	SectionBase() {};
	SectionBase(const SectionBase& Sb) = delete;
	SectionBase& operator=(SectionBase& Sb) = delete;
	virtual ~SectionBase() {};
	virtual void DisplaySection()=0;
	virtual int ReadToSection(size_t offset,std::vector<char>&I_Data)=0;
	



};
