#pragma once
#include <iostream>
#include <Windows.h>
class Output
{
public:
	Output();
	void Display(int **i_ToDisplay,int i_Rows,int i_Columns);

	~Output();
private:
	Output(const Output& c_Output);
	Output& operator=(const Output& c_Output);


};
