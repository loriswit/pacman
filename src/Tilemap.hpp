//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_TILEMAP_HPP
#define PACMAN_TILEMAP_HPP


#include "Matrix.hpp"
#include "Tile.hpp"
#include "Text.hpp"

/**
 * Class representing a tile matrix.
 *
 * @tparam WIDTH The number of tile per line
 * @tparam HEIGHT The number of tile per row
 */
template<Size WIDTH, Size HEIGHT>
struct Tilemap
{
    Matrix<Tile, WIDTH, HEIGHT> tiles;
    
    /**
     * Displays a text at a specific position on the tilemap.
     *
     * @param x The horizontal position of the first character
     * @param y The vertical position of the first character
     * @param text The text to display
     */
    void print(Size x, Size y, const Text & text)
    {
        for(Size i = 0; i < text.tiles().size(); ++i)
            tiles(x + i, y) = text.tiles()[i];
    }
    
    void testScreen(Size seed, bool digits, bool palette)
    {
        constexpr Byte INITIAL_VALUE = 0xf;
        constexpr Byte FRAME_MULTIPLIER = 0x7;
        constexpr Byte X_MULTIPLIER = 0x2;
        constexpr Byte Y_MULTIPLIER = 0x3;
        constexpr Byte X_FRAME_MULTIPLIER = 0x8;
        
        Byte initialValue = INITIAL_VALUE;
        initialValue += seed * FRAME_MULTIPLIER;
        
        for(Size y = 0; y < HEIGHT; ++y)
        {
            auto value = initialValue;
            value += y * Y_MULTIPLIER;
            
            for(Size x = 0; x < WIDTH; ++x)
            {
                auto finalValue = value;
                
                finalValue += x * seed * X_FRAME_MULTIPLIER;
                finalValue *= 0x10;
                finalValue += x * X_MULTIPLIER;
                
                if(palette)
                    tiles(x, y).palette = static_cast<Byte>(finalValue % 0x20);
                else
                    tiles(x, y).number = finalValue % 0x10 * 0x10;
            }
        }
    }
};


#endif //PACMAN_TILEMAP_HPP
