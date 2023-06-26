#include "Engine.h"

Engine::Engine()
{
    
	glfwInit();
	m_Window = glfwCreateWindow(1280, 960, "Hollow Knight", NULL, NULL);
    m_Ball = new Ball(0.02f);
    m_Floor = new Obstacle(-1.0f, 2.0f, 0.01f,0.0f);
    m_Obstacles.push_back(m_Floor);
    m_StartPlatform = new Obstacle(-1.0f, 0.2f, 0.5f, 0.0f);
  /*  for (size_t i = 1; i < 6; ++i)
    {
        m_Obstacles.push_back(new Obstacle(-0.8f+i/3.0f , 0.05f, i/7.6f,0.1f));
    }*/
    m_Obstacles.push_back(new Obstacle(-0.5f, 0.05f, 1.0f/7.6f,0.01f));
    m_Obstacles.push_back(new Obstacle(-0.2f, 0.05f, 2.0f/7.6f, 0.01f));

    m_Obstacles.push_back(new Obstacle(0.0f, 0.1f, 0.1f, 0.0f));

    m_Obstacles.push_back(new Obstacle(0.02f, 0.05f, 0.55f, 0.5f));
    m_Obstacles.push_back(new Obstacle(0.14f, 0.05f, 0.9f, 0.8f));
    m_Obstacles.push_back(new Obstacle(0.3f, 0.05f, 0.6f, 0.56f));
    m_Obstacles.push_back(new Obstacle(0.6f, 0.05f, 4.0f/7.6f, 0.01f));
    m_Obstacles.push_back(new Obstacle(0.7f, 0.05f, 5.0f/7.6f, 0.01f));
    m_Obstacles.push_back(m_StartPlatform);
	glfwMakeContextCurrent(m_Window);
    
}
Engine::~Engine()
{

    for (auto& current : m_Obstacles)
    {
        
            delete current;
        
        
    }
    delete m_Ball;
    delete m_Floor;
    delete m_StartPlatform;
}

void Engine::Start()
{
    while (!glfwWindowShouldClose(m_Window))
    {
        int cnt = 0;
        //Flooor
       
        glClear(GL_COLOR_BUFFER_BIT);


        //BOX   
        float b_Radius = m_Ball->GetRadius();
        Vec2 b_CurrentBallPos = m_Ball->GetPosition();
        Vec2 b_CurrentBallX = { b_CurrentBallPos.x - b_Radius,b_CurrentBallPos.x + b_Radius };
        Vec2 b_CurrentBallY = { b_CurrentBallPos.y - b_Radius,b_CurrentBallPos.y + b_Radius };
        bool Coliding = false;
        
        for (auto& i : m_Obstacles)
        {
            Vec2 b_CurrentObstacle = i->GetPosition();
            float b_CurrentObstacleWidth = i->GetWidth()/2.0f;
            if ((b_CurrentBallX.x > (b_CurrentObstacle.x - b_CurrentObstacleWidth) &&
                b_CurrentBallX.x < (b_CurrentObstacle.x + b_CurrentObstacleWidth)) ||
                (b_CurrentBallX.y > (b_CurrentObstacle.x - b_CurrentObstacleWidth) &&
                    b_CurrentBallX.y < (b_CurrentObstacle.x + b_CurrentObstacleWidth)))
            {
                    Vec2  b_CurrentObstacleHeight = i->GetHeight();

                    if ((b_CurrentBallY.x >b_CurrentObstacleHeight.x  &&
                        b_CurrentBallY.x < b_CurrentObstacleHeight.y) ||
                        (b_CurrentBallY.y > b_CurrentObstacleHeight.x&&
                        b_CurrentBallY.y < b_CurrentObstacleHeight.y))
                            {
                                Coliding = true;
                                CollisionResolution(*m_Ball, *i);
                                
                                m_Ball->Jumped(false);   
                                if (m_Ball->GetPosition().y < b_CurrentObstacleHeight.y)
                                {

                                    m_Ball->SetVelocity({ 0.0f,0.0f });

                                    Vec2 bufOffset = i->GetOffset();
                                    if(b_CurrentBallX.y-b_CurrentObstacle.x<0.0f)  m_Ball->SetPosition({ bufOffset.x- m_Ball->GetRadius(), m_Ball->GetPosition().y });
                                    else if (b_CurrentBallX.x - b_CurrentObstacle.x > 0.0f)m_Ball->SetPosition({ bufOffset.y+ m_Ball->GetRadius(), m_Ball->GetPosition().y });
                                    
                                }
                                if (cnt == 0)
                                {

                                    m_Ball->SetPosition({ -1.0f + m_Ball->GetRadius(), 0.6f });
                                    m_Ball->SetVelocity({ 0.0f,0.0f });
                                }
                           
                            }
            }

            if(cnt!=0)glColor3f(0.0f, 255.0f, 0.0f);
            else glColor3f(0.0f,  0.0f, 255.0f);
            i->Display(m_Window);
            ++cnt;
        }
        m_Ball->IsColiding(Coliding);
        glColor3f(255.0f, 0.0f, 0.0f);
        if (m_Ball->GetPosition().x < -1.0f)
        {   
            m_Ball->SetPosition({ -1.0f + m_Ball->GetRadius(), m_Ball->GetPosition().y});
            m_Ball->SetVelocity({ 0.0f,0.0f });
            m_Ball->Jumped(false);
        }
        else if (m_Ball->GetPosition().x >1.0f)
        {
            m_Ball->SetPosition({ 1.0f - m_Ball->GetRadius(), m_Ball->GetPosition().y });
            m_Ball->SetVelocity({ 0.0f,0.0f });
            m_Ball->Jumped(false);
        }
        m_Ball->Display(m_Window);
        glColor3f(0.0f, 0.0f, 255.0f);
        m_Floor->Display(m_Window);

        glfwSwapBuffers(m_Window);
        glfwPollEvents();

    }

    glfwTerminate();
}

double Engine::Direction(GameObject& go1, GameObject& go2)
{
    Vec2 Middle1 = go1.GetPosition();
    Vec2 Middle2 = go2.GetPosition();
    double angle = atan2f(Middle2.y-Middle1.y,Middle2.x-Middle1.x);
    return angle;
}

void Engine::CollisionResolution(GameObject& go1, GameObject& go2)
{
    float Dir = Direction(go1, go2);
    Vec2 V1 = go1.GetVelocity();
    Vec2 V2 = go2.GetVelocity();
    
    float Vx = V1.x  * 0.005f* cos(Dir) - V1.y  * 0.005f  * sin(Dir);
    float Vy = V1.x  * 0.005f * sin(Dir) + V1.y * 0.005f  * cos(Dir);
    float Vx2 = V2.x * 0.005f * cos(Dir) - V2.y * 0.005f * sin(Dir);
    float Vy2 = V2.x * 0.005f * sin(Dir) + V2.y * 0.005f * cos(Dir);
    float buf = Vx;
    Vx = Vx2;
    Vx2 = buf;
    
   go1.SetVelocity({ Vx * cos(-Dir) - Vy * sin(-Dir), Vx * sin(-Dir) + Vy * cos(-Dir) });
    //go1.SetVelocity({ V1.x*0.5f,-V1.y * 0.5f });

}
