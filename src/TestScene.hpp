//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_TESTSCENE_HPP
#define PACMAN_TESTSCENE_HPP


#include "Scene.hpp"

template<Size WIDTH, Size HEIGHT>
class TestScene : public Scene<WIDTH, HEIGHT>
{
    void testTiles()
    {
        auto index = m_index % 15;
        
        constexpr Byte palette = 0xf;
        
        for(Size x = 0; x < WIDTH; ++x)
        {
            Byte valueA = 0x60;
            valueA += index * 0x30;
            valueA += x * 0xd0;
            valueA += (x >= WIDTH / 2 ? index * 0x40 : 0);
            
            auto valueB = valueA;
            valueB += (index % 2 ? 0x80 : 0);
            
            Tile tileA(valueA, palette);
            Tile tileB(valueB, palette);
            
            this->setTile(x, 0, tileB);
            this->setTile(x, 1, tileA);
            this->setTile(x, HEIGHT - 2, tileB);
            this->setTile(x, HEIGHT - 1, tileA);
        }
        for(Size y = 2; y < HEIGHT - 2; ++y)
        {
            Byte valueA = 0x90;
            valueA += index * 0xf0;
            valueA += y * 0x30;
            valueA += (y >= HEIGHT / 2 ? index * 0xc0 : 0);
            
            auto valueB = valueA;
            valueB += (index % 2 ? 0x80 : 0);
            
            Tile tileA(valueA, palette);
            Tile tileB(valueB, palette);
            
            for(Size x = 0; x < WIDTH; ++x)
                this->setTile(x, y, x % 2 ? tileA : tileB);
        }
    }
    
    void testDigits()
    {
        constexpr Byte palette = 0xf;
        
        auto index = m_index % 15;
        
        for(Size x = 0; x < WIDTH; ++x)
        {
            Byte valueA = 0x7;
            valueA += index * 0xb;
            valueA += x * 0xd;
            
            auto valueB = valueA;
            valueB += 0x6 + index * 0x8;
            
            valueA += (x >= WIDTH / 2 ? 0x3 + index * 0x4 : 0);
            valueB += (x >= WIDTH / 2 ? 0xb + index * 0x4 : 0);
            
            auto valueC = valueA;
            valueC += 0xc;
            
            auto valueD = valueB;
            valueD += 0xc;
            
            valueA %= 0x10;
            valueB %= 0x10;
            valueC %= 0x10;
            valueD %= 0x10;
            
            this->setTile(x, 0, {valueA, palette});
            this->setTile(x, 1, {valueB, palette});
            this->setTile(x, HEIGHT - 2, {valueC, palette});
            this->setTile(x, HEIGHT - 1, {valueD, palette});
        }
        for(Size y = 2; y < HEIGHT - 2; ++y)
        {
            Byte valueA = 0xf;
            valueA += index * 0x7;
            valueA += y * 0x3;
            valueA += (y >= HEIGHT / 2 ? 0x5 + index * 0xc : 0);
            
            for(Size x = 0; x < WIDTH; ++x)
            {
                valueA %= 0x10;
                this->setTile(x, y, {valueA, palette});
                valueA += (y >= HEIGHT / 2 ? 0xa : 0x2) + index * 0x8;
            }
        }
    }
    
    void testBlank()
    {
        this->fill({0x40, 0xf});
    }
    
    Size m_index = 0;
    float time = 0;

public:
    void next() noexcept
    {
        ++m_index;
    }
    
    void update(float deltaTime) override
    {
        time += deltaTime;
        
        if(time >= 0.045)
        {
            ++m_index;
            time = 0;
        }
        if(m_index > 60)
            m_index = 0;
        
        if(m_index > 45)
            testTiles();
        
        else if(m_index > 30)
            testDigits();
        
        else
            testBlank();
    }
};


#endif //PACMAN_TESTSCENE_HPP
