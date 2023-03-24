#include "Init.h"

Init::~Init()
{
	for (size_t i = 0; i < m_Columns; ++i)
	{
		delete[]m_Board[i];
	}
	delete[]m_Board;

}
void Init::ChangeState(std::vector<std::pair<int, int>> I_Pair)
{
	for (auto& i : I_Pair)
	{
		if (m_Board[i.first][i.second] == 0)m_Board[i.first][i.second] = 1;
		else m_Board[i.first][i.second] = 0;
	}

}
Init::Init()
:m_Columns(0), m_Rows(0)
{}
void Init::Seed()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Columns; ++j)
		{
			m_Board[i][j] = dist(mt);
		}
	}
}
Init::Init(int i_rows, int i_Columns)
	:m_Rows(i_rows), m_Columns(i_Columns) 
{
	m_Board = new int*[m_Columns];
	for (size_t i = 0; i < m_Columns; ++i)
	{
		m_Board[i] = new int[m_Rows];
	}
	Seed();
	
}
