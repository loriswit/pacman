//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_SFMLINPUT_HPP
#define PACMAN_SFMLINPUT_HPP


#include <SFML/Window/Event.hpp>
#include "Input.hpp"

struct SFMLInput
{
};

/**
 * Class implementing user inputs using SFML.
 */
template<>
class Input<SFMLInput> : private NonCopyable
{
    sf::Window & m_window;
    std::vector<sf::Event> m_events;

public:
    /**
     * Constructs an instance that reads inputs from a specific SFML window.
     *
     * @param window The reference to the window
     */
    Input(sf::Window & window)
            : m_window(window)
    {
    }
    
    /**
     * Returns the button linked to the given keyboard key.
     *
     * @param key The keyboard key
     * @return The arcade button
     */
    static Button getButton(sf::Keyboard::Key key) noexcept
    {
        switch(key)
        {
            case sf::Keyboard::Space: return Button::Start;
            case sf::Keyboard::Left: return Button::Left;
            case sf::Keyboard::Right: return Button::Right;
            case sf::Keyboard::Up: return Button::Up;
            case sf::Keyboard::Down: return Button::Down;
            case sf::Keyboard::Escape: return Button::Off;
            default: return Button::None;
        }
    }
    
    void update()
    {
        m_events.clear();
        
        sf::Event event{};
        while(m_window.pollEvent(event))
            m_events.push_back(event);
    }
    
    template<Button BUTTON>
    bool buttonPressed() const
    {
        for(const auto & event : m_events)
            if(event.type == sf::Event::KeyPressed && getButton(event.key.code) == BUTTON)
                return true;
        
        return false;
    }
};

template<>
inline bool Input<SFMLInput>::buttonPressed<Button::Off>() const
{
    for(const auto & event : m_events)
        if(event.type == sf::Event::Closed ||
           (event.type == sf::Event::KeyPressed && getButton(event.key.code) == Button::Off))
            return true;
    
    return false;
}


#endif //PACMAN_SFMLINPUT_HPP
