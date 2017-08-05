//
// Created by loris on 8/4/2017.
//

#include <SFML/Window/Window.hpp>
#include "SFMLInput.hpp"

SFMLInput::SFMLInput(sf::Window & window)
        : m_window(window)
{
}

Button SFMLInput::getButton(sf::Keyboard::Key key) noexcept
{
    switch(key)
    {
        case sf::Keyboard::Space: return Button::Start;
        case sf::Keyboard::Left: return Button::Left;
        case sf::Keyboard::Right: return Button::Right;
        case sf::Keyboard::Up: return Button::Up;
        case sf::Keyboard::Down: return Button::Down;
        default: return Button::None;
    }
}

void SFMLInput::update()
{
    resetButtons();
    
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            addButton(Button::Off);
        
        if(event.type == sf::Event::KeyPressed)
            addButton(getButton(event.key.code));
    }
}
