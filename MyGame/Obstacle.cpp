#include "Obstacle.h"

Obstacle::Obstacle(float i_Offset, float i_Width, float i_Height,float i_h)
	:m_Height(i_Height),m_Width(i_Width),m_Offset(i_Offset),m_h(i_h)
{
	m_Velocity = { 0.0f,0.0f };
	 m_CurrentlyColliding = false;
	 m_Position.x = m_Offset+m_Width/2;
	 m_Position.y = m_Height;
}

void Obstacle::Display(GLFWwindow* i_window)
{
	
	glRectf(m_Position.x - m_Width / 2, m_Height, m_Position.x + m_Width / 2, m_h);
}

void Obstacle::SetAll(float i_Offset, float i_Width, float i_Height)
{
	m_Height = i_Height;
	m_Width = i_Width;
	m_Offset = i_Offset;
	m_CurrentlyColliding = false;
	m_Position.x = m_Offset + m_Width / 2;
	m_Position.y = m_Height / 2;
}
