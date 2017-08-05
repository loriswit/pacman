//
// Created by loris on 8/4/2017.
//

#include <algorithm>
#include "Input.hpp"

void Input::addButton(Button button)
{
    m_buttons.push_back(button);
}

void Input::resetButtons() noexcept
{
    m_buttons.clear();
}

bool Input::buttonPressed(Button button) const
{
    return std::find(m_buttons.cbegin(), m_buttons.cend(), button) != m_buttons.cend();
}
