//
// Created by loris on 8/1/2017.
//


#include <iostream>

#include "SFMLOutput.hpp"
#include "SFMLInput.hpp"
#include "Game.hpp"

/**
 * Main entry point.
 */
int main()
{
    std::cout.sync_with_stdio(false);
    
    sf::RenderWindow window;
    
    SFMLOutput<Game::WIDTH, Game::HEIGHT, 8> output(window);
    SFMLInput input(window);
    
    Game game(input, output);
    game.run();
    
    window.close();
}
