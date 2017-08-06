//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_SFMLINPUT_HPP
#define PACMAN_SFMLINPUT_HPP


#include <SFML/Window/Event.hpp>

#include "Input.hpp"

/**
 * Class implementing user inputs using SFML.
 */
class SFMLInput : public Input
{
    sf::Window & m_window;
    
    /**
     * Returns the button linked to the given keyboard key.
     *
     * @param key The keyboard key
     * @return The arcade button
     */
    static Button getButton(sf::Keyboard::Key key) noexcept;

protected:
    void updateButtons() override;

public:
    /**
     * Constructs an instance that reads inputs from a specific SFML window.
     *
     * @param window The reference to the window
     */
    SFMLInput(sf::Window & window);
};


#endif //PACMAN_SFMLINPUT_HPP
