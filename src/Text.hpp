//
// Created by loris on 8/8/2017.
//

#ifndef PACMAN_TEXT_HPP
#define PACMAN_TEXT_HPP


#include <vector>
#include <string>

#include "Tile.hpp"

using Size = std::size_t;

/**
 * Class representing a displayable text.
 */
struct Text
{
    /**
     * Represents the text color.
     */
    enum struct Color
    {
        Red = 1,
        Pink = 3,
        Cyan = 5,
        Orange = 7,
        Yellow = 9,
        Skin = 14,
        White = 15,
        Blue = 16
    };
    
    /**
     * Constructs a displayable text.
     *
     * @param body The text content
     * @param color The color of the text
     */
    Text(const std::string & body, Color color = Color::White)
    {
        for(auto character : body)
        {
            auto number = toTileNumber(character);
            auto palette = static_cast<Byte>(color);
            m_tiles.push_back({number, palette});
        }
    }
    
    /**
     * Returns the text tiles.
     *
     * @return An array containing all tiles.
     */
    const auto & tiles() const
    {
        return m_tiles;
    }

private:
    std::vector<Tile> m_tiles;
    
    /**
     * Converts a character into a tile number.
     *
     * @param character
     * @return
     */
    Byte toTileNumber(char character)
    {
        switch(character)
        {
            case '.': return 0x25;
            case '/': return 0x3a;
            case '-': return 0x3b;
            case ' ': return 0x40;
            case '!': return 0x5b;
            default:return static_cast<Byte>(std::toupper(character));
        }
    }
};


#endif //PACMAN_TEXT_HPP
