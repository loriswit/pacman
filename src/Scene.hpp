//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_TILEMAP_HPP
#define PACMAN_TILEMAP_HPP


#include "NonCopyable.hpp"
#include "Matrix.hpp"
#include "Tile.hpp"

template<Size WIDTH, Size HEIGHT>
using TileMap = Matrix<Tile, WIDTH, HEIGHT>;

template<Size WIDTH, Size HEIGHT>
class Scene : private NonCopyable
{
    TileMap<WIDTH, HEIGHT> m_tiles;

protected:
    void setTile(Size x, Size y, const Tile & tile) noexcept
    {
        m_tiles(x, y) = tile;
    }
    
    void fill(const Tile & tile) noexcept
    {
        m_tiles.array.fill(tile);
    }

public:
    const Tile & operator()(Size x, Size y) const noexcept
    {
        return m_tiles(x, y);
    }
    
    virtual void update(float deltaTime) = 0;
};


#endif //PACMAN_TILEMAP_HPP
