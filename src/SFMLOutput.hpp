//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_SFMLOUTPUT_HPP
#define PACMAN_SFMLOUTPUT_HPP


#include "Output.hpp"
#include "Graphics.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>

/**
 * Class implementing a render target using SFML.
 *
 * @tparam WIDTH The number of tile per line
 * @tparam HEIGHT The number of tile per row
 * @tparam TILESIZE The number of pixels of a tile side
 */
template<Size WIDTH, Size HEIGHT, Size TILESIZE>
class SFMLOutput : public Output<WIDTH, HEIGHT>
{
    sf::RenderWindow & m_window;
    
    sf::VertexArray m_tilemap;
    sf::Texture m_tileTexture;
    sf::Texture m_spriteTexture;
    
    sf::Clock timer;

public:
    /**
     * Constructs an instance that displays graphics in a SFML window.
     *
     * @param window The reference to the window
     */
    SFMLOutput(sf::RenderWindow & window)
            : m_window(window)
    {
        const float FACTOR = sf::VideoMode::getDesktopMode().height / HEIGHT * 0.9f;
        const auto WINDOWWIDTH = static_cast<Size>(WIDTH * FACTOR);
        const auto WINDOWHEIGHT = static_cast<Size>(HEIGHT * FACTOR);
        
        m_window.create(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Pac-Man", sf::Style::None);
        m_window.setFramerateLimit(60);
        
        sf::View view(sf::FloatRect(0, 0, WIDTH * TILESIZE, HEIGHT * TILESIZE));
        m_window.setView(view);
        
        auto colors = generateColors<16>("colors.bin");
        auto palettes = generatePalettes<32>("palettes.bin", colors);
        
        sf::Image image;
        
        auto tilePixels = generateTexturePixels<256, TILESIZE>("tiles.bin", palettes);
        image.create(tilePixels->width() / 4, tilePixels->height(), tilePixels->array.data());
        m_tileTexture.loadFromImage(image);
        m_tileTexture.copyToImage().saveToFile("design/tiles.png");
        
        auto spritePixels = generateTexturePixels<64, TILESIZE * 2>("sprites.bin", palettes);
        image.create(spritePixels->width() / 4, spritePixels->height(), spritePixels->array.data());
        m_spriteTexture.loadFromImage(image);
        m_spriteTexture.copyToImage().saveToFile("design/sprites.png");
        
        m_tilemap.setPrimitiveType(sf::Quads);
        m_tilemap.resize(WIDTH * HEIGHT * 4);
    }
    
    void updateScene(const Scene<WIDTH, HEIGHT> & scene) noexcept override
    {
        for(Size x = 0; x < WIDTH; ++x)
            for(Size y = 0; y < HEIGHT; ++y)
            {
                const auto & tile = scene(x, y);
                
                Size index = (x + y * WIDTH) * 4;
                
                m_tilemap[index].position = sf::Vector2f(x * TILESIZE, y * TILESIZE);
                m_tilemap[index + 1].position = sf::Vector2f((x + 1) * TILESIZE, y * TILESIZE);
                m_tilemap[index + 2].position = sf::Vector2f((x + 1) * TILESIZE, (y + 1) * TILESIZE);
                m_tilemap[index + 3].position = sf::Vector2f(x * TILESIZE, (y + 1) * TILESIZE);
                
                auto number = static_cast<Size>(tile.number);
                auto palette = static_cast<Size>(tile.palette);
                
                m_tilemap[index].texCoords = sf::Vector2f(number * TILESIZE, palette * TILESIZE);
                m_tilemap[index + 1].texCoords = sf::Vector2f((number + 1) * TILESIZE, palette * TILESIZE);
                m_tilemap[index + 2].texCoords = sf::Vector2f((number + 1) * TILESIZE, (palette + 1) * TILESIZE);
                m_tilemap[index + 3].texCoords = sf::Vector2f(number * TILESIZE, (palette + 1) * TILESIZE);
            }
    }
    
    void updateSprites(const std::vector<Tile> & sprites) noexcept override
    {
    }
    
    float display() override
    {
        m_window.clear();
        m_window.draw(m_tilemap, sf::RenderStates(&m_tileTexture));
        m_window.display();
        
        return timer.restart().asSeconds();
    }
};


#endif //PACMAN_SFMLOUTPUT_HPP
