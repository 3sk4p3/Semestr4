#pragma once
#include <GLFW/glfw3.h>
#include "cmath"

struct Vec2
{
	float x, y;
};
class GameObject
{

protected:
	Vec2 m_Position;
	Vec2 m_Velocity;
	bool m_CurrentlyColliding;
public:
	GameObject() {};
	virtual void Display(GLFWwindow* i_window) = 0;
	virtual ~GameObject() {};
	inline const Vec2 GetPosition() const { return m_Position; }
	inline const Vec2 GetVelocity() const { return m_Velocity; }
	void SetVelocity(Vec2 i_Velocity) { m_Velocity = i_Velocity; }
	void SetPosition(Vec2 i_Velocity) { m_Position.x = i_Velocity.x; m_Position.y = i_Velocity.y; }




};
