//
// Created by loris on 8/4/2017.
//

#include "Game.hpp"
#include "TestScene.hpp"


Game::Game(Input & input, Output<WIDTH, HEIGHT> & output)
        : m_input(input), m_output(output)
{
}

void Game::run()
{
    float deltaTime = 0;
    bool isRunning = true;
    
    TestScene<WIDTH, HEIGHT> scene;
    
    while(isRunning)
    {
        m_input.update();
        
        if(m_input.buttonPressed(Button::Off))
            isRunning = false;
        
        if(m_input.buttonPressed(Button::Start))
        {
            scene.next();
        }
        
        scene.update(deltaTime);
        m_output.updateScene(scene);
        
        deltaTime = m_output.display();
    }
}
