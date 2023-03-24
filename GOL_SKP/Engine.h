#pragma once
#include "Init.h"
#include <vector>
#include "Output.h"
class Engine :public Init, public Output
{
private:
	Init* m_Init;
	Output m_Output;
	int m_Row, m_Col;
	Engine(const Engine& c_Engine) ;
	Engine& operator=(const Engine& c_Engine) {};
public:

	void CalculateChanges();
	Engine();
	~Engine();
	Engine(int m_Rows, int m_Columns);
	void Start();
	std::vector <std::pair<int,int>>m_StateToChange;

};