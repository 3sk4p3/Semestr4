#pragma once
#include <fstream>
#include "Section0.h"
#include "Section1.h"
#include "Section2.h"
#include "Section4.h"
#include "Section5.h"

class Forecast

{
private:
	std::vector<char>m_Data;
	int m_Size;
	Section0 *m_Section0;
	Section1 *m_Section1;
	Section2 *m_Section2;
	Section4 *m_Section4;
	Section5 *m_Section5;
public:
	Forecast() ;
	~Forecast() {
		if (m_Section0 != nullptr)
		{
			delete m_Section0;
			delete m_Section1;
			delete m_Section2;
			delete m_Section4;
			delete m_Section5;
	}
	};
	Forecast(const Forecast& mF) = delete;
	Forecast& operator=(const Forecast& mF) = delete;
	void LoadData(const char* I_Path);
	void FillSection(size_t offset);
	friend void ReverseBytes(size_t I_Size,char* I_Data);
private:
	void SetSize();

};
