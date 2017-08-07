//
// Created by loris on 8/4/2017.
//

#include "Game.hpp"
#include "TestScene.hpp"


Game::Game(Input & input, Output<WIDTH, HEIGHT> & output)
        : m_input(input), m_output(output)
{
    loadScene<TestScene<WIDTH, HEIGHT>>();
}

void Game::run()
{
    float deltaTime = 0;
    bool isRunning = true;
    
    while(isRunning)
    {
        m_input.update();
        
        if(m_input.buttonPressed(Button::Off))
            isRunning = false;
        
        if(m_scene->expired())
            loadScene<TestScene<WIDTH, HEIGHT>>();
        
        m_scene->update(deltaTime);
        m_output.updateScene(*m_scene);
        
        deltaTime = m_output.display();
    }
}
