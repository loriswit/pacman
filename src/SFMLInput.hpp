//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_SFMLINPUT_HPP
#define PACMAN_SFMLINPUT_HPP

#include <SFML/Window/Event.hpp>
#include <vector>
#include "Input.hpp"

class SFMLInput : public Input
{
    sf::Window & m_window;
    
    static constexpr Button getButton(sf::Keyboard::Key key) noexcept;

public:
    SFMLInput(sf::Window & window);
    
    void update() override;
};


#endif //PACMAN_SFMLINPUT_HPP
