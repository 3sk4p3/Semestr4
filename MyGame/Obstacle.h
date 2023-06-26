#pragma once
#include "GameObject.h"

class Obstacle :public GameObject
{
public:
	Obstacle() =delete;
	Obstacle(Obstacle& mo) = delete;
	Obstacle(float i_Offset, float i_Width, float i_Height,float i_h);
	Obstacle& operator=(const Obstacle& obs) = delete;
	void Display(GLFWwindow* i_window) override;
	void SetAll(float i_Offset, float i_Width, float i_Height);
	inline const float  GetWidth() { return m_Width; }
	inline const Vec2  GetHeight() { return {m_h,m_Height}; }
	inline const Vec2 GetOffset() { return { m_Offset,m_Offset+m_Width }; }
private:
	float m_Width;
	float m_Height;
	float m_Offset;
	float m_h;



};