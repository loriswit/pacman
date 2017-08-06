//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_TILE_HPP
#define PACMAN_TILE_HPP


using Byte = unsigned char;

/**
 * Class representing a tile (i.e. the association of a tile number and a color palette).
 */
struct Tile
{
    /**
     * The tile number.
     */
    Byte number;
    
    /**
     * The color palette.
     */
    Byte palette;
    
    /**
     * Constructs a tile.
     *
     * @param tileNumber The tile number
     * @param colorPalette The color palette
     */
    constexpr Tile(Byte tileNumber = 0, Byte colorPalette = 0) noexcept
            : number{tileNumber}, palette{colorPalette}
    {}
};


#endif //PACMAN_TILE_HPP
