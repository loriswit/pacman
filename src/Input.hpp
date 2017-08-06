//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_INPUT_HPP
#define PACMAN_INPUT_HPP


#include <unordered_set>

#include "NonCopyable.hpp"

/**
 * Represents an arcade button.
 */
enum struct Button
{
    None,
    Left,
    Right,
    Up,
    Down,
    Start,
    Off
};

/**
 * Abstract class defining an interface for user inputs.
 */
class Input : private NonCopyable
{
    std::unordered_set<Button> m_buttons;

protected:
    /**
     * Marks a button as pressed down.
     *
     * @param button The pressed button
     */
    void addButton(Button button);
    
    /**
     * Updates the buttons state. Implementations of this function
     * should define all pressed buttons by calling @a addButton.
     */
    virtual void updateButtons() = 0;

public:
    /**
     * Returns true if a specific button is pressed down.
     *
     * @param button The tested button
     * @return @a true if the button is pressed down, @a false if not
     */
    bool buttonPressed(Button button) const;
    
    /**
     * Resets and updates buttons state.
     */
    void update();
};


#endif //PACMAN_INPUT_HPP
