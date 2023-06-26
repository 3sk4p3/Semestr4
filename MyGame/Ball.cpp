#include "Ball.h"

void drawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);

    float radial_factor = cosf(theta);

    float x = r;

    float y = 0;
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);

        float tx = -y;
        float ty = x;

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}
Ball::Ball(float i_radius)
	:m_radius(i_radius),m_DoubleJump(false)
{
	m_CurrentlyColliding = false;
	m_Velocity = { 0.0f,0.0f };
	m_Position.x = -1.0f+i_radius;
	m_Position.y = 0.6f ;
}

void Ball::Display(GLFWwindow* i_window)
{
	//glfwSetInputMode(i_window, GLFW_STICKY_KEYS, GLFW_TRUE);
	int stateRight = glfwGetKey(i_window, GLFW_KEY_RIGHT);
	int stateLeft = glfwGetKey(i_window, GLFW_KEY_LEFT);
	int stateSpace = glfwGetKey(i_window, GLFW_KEY_SPACE);
	int stateZ = glfwGetKey(i_window, GLFW_KEY_Z);
	if (stateRight != GLFW_RELEASE)m_Velocity.x += 0.0000005f;
	if (stateLeft != GLFW_RELEASE)m_Velocity.x -= 0.0000005f;
    if (stateSpace != GLFW_RELEASE && m_CurrentlyColliding) { 
        m_Velocity.y += 0.0005f; 
        m_Position.y += m_Velocity.y; 
    }
    if (stateZ != GLFW_RELEASE && !m_DoubleJump) {
        m_Velocity.y += 0.0008f;
        m_Position.y += m_Velocity.y;
        m_DoubleJump = true;
    }

	if (m_Position.y >m_radius/2&&!m_CurrentlyColliding)m_Velocity.y -= 0.000001f;


    m_Position.x += m_Velocity.x;
    if (m_Position.y > m_radius / 2)m_Position.y += m_Velocity.y;
    else m_Position.y =  m_radius / 2;
   
	drawCircle(m_Position.x, m_Position.y, m_radius, 100);
}


