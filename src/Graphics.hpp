//
// Created by loris on 8/3/2017.
//

#ifndef PACMAN_GRAPHICS_HPP
#define PACMAN_GRAPHICS_HPP


#include "Matrix.hpp"
#include "Data.hpp"

#include <fstream>

/**
 * Various functions that generates graphics data from binary files.
 */

using Color = std::array<Byte, 3>;
using Palette = std::array<Color, 4>;

/**
 * Stores file content into a @a Data object.
 *
 * @tparam SIZE The size of the content
 * @param filename The path to the file
 * @return The @a Data object
 */
template<Size SIZE>
auto readFile(const std::string & filename)
{
    Data<SIZE> data;
    std::ifstream file("res/" + filename, std::ios::binary);
    file.read(reinterpret_cast<char *>(data.array.data()), SIZE);
    return data;
}

/**
 * Generates a list of colors from a binary file.
 *
 * @tparam COLOR_COUNT The number of color to read
 * @param filename The path to the file
 * @return An array containing all colors
 */
template<Size COLOR_COUNT>
auto generateColors(const std::string & filename) noexcept
{
    auto data = readFile<COLOR_COUNT>(filename);
    
    std::array<Color, COLOR_COUNT> colors;
    for(auto & color : colors)
    {
        auto value = data.template next<Byte>();
        for(Size channelIndex = 0; channelIndex < color.size(); ++channelIndex)
            color[channelIndex] = value << (3 * channelIndex) & 0b11100000;
    }
    
    return colors;
}

/**
 * Generates a list of palettes from a binary file and a color list.
 *
 * @tparam PALETTE_COUNT The number of palette to read
 * @tparam COLOR_COUNT The number of available color
 * @param filename The path to the file
 * @param colors An array containing all available colors
 * @return An array containing all palettes
 */
template<Size PALETTE_COUNT, Size COLOR_COUNT>
auto generatePalettes(const std::string & filename, const std::array<Color, COLOR_COUNT> & colors) noexcept
{
    auto data = readFile<PALETTE_COUNT * sizeof(Short)>(filename);
    
    std::array<Palette, PALETTE_COUNT> palettes;
    for(auto & palette : palettes)
    {
        auto value = data.template get<Short>();
        for(Size paletteIndex = 0; paletteIndex < palette.size(); ++paletteIndex)
        {
            auto colorIndex = static_cast<Size>(value >> (0xc - 4 * paletteIndex) & 0b1111);
            palette[paletteIndex] = colors[colorIndex];
        }
        data.template next<Short>();
    }
    
    return palettes;
}

#include <memory>

/**
 * Generates texture pixels from a binary file and a list of palettes.
 * The generated texture is made of one row per tile and one line per palette.
 * The generated texture is stored on the heap to avoid stack overflow.
 *
 * @tparam TILE_COUNT The number of tile to read
 * @tparam TILE_SIZE The number of pixels of a tile side
 * @tparam PALETTE_COUNT The number of available palette
 * @param filename The path to the file
 * @param palettes An array containing all available palettes
 * @return A pointer to a @a Matrix object containing 32 bits RGBA pixels
 */
template<Size TILE_COUNT, Size TILE_SIZE, Size PALETTE_COUNT>
auto generateTexturePixels(const std::string & filename, const std::array<Palette, PALETTE_COUNT> & palettes) noexcept
{
    constexpr Size PIXELSPERBYTE = 4;
    constexpr Size BYTEPERTILE = TILE_SIZE * TILE_SIZE / PIXELSPERBYTE;
    constexpr Size FILESIZE = TILE_COUNT * BYTEPERTILE;
    
    auto data = readFile<FILESIZE>(filename);
    
    // store texture on the heap
    auto pixelsPtr = std::make_unique<Matrix<Byte, TILE_COUNT * TILE_SIZE * 4, PALETTE_COUNT * TILE_SIZE>>();
    auto & pixels = *pixelsPtr;
    
    for(Size byteIndex = 0; byteIndex < FILESIZE; ++byteIndex)
    {
        auto value = data.template next<Byte>();
        
        for(Size pixelIndex = 0; pixelIndex < PIXELSPERBYTE; ++pixelIndex)
        {
            auto colorIndex = static_cast<Size>(value >> (6 - pixelIndex * 2) & 0b11);
            
            auto pixelNumber = byteIndex % BYTEPERTILE * PIXELSPERBYTE + pixelIndex;
            auto x = pixelNumber % TILE_SIZE + byteIndex / BYTEPERTILE * TILE_SIZE;
            
            for(Size paletteIndex = 0; paletteIndex < PALETTE_COUNT; ++paletteIndex)
            {
                auto y = pixelNumber / TILE_SIZE + paletteIndex * TILE_SIZE;
                
                auto & color = palettes[paletteIndex][colorIndex];
                for(Size channelIndex = 0; channelIndex < color.size(); ++channelIndex)
                    pixels(x * 4 + channelIndex, y) = color[channelIndex];
                
                // alpha channel
                pixels(x * 4 + color.size(), y) = 0xff;
            }
        }
    }
    
    return pixelsPtr;
}


#endif //PACMAN_GRAPHICS_HPP
