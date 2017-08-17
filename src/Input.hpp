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
 *
 * @tparam TAG The concrete input class tag
 */
template<typename TAG>
class Input : private NonCopyable
{
public:
    /**
     * Returns true if a specific button is pressed down.
     *
     * @tparam BUTTON The tested button
     * @return @a true if the button is pressed down, @a false if not
     */
    template<Button BUTTON>
    bool buttonPressed() const = delete;
    
    /**
     * Resets and updates buttons state.
     */
    void update() = delete;
};


#endif //PACMAN_INPUT_HPP
