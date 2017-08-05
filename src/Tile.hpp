//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_TILE_H
#define PACMAN_TILE_H


using Byte = unsigned char;

struct Tile
{
    Byte number;
    Byte palette;
    
    constexpr Tile(Byte tileNumber = 0, Byte tilePalette = 0) noexcept
            : number{tileNumber}, palette{tilePalette}
    {}
};


#endif //PACMAN_TILE_H
