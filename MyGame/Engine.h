#pragma once
#include "Ball.h"
#include "Obstacle.h"
#include <vector>
#include <iostream>



class Engine
{
public:
	Engine();
	Engine(Engine& eng) = delete;
	Engine& operator=(const Engine& eng) = delete;
	void Start();
	double Direction(GameObject& go1, GameObject& go2);
	void CollisionResolution(GameObject& go1, GameObject& go2);
	~Engine();
private:

	Ball* m_Ball;
	Obstacle* m_Floor;
	Obstacle* m_StartPlatform;
	std::vector<Obstacle *>m_Obstacles;
	GLFWwindow* m_Window;
};
