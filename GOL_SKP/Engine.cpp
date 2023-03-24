#include "Engine.h"

Engine::Engine()
{
	
}

Engine::~Engine()
{
}

Engine::Engine(int m_Rows, int m_Columns)
	:m_Row(m_Rows), m_Col(m_Columns)
{	
	m_Init = new Init(m_Rows, m_Columns);
	
}

void Engine::Start()
{
	while (true)
	{
		m_Output.Display(m_Init->GetBoard(), m_Row, m_Col);
		CalculateChanges();
		m_Init->ChangeState(m_StateToChange);
		m_StateToChange.clear();
	}
}

void Engine::CalculateChanges()
{
	
	int** bufArray = m_Init->GetBoard();

	for (int i = 0; i < m_Row; ++i)
	{
		for (int j = 0; j < m_Col; ++j)
		{
		
				int cnt = 0;
				for (int di = i-1; di <= i+1; ++di)
				{

					for (int dj = j-1; dj <=j+1; ++dj)
					{
						if (di == i && dj == j)continue;
						if (di >= 0 && dj >= 0 && di < m_Row && dj < m_Col)
						{
							if (bufArray[di][dj] == 1)++cnt;
					
							if (cnt > 3)break;
						}
					}
				}

				if (bufArray[i][j] == 0 && cnt == 3)m_StateToChange.push_back({ i,j });
				
				else if (cnt != 3 && cnt != 2 && bufArray[i][j] == 1) 	m_StateToChange.push_back({ i,j });
				


			
			
				


			
		}

	}


}
