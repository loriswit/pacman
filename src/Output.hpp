//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_OUTPUT_HPP
#define PACMAN_OUTPUT_HPP


#include <vector>

#include "NonCopyable.hpp"
#include "Scene.hpp"

/**
 * Abstract class defining an interface for a render target.
 *
 * @tparam WIDTH The number of tile per line
 * @tparam HEIGHT The number of tile per row
 */
template<Size WIDTH, Size HEIGHT>
class Output : private NonCopyable
{
public:
    /**
     * Updates the background tilemap.
     *
     * @param scene The new scene to be displayed
     */
    virtual void updateScene(const Scene<WIDTH, HEIGHT> & scene) = 0;
    
    /**
     * Updates the sprites.
     *
     * @param sprites The list of all sprites to be displayed
     */
    virtual void updateSprites(const std::vector<Tile> & sprites) = 0;
    
    /**
     * Displays the tilemap and the sprites.
     *
     * @return The time elapsed since last call to this function
     */
    virtual float display() = 0;
};


#endif //PACMAN_OUTPUT_HPP
