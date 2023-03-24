#pragma once
#include <random>
class Init
{
private:
	int** m_Board;
	int m_Rows, m_Columns;
	Init(const Init &c_Init);
	Init &operator=(const Init& c_Init);
public:
	inline  int** GetBoard() { return m_Board; };
	inline const std::pair<int, int> GetRandC() { return { m_Rows,m_Columns }; }
	void Seed();
	Init(int i_Rows,int i_Columns);
	virtual ~Init();
	void ChangeState(std::vector<std::pair<int, int>>I_Pair);
	Init();

};