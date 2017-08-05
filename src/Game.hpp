//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_GAME_HPP
#define PACMAN_GAME_HPP


#include "Output.hpp"
#include "Input.hpp"

class Game : private NonCopyable
{
public:
    static constexpr Size WIDTH = 28;
    static constexpr Size HEIGHT = 36;

private:
    Input & m_input;
    Output<WIDTH, HEIGHT> & m_output;
    
public:
    Game(Input & input, Output<WIDTH, HEIGHT> & output);
    
    void run();
};


#endif //PACMAN_GAME_HPP
