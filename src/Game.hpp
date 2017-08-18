//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_GAME_HPP
#define PACMAN_GAME_HPP


#include "Output.hpp"
#include "Input.hpp"
#include "Tilemap.hpp"

/**
 * Class representing the Pac-Man game.
 *
 * @tparam INPUT_TAG The concrete input class tag
 * @tparam OUTPUT_TAG The concrete output class tag
 * @tparam WIDTH The number of tile per line
 * @tparam HEIGHT The number of tile per row
 * @tparam TILE_SIZE The number of pixels of a tile side
 */
template<typename INPUT_TAG, typename OUTPUT_TAG, Size WIDTH, Size HEIGHT, Size TILE_SIZE>
class Game : private NonCopyable
{
    Input<INPUT_TAG> & m_input;
    Output<OUTPUT_TAG, WIDTH, HEIGHT, TILE_SIZE> & m_output;
    
    Tilemap<WIDTH, HEIGHT> m_tilemap;

public:
    /**
     * Creates a game instance reading user's inputs from @a input
     * and rendered in @a output.
     *
     * @param input The user inputs
     * @param output The render target
     */
    Game(Input<INPUT_TAG> & input, Output<OUTPUT_TAG, WIDTH, HEIGHT, TILE_SIZE> & output)
            : m_input(input), m_output(output)
    {
        m_tilemap.tiles.fill({0, 0xf});
    }
    
    /**
     * Runs the game until it gets shut down.
     */
    void run()
    {
        float deltaTime = 0;
        bool isRunning = true;
        
        while(isRunning)
        {
            m_input.update();
            
            if(m_input.template buttonPressed<Button::Off>())
                isRunning = false;
            
            m_tilemap.testScreen(1, false, false);
            
            m_output.template drawTilemap<0, 0>(m_tilemap);
            
            deltaTime = m_output.display();
        }
    }
};


#endif //PACMAN_GAME_HPP
