//
// Created by loris on 8/4/2017.
//

#ifndef PACMAN_TESTSCENE_HPP
#define PACMAN_TESTSCENE_HPP


#include "Scene.hpp"

/**
 * Class representing the test screen displayed during game startup.
 *
 * @tparam WIDTH
 * @tparam HEIGHT
 */
template<Size WIDTH, Size HEIGHT>
class TestScene : public Scene<WIDTH, HEIGHT>
{
    Size m_frame = 0;
    float time = 0;
    
    /**
     * Generates a tilemap chunk according to various parameters.
     *
     * @tparam X_POS The top left X coordinate
     * @tparam Y_POS The top left Y coordinate
     * @tparam X_SIZE The chunk width
     * @tparam Y_SIZE The chunk height
     * @tparam INITIAL_VALUE The initial value
     * @tparam FINAL_MULTIPLIER The final value multiplier (@a value *= @a multiplier)
     * @tparam FRAME_MULTIPLIER The frame multiplier (@a value + @a frame * @a multiplier)
     * @tparam X_MULTIPLIER The width multiplier (@a value + @a x * @a multiplier)
     * @tparam Y_MULTIPLIER The height multiplier (@a value + @a y * @a multiplier)
     * @tparam X_FRAME_MULTIPLIER The width frame multiplier (@a value + @a x * @a frame * @a multiplier)
     * @tparam Y_FRAME_MULTIPLIER The height frame multiplier (@a value + @a y * @a frame * @a multiplier)
     * @tparam PALETTE @a true to apply the value to the color palette, @a false to apply to the tile number
     */
    template<Size X_POS, Size Y_POS,
            Size X_SIZE, Size Y_SIZE,
            Byte INITIAL_VALUE,
            Byte FINAL_MULTIPLIER, Byte FRAME_MULTIPLIER,
            Byte X_MULTIPLIER, Byte Y_MULTIPLIER,
            Byte X_FRAME_MULTIPLIER, Byte Y_FRAME_MULTIPLIER,
            bool PALETTE = false>
    void genereateChunk() noexcept
    {
        auto frame = m_frame % 15;
        
        Byte initialValue = INITIAL_VALUE;
        initialValue += frame * FRAME_MULTIPLIER;
        
        for(Size x = X_POS; x < X_POS + X_SIZE; ++x)
        {
            auto value = initialValue;
            
            value += x * X_MULTIPLIER;
            value += x * frame * X_FRAME_MULTIPLIER;
            
            for(Size y = Y_POS; y < Y_POS + Y_SIZE; ++y)
            {
                auto finalValue = value;
                
                finalValue += y * Y_MULTIPLIER;
                finalValue += y * frame * Y_FRAME_MULTIPLIER;
                
                finalValue %= 0x10;
                finalValue *= FINAL_MULTIPLIER;
                
                if(PALETTE)
                    this->tiles(x, y).palette = static_cast<Byte>(finalValue % 0x20);
                else
                    this->tiles(x, y).number = finalValue;
            }
        }
    }
    
    /**
     * Generates a grid tilemap.
     */
    void grid() noexcept
    {
        for(Size i = 0; i < WIDTH * HEIGHT; ++i)
        {
            Byte value = 0x3c;
            value += ((i % WIDTH) % 2 ? 0 : 2);
            value += ((i / WIDTH) % 2 ? 1 : 0);
            
            this->tiles(i % WIDTH, i / WIDTH).number = value;
        }
    }

public:
    /**
     * Construct the test screen.
     */
    TestScene() noexcept
    {
        this->fill({0x40, 0xf});
    }
    
    void update(float deltaTime) override
    {
        time += deltaTime;
        
        m_frame = static_cast<Size>(time / 0.045);
//        if(time >= 0.045)
//        {
//            ++m_frame;
//            time = 0;
//        }
        
        if(m_frame < 30)
            return;
        
        else if(m_frame < 45)
        {
            genereateChunk<0, 0, WIDTH / 2, HEIGHT, 0x7, 0x1, 0xb, 0xd, 0x6, 0x0, 0x8>();
            genereateChunk<WIDTH / 2, 0, WIDTH / 2, HEIGHT, 0xa, 0x1, 0xf, 0xd, 0xe, 0x0, 0x8>();
    
            genereateChunk<0, 2, WIDTH, HEIGHT / 2 - 2, 0xf, 0x1, 0x7, 0x2, 0x3, 0x8, 0x0>();
            genereateChunk<0, HEIGHT / 2, WIDTH, HEIGHT / 2 - 2, 0x4, 0x1, 0x3, 0xa, 0x3, 0x8, 0x0>();
        }
        
        else if(m_frame < 60)
        {
            genereateChunk<0, 0, WIDTH / 2, HEIGHT, 0x6, 0x10, 0xb, 0xd, 0x0, 0x0, 0x8>();
            genereateChunk<WIDTH / 2, 0, WIDTH / 2, HEIGHT, 0x6, 0x10, 0xf, 0xd, 0x0, 0x0, 0x8>();
    
            genereateChunk<0, 2, WIDTH, HEIGHT / 2 - 2, 0x9, 0x10, 0x7, 0x0, 0x3, 0x8, 0x0>();
            genereateChunk<0, HEIGHT / 2, WIDTH, HEIGHT / 2 - 2, 0x9, 0x10, 0x3, 0x0, 0x3, 0x8, 0x0>();
        }
        
        else if(m_frame < 75)
        {
            genereateChunk<0, 0, WIDTH / 2, HEIGHT, 0x7, 0x1, 0xb, 0xd, 0x6, 0x0, 0x8, true>();
            genereateChunk<WIDTH / 2, 0, WIDTH / 2, HEIGHT, 0xa, 0x1, 0xf, 0xd, 0xe, 0x0, 0x8, true>();
    
            genereateChunk<0, 2, WIDTH, HEIGHT / 2 - 2, 0xf, 0x1, 0x7, 0x2, 0x3, 0x8, 0x0, true>();
            genereateChunk<0, HEIGHT / 2, WIDTH, HEIGHT / 2 - 2, 0x4, 0x1, 0x3, 0xa, 0x3, 0x8, 0x0, true>();
        }
        
        else if(m_frame < 90)
        {
            genereateChunk<0, 0, WIDTH / 2, HEIGHT, 0x6, 0x10, 0xb, 0xd, 0x0, 0x0, 0x8, true>();
            genereateChunk<WIDTH / 2, 0, WIDTH / 2, HEIGHT, 0x6, 0x10, 0xf, 0xd, 0x0, 0x0, 0x8, true>();
    
            genereateChunk<0, 2, WIDTH, HEIGHT / 2 - 2, 0x9, 0x10, 0x7, 0x0, 0x3, 0x8, 0x0, true>();
            genereateChunk<0, HEIGHT / 2, WIDTH, HEIGHT / 2 - 2, 0x9, 0x10, 0x3, 0x0, 0x3, 0x8, 0x0, true>();
        }
        
        else if(m_frame == 90)
            this->fill({0x40, 0xf});
        
        else
            grid();
    }
    
    bool expired() override
    {
        return m_frame > 108;
    }
};


#endif //PACMAN_TESTSCENE_HPP
