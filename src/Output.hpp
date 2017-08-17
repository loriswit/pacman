//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_OUTPUT_HPP
#define PACMAN_OUTPUT_HPP


#include <vector>

#include "NonCopyable.hpp"
#include "Tilemap.hpp"

/**
 * Abstract class defining an interface for a render target.
 *
 * @tparam TAG The concrete output class tag
 * @tparam WIDTH The number of tile per line
 * @tparam HEIGHT The number of tile per row
 * @tparam TILE_SIZE The number of pixels of a tile side
 */
template<typename TAG, Size WIDTH, Size HEIGHT, Size TILE_SIZE>
class Output : private NonCopyable
{
public:
    /**
     * Displays a tilemap at a specific position.
     *
     * @tparam X The horizontal drawing position
     * @tparam Y The vertical drawing position
     * @tparam TM_WIDTH The tilemap width
     * @tparam TM_HEIGHT The tilemap height
     * @param tilemap The tilemap to display
     */
    template<Size X, Size Y, Size TM_WIDTH, Size TM_HEIGHT>
    void drawTilemap(const Tilemap<TM_WIDTH, TM_HEIGHT> & tilemap) = delete;
    
    /**
     * Draws the sprites.
     *
     * @param sprites The list of all sprites to be displayed
     */
    void drawSprites(const std::vector<Tile> & sprites) = delete;
    
    /**
     * Displays the tilemap and the sprites.
     *
     * @return The time elapsed since last call to this function
     */
    float display() = delete;
};


#endif //PACMAN_OUTPUT_HPP
