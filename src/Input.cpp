//
// Created by loris on 8/4/2017.
//

#include "Input.hpp"

void Input::addButton(Button button)
{
    m_buttons.insert(button);
}

bool Input::buttonPressed(Button button) const
{
    return m_buttons.find(button) != m_buttons.cend();
}

void Input::update()
{
    m_buttons.clear();
    updateButtons();
}
