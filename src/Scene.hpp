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

/**
 * Class representing a scene (i.e. a background tilemap).
 *
 * @tparam WIDTH The number of tile per line
 * @tparam HEIGHT The number of tile per row
 */
template<Size WIDTH, Size HEIGHT>
class Scene : private NonCopyable
{
    TileMap<WIDTH, HEIGHT> m_tiles;

protected:
    /**
     * Updates a tile in the tilemap.
     *
     * @param x The horizontal index of the tile
     * @param y The vertical index of the tile
     * @param tile The new tile
     */
    void setTile(Size x, Size y, const Tile & tile) noexcept
    {
        m_tiles(x, y) = tile;
    }
    
    /**
     * Fill the whole tilemap with a unique tile.
     *
     * @param tile The new tile
     */
    void fill(const Tile & tile) noexcept
    {
        m_tiles.array.fill(tile);
    }

public:
    /**
     * Returns a reference to a @a const tile in the tilemap.
     *
     * @param x The horizontal index of the tile
     * @param y The vertical index of the tile
     * @return The reference to the @a const tile
     */
    const Tile & operator()(Size x, Size y) const noexcept
    {
        return m_tiles(x, y);
    }
    
    /**
     * Updates the tilemap.
     *
     * @param deltaTime The time elapsed since last frame
     */
    virtual void update(float deltaTime) = 0;
};


#endif //PACMAN_TILEMAP_HPP
