#include "Output.h"

Output::Output()
{
}

void Output::Display(int** i_ToDisplay,int i_Rows, int i_Columns)
{
	for (size_t i = 0; i < i_Rows; ++i)
	{
		for (size_t j = 0; j < i_Columns; ++j)
		{
			std::cout << i_ToDisplay[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	Sleep(5000);
	
}



Output::~Output()
{
}
