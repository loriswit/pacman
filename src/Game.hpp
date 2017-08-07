//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_GAME_HPP
#define PACMAN_GAME_HPP


#include <memory>

#include "Output.hpp"
#include "Input.hpp"
#include "Scene.hpp"

/**
 * Class representing the Pac-Man game.
 */
class Game : private NonCopyable
{
public:
    /**
     * Number of tiles per line.
     */
    constexpr static Size WIDTH = 28;
    
    /**
     * Number of tile per row.
     */
    constexpr static Size HEIGHT = 36;

private:
    Input & m_input;
    Output<WIDTH, HEIGHT> & m_output;
    
    std::unique_ptr<Scene<WIDTH, HEIGHT>> m_scene;
    
    template<typename SCENE_TYPE>
    void loadScene()
    {
        m_scene = std::make_unique<SCENE_TYPE>();
    }

public:
    /**
     * Creates a game instance reading user's inputs from @a input
     * and rendered in @a output.
     *
     * @param input The user inputs
     * @param output The render target
     */
    Game(Input & input, Output<WIDTH, HEIGHT> & output);
    
    /**
     * Runs the game until it gets shut down.
     */
    void run();
};


#endif //PACMAN_GAME_HPP
