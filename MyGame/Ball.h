#pragma once
#include "GameObject.h"
class Ball :public GameObject
{


private:
	float m_radius;
	bool m_DoubleJump;
public:
	Ball()=delete;
	Ball(float i_radius);
	~Ball() {};
	void Display(GLFWwindow* i_window) override;
	inline const float const GetRadius(){ return m_radius; }
	inline void IsColiding(bool i_CurrentState) { m_CurrentlyColliding = i_CurrentState; }
	inline void Jumped(bool i_CurrentState) { m_DoubleJump = i_CurrentState; }

};

