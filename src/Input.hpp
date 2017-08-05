//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_INPUT_HPP
#define PACMAN_INPUT_HPP


#include <vector>
#include "NonCopyable.hpp"

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

class Input : private NonCopyable
{
    std::vector<Button> m_buttons;

protected:
    void addButton(Button button);
    
    void resetButtons() noexcept;

public:
    bool buttonPressed(Button button) const;
    
    virtual void update() = 0;
};


#endif //PACMAN_INPUT_HPP
